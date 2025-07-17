#include<iostream>
using namespace std;
class Circle{
public:
    Circle(float r):radius(r){}
    ~Circle(){}
    float getArea() const {return 3.14*radius*radius;}
private:
    float radius;
};

int main()
{
    float radius;
    cout<<"请输入圆的半径: ";
    cin>>radius;
    Circle c(radius);
    cout<<"半径为"<<radius<<"的圆的面积为: "<<c.getArea()<<endl;
    return 0;
}