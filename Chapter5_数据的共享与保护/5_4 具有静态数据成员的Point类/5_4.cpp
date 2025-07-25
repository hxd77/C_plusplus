//exp5_4:具有静态数据成员的Point类
#include<iostream>
using namespace std;
class Point{        //Point类定义
public:             //外部接口
    Point(int x=0,int y=0):x(x),y(y){
        //在构造函数中对count累加，所有对象共同维护同一个count
        count++;
    }      //构造函数
    
    Point(Point &p)         //复制构造函数
    {
        x=p.x;
        y=p.y; 
        count++;
    }
    ~Point(){count--;}              //析构函数不接受任何参数
    int getX(){return x;}
    int getY(){return y;}

    void showCount(){               //输出静态数据成员
        cout<<" Object count="<<count<<endl;
    }
private:
    int x,y;
    static int count;               //静态数据成员声明，用于记录点的个数
    constexpr static int origin=0;  //常量静态成员类内初始化
};

int Point::count=0;         //静态数据成员定义和初始化，使用类名限定
constexpr int Point::origin;    //类外定义常量静态成员，但不可二次初始化
int main()
{
    Point a(4,5);
    cout<<"Point A: "<<a.getX()<<", "<<a.getY();
    a.showCount();          //输出对象个数

    Point b(a);             //定义对象b，其构造函数会使count+1
    cout<<"Point B: "<<b.getX()<<", "<<b.getY();
    b.showCount();          //输出对象个数

    return 0;
}