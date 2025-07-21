//文件2，类的实现
#include "Point.h"
#include<iostream>
using namespace std;

int Point::count=0;  //静态数据成员的定义
Point::Point(const Point&p):x(p.x),y(p.y){count++;}
void Point::showCount()
{
    cout<<"Objects count = "<<count<<endl;
}
