//exp3_15:带默认形参值的函数举例
#include<iostream>
#include<iomanip>
using namespace std;

int getVolume(int length,int width=2,int height=3);

int main()
{
    const int X=10,Y=12,Z=15;
    cout<<"Some box data is ";
    cout<<getVolume(X,Y,Z)<<endl;
    cout<<"Some box data is ";
    cout<<getVolume(X,Y)<<endl;
    cout<<"Some box data is ";
    cout<<getVolume(X)<<endl;
    return 0;
}

int getVolume(int length,int width/*=2*/,int height/*=3*/)
{
    cout<<setw(5)<<length<<setw(5)<<width<<setw(5)<<height<<'\t';
    return length*width*height;
}