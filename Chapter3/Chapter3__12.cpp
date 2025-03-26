//exp3_12:使用引用传递改写例3-11的程序，使良政署成功地进行交换
#include<iostream>
using namespace std;
void swap(int &a,int &b)
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