#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include "Point.h"

class Rectangle:public Point{   //派生类定义部分
public:                         //新增共有函数成员
    void initRectangle(float x,float y,float w,float h)
    {
        initPoint(x,y);         //调用基类公有成员函数
        //派生类的成员函数及对象可以访问到基类的公有成员
        this->w=w;
        this->h=h;
    }
    float getH()const {return h;}
    float getW()const {return w;}
private:                        //新增私有数据成员
    float w,h;
};
#endif