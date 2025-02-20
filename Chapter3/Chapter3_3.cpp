//exp3_3:编写程序求Π的值 Π=16arctan(1/5)-4arctan(1/239)
//其中arctan=x-x^3/3+x^5/5-x^7/7+...，直到级数某项绝对值不大于10^-15为止
#include<iostream>
using namespace std;
double arctan(double x)
{
    double sqr=x*x;
    double e=x;
    double r=0; 
    int i=1;//i代表次数
    while(e/i>1e-15)
    {

        double f=e/i;
        r=(i%4==1)?r+f:r-f;
        e=e*sqr;
        i+=2;
    }
    return r;
}
int main()
{
    double a=16.0*arctan(1/5.0);
    double b=4.0*arctan(1/239.0);
    cout<<"PI="<<a-b<<endl;
    return 0;
}