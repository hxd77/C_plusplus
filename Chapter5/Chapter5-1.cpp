//exp5_1:作用域实例
#include<iostream>
using namespace std;

int i;              //全局变量

int main()
{
    i=5;            //为全局变量赋值
    {
        int i;      //子块1
        i=7;
        cout<<"i="<<i<<endl;    //输出7
    }
    cout<<"i="<<i<<endl;        //输出5
    return 0;
}