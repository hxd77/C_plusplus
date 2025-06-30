//通过指针访问类的静态函数成员
#include<iostream>
using namespace std;
class Point{
public:
    Point(int x=0,int y=0):x(x),y(y){
        count++;
    }
    Point (const Point &p):x(p.x),y(p.y)
    {
        count++;
    }
    ~Point(){count--;}
    int getX()const{return x;}
    int getY()const {return y;}
    static void showCount()
    {
        cout<<"Object count="<<count<<endl;
    }
private:
    static int count;
    int x,y;
};

int Point::count=0;
int main()
{
    void (*funcPtr)() = Point::showCount;        //定义一个指向函数的指针，因为指向类的静态成员函数，因此可以用普通的函数指针
    Point a(4,5);
    cout<<"Point A: "<<a.getX()<<", "<<a.getY();
    funcPtr();                                  //输出对象个数，直接通过指针访问静态函数成员

    Point b(a);
    cout<<"Point B: "<<b.getX()<<", "<<b.getY();
    funcPtr();
    return 0;
}