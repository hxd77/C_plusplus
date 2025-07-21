//Point类的实现
#include"Point.h"
#include<iostream>
#include<cmath>
using namespace std;

//直线线性拟合，points为各点，nPoint为点数
float lineFit(const Point points[], int nPoint)
{
    float avgX=0,avgY=0;
    float lxx=0,lyy=0,lxy=0;    //计算x、y的平均值
    for(int i=0;i<nPoint;i++)
    {
        avgX+=points[i].getX()/nPoint; //常对象调用常成员函数
        avgY+=points[i].getY()/nPoint;
    }
    for(int i=0;i<nPoint;i++)       //计算出Lxx、Lyy和Lxy
    {
        lxx+=(points[i].getX()-avgX)*(points[i].getX()-avgX);
        lxy+=(points[i].getX()-avgX)*(points[i].getY()-avgY);
        lyy+=(points[i].getY()-avgY)*(points[i].getY()-avgY);
    }
    cout<<"This line can be fitted by y=ax+b."<<endl;
    cout<<"a="<<lxy/lxx<<endl;              //输出回归系数a
    cout<<"b="<<avgY-lxy*avgX/lxx<<endl;    //输出回归系数b
    return static_cast<float>(lxy/sqrt(lxx*lyy)); //返回相关系数r
}

int main()
{
    Point p[10]={
        Point(6,10), Point(14,20), Point(26,30),
        Point(33,40), Point(46,50), Point(54,60),
        Point(67,70), Point(75,80), Point(84,90),
        Point(100,100)
    };  //初始化数据点
    float r=lineFit(p,10); //调用线性拟合函数
    cout<<"Line coefficient r="<<r<<endl; //输出相关系数r
    return 0;
}