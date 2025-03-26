//编写函数float Convert(float TempFer)，参数和返回值都为float类型，实现算法
#include<iostream>
using namespace std;
float Convert(float TempFer)
{
    return (TempFer-32)*5/9;
}
int main()
{
    float temprature;
    cout<<"请输入一个华式温度: ";
    cin>>temprature;
    cout<<"你输入的华氏温度为: "<<temprature<<endl;
    cout<<"转化为摄制温度为: "<<Convert(temprature)<<endl;
    return 0;
}