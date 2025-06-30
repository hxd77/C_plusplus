#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
class SavingsAccount{
private:
    int id;          //账户ID
    double balance;  //账户余额
    double rate;      //利率
    int lastDate;   //上次变更余额的日期
    double accumulation;    //余额按日累加之和
    static double total;    //所有账户的总金额
    //记录一笔账，date为日期，amount为金额，desc为说明
    void record(int date,double amount);
    //获得到指定日期为止的存款金额按日累积值
    double accumulate(int date) const{    //常成员函数
        return accumulation+balance*(date-lastDate);
    }
public:
    //构造函数,id为账户ID，balance为余额，rate为利率
    //常成员函数，只能调用常对象
    SavingsAccount(int date, int id,double rate);
    int getId() const{return id;}  //获取账户ID
    int getBalance() const{return balance;}  //获取账户余额
    double getRate() const{return rate;}  //获取账户利率
    //显示账户信息
    void show() const;
    static double getTotal() {return total;}  //获取所有账户的总金额 静态成员函数，拥有整个类
    void deposit(int date,double amount);  //存入现金
    void withdraw(int date,double amount); //取出现金
    //结算利息,每年1月1日调用一次该函数
    void settle(int date);
};
#endif // __ACCOUNT_H__