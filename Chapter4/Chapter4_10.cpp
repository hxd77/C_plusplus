//exp4_10:个人银行账户管理程序
#include<iostream>
#include<cmath>
using namespace std;
class SavingAccount{        //储蓄账户类
private:
    int id;                 //账号
    double balance;         //余额
    double rate;            //存款的年利率
    int lastDate;          //上次变更余额的时期
    double accumulation;    //余额按日累加之和
    //记录一笔账，date为日期，amount为金额，desc为说明
    void record(int date,double amount);
    //获得到指定日期为止的存款金额按日累积值
    double accumulate(int date)const   //常成员函数
    {
        return accumulation+balance*(date-lastDate);
    }
public:
    //构造函数
    SavingAccount(int date,int id,double rate);
    int getId(){return id;}
    double getBalance(){return balance;}
    double getRate(){return rate;}
    void deposit(int date,double amount);       //存入现金
    void withdraw(int date,double amount);      //取出现金
    //结算利息，每年1月1日调用一次该函数
    void settle(int date);
    //显示账户信息
    void show();
};
//SavingAccount类相关成员函数的实现
SavingAccount::SavingAccount(int date,int id,double rate):id(id),balance(0),rate(rate),lastDate(date),accumulation(0)
{
    cout<<date<<"\t#"<<id<<" is created"<<endl;
}
void SavingAccount::record(int date,double amount)
{
    accumulation=accumulate(date);
    lastDate=date;
    amount=floor(amount*100+0.5)/100;//floor高斯函数，向下取整，得到一个不大于一个数的最大整数,保留小数点后两位
    balance+=amount;
    cout<<date<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<endl;
}
void SavingAccount::deposit(int date,double amount)
{
    record(date,amount);
}
void SavingAccount::withdraw(int date,double amount)
{
    if(amount>balance)
    {
        cout<<"Error: not enough money"<<endl;
    }
    else
    {
        record(date,-amount);
    }
}
void SavingAccount::settle(int date)
{
    double interest=accumulate(date)*rate/365;      //计算年息
    if(interest!=0)
    {
        record(date,interest);
    }
    accumulation=0;         
}
void SavingAccount::show()
{
    cout<<"#"<<id<<"\tBalance: "<<balance;
}
int main()
{
    //建立几个账户
    SavingAccount sa0(1,21325302,0.015);
    SavingAccount sa1(1,58320212,0.015);
    //几笔账目
    sa0.deposit(5,5000);
    sa1.deposit(25,10000);
    sa0.deposit(45,5500);
    sa1.withdraw(60,4000);
    //开户第90天到了银行的计息日，结算所有账户的年息
    sa0.settle(90);
    sa1.settle(90);
    //输出各个账户信息
    sa0.show();cout<<endl;
    sa1.show();cout<<endl;
    return 0;
}