//文件3，主函数
#include"Point.h"
#include<iostream>
using namespace std;

int main()
{
    Point a(4,5);       //定义对象a，其构造函数会使count加1
    cout<<"Point A: "<<a.getX()<<","<<a.gety()<<endl;
    Point::showCount(); //显示当前对象个数
    Point b(a);         //定义对象b，其构造函数会使count加1
    cout<<"Point B: "<<b.getX()<<","<<b.gety()<<endl;
    Point::showCount(); //显示当前对象个数
    return 0;
    
}