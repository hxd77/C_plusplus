//exp3_13:值传递与引用传递的比较
#include<iostream>
#include<iomanip>
using namespace std;

void fiddle(int in1,int &in2)
{
    in1=in1+100;
    in2=in2+100;
    cout<<"The value are ";
    cout<<setw(5)<<in1;
    cout<<setw(5)<<in2<<endl;
}

int main()
{
    int v1=7,v2=12;
    cout<<"The value are ";
    cout<<setw(5)<<v1;
    cout<<setw(5)<<v2<<endl;
    fiddle(v1,v2);
    cout<<"The value are ";
    cout<<setw(5)<<v1;
    cout<<setw(5)<<v2<<endl;
    return 0;

}