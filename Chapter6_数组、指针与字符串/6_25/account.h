#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include"date.h"
#include<string>
using namespace std;
class SavingsAccount{        //储蓄账户类
private:
    string id;              //账号
    double balance;         //余额
    double rate;            //存款的年利率
    Date lastDate;          //上次变更余额的日期
    double accumulation;    //余额按日累加之和
    static double total;    //
    //记录一笔账，date为日期，amount为金额，desc为说明
    void record(const Date &date,double amount,const string &desc);
    //报告错误信息
    void error(const string&msg)const;
    //获得到指定日期为止的存款金额按日累积值
    double accumulate(const Date&date)const
    {
        return accumulation+balance*date.distance(lastDate);
    }
public:
    //构造函数
    SavingsAccount(const Date &date,const string &id,double rate);
    const string& getId() const{return id;}
    double getBalance() const{return balance;}
    double getRate() const{return rate;}
    static double getTotal() {return total;}
    //存入现金
    void deposit(const Date&date,double amount,const string & desc);
    //取出现金
    void withdraw(const Date&date,double amount,const string&desc);
    //结算利息,每年1月1日调用一次函数
    void settle(const Date&date);
    //显示账户信息
    void show() const;
};
#endif