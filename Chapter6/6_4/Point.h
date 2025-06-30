//Point.h
#ifndef _POINT_H
#define _POINT_H

class Point{
private:
    float x;
    float y;
public:
    Point(float x=0,float y=0):x(x),y(y){}
    float getX() const {return x;}  //常成员函数
    float getY() const {return y;}
};
#endif