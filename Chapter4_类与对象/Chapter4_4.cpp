//exp4_4:类的组合，线段(Line)类
#include<iostream>
#include<cmath>
using namespace std;

class Point{        //Point类的定义
public:
    Point(int xx=0,int yy=0)    //默认参数构造函数
    {
        x=xx;
        y=yy;
    }
    Point (Point &p);           //复制构造函数
    int getX(){return x;}
    int getY(){return y;}

private:
    int x,y;
};
Point::Point(Point &p)          //复制构造函数实现
{
    x=p.x;
    y=p.y;
    cout<<"Calling the copy constructor of Point"<<endl;
}

//类的组合
class Line{                     //Line类的定义
public:
    Line(Point xp1,Point xp2);
    Line(Line &l);              //Line类的复制构造函数
    double getLen(){return len;}

private:
    Point p1,p2;                //私有数据成员
    double len;
};

//组合Line类的构造函数
Line::Line(Point xp1,Point xp2):p1(xp1),p2(xp2)//列表初始化赋值
{
    cout<<"Calling the constructor of Line"<<endl;
    double x=static_cast<double> (p1.getX()-p2.getX());
    double y=static_cast<double> (p1.getY()-p2.getY());
    len=sqrt(x*x+y*y);
}

//组合Line的复制构造函数
Line::Line(Line &l):p1(l.p1),p2(l.p2)
{
    cout<<"Calling the copy constructor of Line"<<endl;
    len=l.getLen();
}

//主函数
int main()
{
    Point myp1(1,1),myp2(4,5);      //建立Point类的对象
    Line line(myp1,myp2);           //建立Line类的对象
    Line line2(line);               //利用复制构造函数建立一个新对象
    cout<<"The length of the line is: ";
    cout<<line.getLen()<<endl;
    cout<<"The length of the line2 is: ";
    cout<<line2.getLen()<<endl;
    return 0;
}