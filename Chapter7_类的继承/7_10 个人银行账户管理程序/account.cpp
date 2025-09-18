#include<iostream>
#include"account.h"
#include<cmath>
using namespace std;
double Account::total=0;

//Account类的实现
Account::Account(const Date&date,const string &id):id(id),balance(0)
{
    date.show();cout<<"\t#"<<id<<" created"<<endl;//date.show()输出当前日期
}

void Account::record(const Date&date,double amount,const string&desc)
{
    amount=floor(amount*100+0.5)/100;   //floor表示向下取整保留小数点后两位
    balance+=amount;total+=amount;
    date.show();    //输出当前日期
    cout<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<"\t"<<desc<<endl;
}

void Account::show()const{cout<<id<<"\tBalance:"<<balance<<endl;}
void Account::error(const string&msg)const{
    cout<<"Error(#"<<id<<"): "<<msg<<endl;
}

//SavingsAccount类相关成员函数的实现
SavingsAccount::SavingsAccount(const Date&date,const string&id,double rate):Account(date,id),rate(rate),acc(date,0) {}//前面是对基类构造，后面是对成员对象rate和acc构造
void SavingsAccount::deposit(const Date&date,double amount,const string&desc)
{
    record(date,amount,desc);//记录一笔账
    acc.change(date,getBalance()); //在date改变value为余额
}
void SavingsAccount::withdraw(const Date&date,double amount,const string&desc)
{
    if(amount>getBalance())//如果取款金额大于存款
    {
        error("not enough money");
    }
    else
    {
        record(date,-amount,desc);//record中就会更改balance余额
        acc.change(date,getBalance());
    }
}
void SavingsAccount::settle(const Date&date)
{
    double interest=acc.getSum(date)*rate/date.distance(Date(date.getYear()-1,1,1));//rate是年利率
    if(interest!=0)record(date,interest,"interest");
    acc.reset(date,getBalance());
}

//CreditAccount类相关成员函数的实现
CreditAccount::CreditAccount(const Date&date,const string&id,double credit,double rate,double fee):Account(date,id),credit(credit),rate(rate),fee(fee),acc(date,0)
{}
void CreditAccount::deposit(const Date&date,double amount,const string&desc)
{
    record(date,amount,desc);
    acc.change(date,getDebt());
}
void CreditAccount::withdraw(const Date&date,double amount,const string&desc)
{
    if(amount-getBalance()>credit)
    {
        error("not enough money");
    }
    else
    {
        record(date,-amount,desc);
        acc.change(date,getDebt());
    }
}
void CreditAccount::settle(const Date&date)
{
    double interest=acc.getSum(date)*rate;//信用账户的rate是日利率
    if(interest!=0)record(date,interest,"interest");
    if(date.getMonth()==1)
    {
        record(date,-fee,"annual fee"); //结算年费
    }
    acc.reset(date,getDebt());
}
void CreditAccount::show()const{
    Account::show();
    cout<<"\tAvailable credit: "<<getAvailableCredit();
}