#include"account.h"
#include<iostream>
#include<cmath>  //包含数学函数库
using namespace std;
//类成员函数实现文件

double SavingsAccount::total = 0;//静态成员变量初始化
//SavingsAcount类相关函数实现
SavingsAccount::SavingsAccount(int date,int id,double rate)
    :id(id),balance(0),rate(rate),lastDate(0),accumulation(0)
{
    cout<<date<<"\t#"<<id<<" is created"<<endl;
}
//记录一笔存账
void SavingsAccount::record(int date,double amount)
{
    accumulation=accumulate(date);
    lastDate=date;  //更新上次变更余额的日期
    amount=floor(amount*100+0.5)/100;  //保留两位小数
    balance+=amount;  //更新余额
    total+=amount;   //所有账户总金额
    cout<<date<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<endl;
}

void SavingsAccount::deposit (int date,double amount) 
{
    record(date,amount);  //记录存款
}

void SavingsAccount::withdraw(int date,double amount)
{
    if(amount>getBalance())  //如果余额不足
    {
        cout<<date<<"Error: not enough money"<<endl;
    }
    else
    {
        record(date,-amount);  //取款金额为负数
    }
}

void SavingsAccount::settle(int date)
{
    double interest = accumulate(date)*rate/365;  //计算利息
    if(interest!=0)
    {   
        record(date,interest);  //记录利息
    }
    accumulation = 0;  //0
}
void SavingsAccount::show() const //常变量成员函数
{
    cout<<"#"<<id<<"\tBalance: "<<balance;
}