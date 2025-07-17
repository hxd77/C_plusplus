#include<iostream>
#include"Point.h"
#include<cmath>
#include"Rectangle.h"

using namespace std;
int main()
{
    Rectangle rect;         //定义Rectangle类的对象
    rect.initRectangle(2,3,20,10);  //设置矩形的数据
    rect.move(3,2);             //移动矩形位置
    cout<<"The data of rect(X,Y,W,H): "<<endl;
    cout<<rect.getX()<<","<<rect.getY()<<","<<rect.getW()<<","<<rect.getH()<<endl;
    return 0;
}