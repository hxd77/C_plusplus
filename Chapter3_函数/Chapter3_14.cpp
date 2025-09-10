//exp3_14:内联函数举例
#include<iostream>
using namespace std;

const double PI=3.14159265358979;

//内联函数，根据圆的半径计算其面积
inline double calArea(double radius)
{
    return PI*radius*radius;
}
int main()
{
    double r=3.0;
    double area=calArea(r);//调用内联函数求圆的面积，编译时此处    被替换为calArea函数体语句，展开为area=PI*radius*radiu
    cout<<area<<endl;
    return 0;
}