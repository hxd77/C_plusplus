//通过指针访问类的静态数据成员
#include<iostream>
using namespace std;
class Point{
public:
    Point(int x=0,int y=0):x(x),y(y){
        count++;
    }
    Point(const Point&p):x(p.x),y(p.y){     //复制构造函数，还使用了常引用
        count++;
    }                   
    ~Point(){count--;}
    int getX() const {return x;}
    int getY() const {return y;}
    static int count;       //静态数据成员声明，用于记录点的个数

private:
    int x,y;
};

int Point::count=0;             //静态数据成员定义和初始化，使用类名限定

int main()
{
    int *ptr=&Point::count;     //定义一个int型指针，指向类的静态成员
    Point a(4,5);
    cout<<"Point A: "<<a.getX()<<", "<<a.getY();
    cout<<"Object count="<<*ptr<<endl;      //直接通过指针访问静态数据成员

    Point b(a);
    cout<<"Point B: "<<b.getX()<<", "<<b.getY();
    cout<<"Object count="<<*ptr<<endl;
    return 0;
}