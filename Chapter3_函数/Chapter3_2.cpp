//exp3_2:输入一个8位二进制数，将其转换为十进制数输出
//调用exp3_1的power函数来求
#include<iostream>
using namespace std;
double power(double x,int n);//计算x的n次方
int main()
{
    int value=0;
    cout<<"Enter an 8 bit binary number: ";
    for (int i = 7; i >=0; i--)
    {
        char ch;
        cin>>ch;
        if(ch=='1')
        {
            value+=static_cast<int>(power(2,i));
        }
    }
    cout<<"Decimal value is "<<value<<endl;
    return 0;
}
double power(double x,int n)
{
    double val=1.0;
    while (n--)
    {
        val*=x;
    }
    return val;
}