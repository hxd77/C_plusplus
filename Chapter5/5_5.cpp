//exp5_5:具有静态数据、函数成员的Point类
#include<iostream>
using namespace std;
class Point{
public:
    Point(int x=0,int y=0):x(x),y(y){
        count++;
    }
    //在构造函数中对count累加，所有对象共同维护同一个count
    Point(Point &p)//复制构造函数
    {
        x=p.x;
        y=p.y;
        count++;
    };    
    ~Point(){count--;}//析构函数
    int getX(){return x;}
    int getY(){return y;}

    static void showCount(){        //静态函数成员
        cout<<" Object count="<<count<<endl;
    }
private:
    int x,y;
    static int count;
};

int Point::count=0;         //静态数据成员声明，用于记录点的个数

int main()
{
    Point a(4,5);             //定义对象a，其构造函数会使count+1
    cout<<"Point A: "<<a.getX()<<", "<<a.getY();
    Point::showCount();     //输出对象个数

    Point b(a);             //定义对象b，其构造函数会使count+1
    cout<<"Point B: "<<b.getX()<<", "<<b.getY();
    Point::showCount();     //输出对象个数
}