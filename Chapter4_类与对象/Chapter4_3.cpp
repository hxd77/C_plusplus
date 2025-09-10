//exp4_3:游泳池改造预算
#include<iostream>
using namespace std;

const float PI=3.141593;
const float FENCE_PRICE=35;         //栅栏的单价
const float CONCRETE_PRICE=20;      //过道水泥单价

class Circle{                       //圆类
public:                             //外部接口
    Circle(float r);                //构造函数
    float circumference();          //计算圆的周长
    float area();                   //计算圆的面积
private:
    float radius;                   //圆的半径
};

//类成员函数的实现

//构造函数初始化成员radius
Circle::Circle(float r)
{
    radius=r;
}

//计算圆的周长
float Circle::circumference()
{
    return 2*PI*radius;
}

//计算圆的面积
float Circle::area()
{
    return PI*radius*radius;
}

//主函数
int main()
{
    float radius;
    cout<<"Enter the radius of the pool: ";
    cin>>radius;

    Circle pool(radius);        //游泳池边界
    Circle poolRim(radius+3);     //栅栏对象

    //计算栅栏造价并输出
    float fenceCost=poolRim.circumference()*FENCE_PRICE;
    cout<<"Fencing Cost is $"<<fenceCost<<endl;

    //计算过道造价并输出
    float concreteCost=(poolRim.area()-pool.area())*CONCRETE_PRICE;
    cout<<"Concrete Cost is $"<<concreteCost<<endl;
    return 0;

}