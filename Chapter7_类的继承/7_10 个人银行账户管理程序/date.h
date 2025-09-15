//date.h
#ifndef __DATE__H__
#define __DATE__H__
class Date{
private:
    int year;   //年
    int month;  //月
    int day;    //日
    int totalDays;  //该日期是从公元元年1月1日开始的第几天
public:
    Date(int year,int month,int day);   //用年月日构造日期
    int getYear() const {return year;} //常成员函数，返回年
    int getMonth() const {return month;}    //返回月
    int getDay() const {return day;}   //返回日
    int getMaxDay() const {};   //判断当月有多少天
    bool isLeapYear() const {   //判断当年是否为闰年
        return year%4==0&&year%100!=0||year%400==0;
    }
    void show() const ;     //输出当前日期
    //计算两个日期之间相差多少天
    int distance(const Date&date) const
    {
        return totalDays-date.totalDays;
    }
};
#endif