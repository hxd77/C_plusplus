#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include"date.h"
#include<string>
using namespace std;
class SavingsAccount{        //�����˻���
private:
    string id;              //�˺�
    double balance;         //���
    double rate;            //����������
    Date lastDate;          //�ϴα����������
    double accumulation;    //�����ۼ�֮��
    static double total;    //
    //��¼һ���ˣ�dateΪ���ڣ�amountΪ��descΪ˵��
    void record(const Date &date,double amount,const string &desc);
    //���������Ϣ
    void error(const string&msg)const;
    //��õ�ָ������Ϊֹ�Ĵ������ۻ�ֵ
    double accumulate(const Date&date)const
    {
        return accumulation+balance*date.distance(lastDate);
    }
public:
    //���캯��
    SavingsAccount(const Date &date,const string &id,double rate);
    const string& getId() const{return id;}
    double getBalance() const{return balance;}
    double getRate() const{return rate;}
    static double getTotal() {return total;}
    //�����ֽ�
    void deposit(const Date&date,double amount,const string & desc);
    //ȡ���ֽ�
    void withdraw(const Date&date,double amount,const string&desc);
    //������Ϣ,ÿ��1��1�յ���һ�κ���
    void settle(const Date&date);
    //��ʾ�˻���Ϣ
    void show() const;
};
#endif