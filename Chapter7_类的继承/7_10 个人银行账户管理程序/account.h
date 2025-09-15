#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include"date.h"
#include"accumulator.h"
#include<string>
using namespace std;
class Account{      //账户类
private:
    string  id; //账号
    double balance; //余额
    static double total;    //所有账户的总金额
protected:
    //供派生类调用的构造函数，id为账户
    Account(const Date&date,double amount,const string &desc);
    //报告错误信息
    void error(const string &msg) const;
public:
    const string &getId()const{return id;}
    double getBalance()const{return balance;}
    static double getTotal(){return total;}
    //显示账户信息
    void show()const;
};
class SavingsAccount:public Account{    //储蓄账户类
private:
    Accumulator acc;        //辅助计算利息的累加群
    double rate;            //存款的年利率
public:
    //构造函数
    SavingsAccount(const Date&date,const string&id,double rate);
    double getRate()const{return rate;}
    //存入现金
    void deposit(const Date&date,double amount,const string&desc);
    //取出现金
    void settle(const Date&date,double amount,const string&desc);
    void settle(const Date&date);               //结算利息，每年1月日调用一次该函数
};
class CreditAccount:public Account{     //信用账户类
    

}
#endif