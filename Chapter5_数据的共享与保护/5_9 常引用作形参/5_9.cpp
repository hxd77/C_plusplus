//常引用作形参
#include<iostream>
#include<cmath>
using namespace std;

class Point{
public:
    Point(int x=0,int y=0):x(x),y(y){}
    int getX(){return x;}
    int gety(){return y;}
    friend float dist(const Point &p1,const Point &p2);
private:    //私有数据成员
    int x,y;
};

float dist(const Point &p1,const Point &p2)
{
    double x=p1.x-p2.x;
    double y=p1.y-p2.y;
    return static_cast<float>(sqrt(x*x+y*y));
}
int main()
{
    const Point myp1(3,4),myp2(4,5);
    cout<<"The distance is : ";
    cout<<dist(myp1,myp2)<<endl;
    return 0;
}