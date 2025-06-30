#include"account.h"
#include<iostream>
#include<cmath>  //������ѧ������
using namespace std;
//���Ա����ʵ���ļ�

double SavingsAccount::total = 0;//��̬��Ա������ʼ��
//SavingsAcount����غ���ʵ��
SavingsAccount::SavingsAccount(int date,int id,double rate)
    :id(id),balance(0),rate(rate),lastDate(0),accumulation(0)
{
    cout<<date<<"\t#"<<id<<" is created"<<endl;
}
//��¼һ�ʴ���
void SavingsAccount::record(int date,double amount)
{
    accumulation=accumulate(date);
    lastDate=date;  //�����ϴα����������
    amount=floor(amount*100+0.5)/100;  //������λС��
    balance+=amount;  //�������
    total+=amount;   //�����˻��ܽ��
    cout<<date<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<endl;
}

void SavingsAccount::deposit (int date,double amount) 
{
    record(date,amount);  //��¼���
}

void SavingsAccount::withdraw(int date,double amount)
{
    if(amount>getBalance())  //�������
    {
        cout<<date<<"Error: not enough money"<<endl;
    }
    else
    {
        record(date,-amount);  //ȡ����Ϊ����
    }
}

void SavingsAccount::settle(int date)
{
    double interest = accumulate(date)*rate/365;  //������Ϣ
    if(interest!=0)
    {   
        record(date,interest);  //��¼��Ϣ
    }
    accumulation = 0;  //0
}
void SavingsAccount::show() const //��������Ա����
{
    cout<<"#"<<id<<"\tBalance: "<<balance;
}