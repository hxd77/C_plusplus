//exp6_3:对象数组应用举例
#include<iostream>
#include "Point.h"
using namespace std;

int main()
{
    cout<<"Entering main..."<<endl;
    Point a[2];
    for(int i=0;i<2;i++)
    {
        a[i].move(i+10,i+20);
    }
    cout<<"Exiting main..."<<endl;
    return 0;
}