//在主程序中提示输入整数n，编写函数用递归的方法求1+2+...+n的值
#include<iostream>
using namespace std;
int fn1(int n);

int main()
{
    int i;
    cout<<"请输入一个正整数: ";
    cin>>i;

    cout<<"从1累加到"<<i<<"的和为: "<<fn1(i)<<endl;
    return 0;
}

int fn1(int n)
{
    if(n==1)
        return 1;
    else 
        return n+fn1(n-1);
}