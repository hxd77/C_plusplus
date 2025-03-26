//Point.h
#ifndef _POINT_H
#define _POINT_H

class Point{
public:                 //外部接口
    Point();            //默认构造函数
    Point(int x,int y); //有形参构造函数
    ~Point();           //析构函数
    void move(int newX,int newY);
    int getX() const {return x;}
    int getY() const {return y;}
    static void showCount();//静态函数成员
private:

    int x,y;
};
#endif //Point.h
