//Point.cpp
#include<iostream>
#include "Point.h"
using namespace std;

Point::Point()      //默认构造函数
{
    x=y=0;
    cout<<"Default Constructor called."<<endl;
}

Point::Point(int x,int y):x(x),y(y)     //构造函数
{
    cout<<"Constructor called."<<endl;
}

Point::~Point()                         //析构函数
{
    cout<<"Destructor called."<<endl;
}

void Point::move(int newX,int newY)
{
    cout<<"Moving the point to ("<<newX<<", "<<newY<<")"<<endl;
    x=newX;
    y=newY;
}
