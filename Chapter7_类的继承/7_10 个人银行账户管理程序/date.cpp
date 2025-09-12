//date.cpp
#include<iostream>
#include"date.h"
#include<cstdlib>
using namespace std;
namespace{      //namespace使下面的定义只在当前文件中有效
    //存储平年中的某个月1日之前有多少天，为便于getMaxDay函数的实现，该数组多出一项
    const int DAYS_BEFORE_MONTH[]={0,31,59,90,120,151,181,212,243,273,304,334,365};
}

Date::Date(int year,int month,int day):year(year),month(month),day(day){
    if(day<0||getMaxDay())
    {

    }
}