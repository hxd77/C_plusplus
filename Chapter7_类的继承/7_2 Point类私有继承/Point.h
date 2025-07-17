#ifndef _POINT_H
#define _POINT_H
#include<iostream>
using namespace std;
class Point{
public:
    void initPoint(float x=0,float y=0){this->x=x;this->y=y;}
    void move(float offX,float offY){x+=offX;y+=offY;}
    float getX()const{return x;}
    float getY()const{return y;}
private:
    float x,y;
};
#endif