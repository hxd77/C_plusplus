#include<iostream>
using namespace std;
class Clock{        //时钟类定义
public:
    Clock(int hout=0,int minute=0,int second=0);
    void showTime()const;
    Clock&operator++();     //前置单目运算符重载
    Clock&operator++(int);  //后置单目运算符重载
private:
    int hour,minute,second;
};

Clock::Clock(int hour/*=0*/,int minute/*=0*/,int second/*=0*/)
{
    if(0<=hour&&hour<24&&0<=minute&&minute<60&&0<=second&&second<60)
    {
        this->hour=hour;
        this->minute=minute;
        this->second=second;
    }
    else
    {
        cout<<"Time error!"<<endl;
    }
}

void Clock::showTime()const{    //显示时间函数
    cout<<hour<<":"<<minute<<":"<<second<<endl;
}

Clock & Clock::operator++()     //前置单目运算符重载函数
{
    second++;
    if(second>=60)
    {
        second-=60;
        minute++;
        if(minute>=60)
        {
            minute-=60;
            hour=(hour+1)%24;
        }
    }
    return *this;
}

