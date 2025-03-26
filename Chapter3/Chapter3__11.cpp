//exp3_11:将两个整数交换次序后输出
#include<iostream>
using namespace std;
void swap(int a,int b)
{
    int t=a;
    a=b;
    b=t;
}
int main()
{
    int x=5,y=10;
    cout<<"x="<<x<<"   y="<<y<<endl;
    swap(x,y);
    cout<<"x="<<x<<"   y="<<y<<endl;
    return 0;
}