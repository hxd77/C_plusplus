//exp3_1:编写一个求x的n次方的函数
#include<iostream>
using namespace std;
//计算x的n次方
double power(double x,int n)
{
    double val=1.0;
    while (n--)
    {
        val*=x;
    }
    return val;
}
int main()
{
    cout<<"5 to the power 2 is "<<power(5,2)<<endl;
    return 0;
}