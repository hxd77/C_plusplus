//exp3_5:计算公式
#include<iostream>
#include<cmath>
using namespace std;
const double TINY_VALUE=1e-10;
double tsin(double x)
{
    double g=0;
    double t=x;
    int n=1;
    do
    {
        g+=t;//g是最终的计算结果
        n++;
        t=-t*x*x/(2*n-1)/(2*n-2);
    } while (fabs(t)>=TINY_VALUE);//当某项绝对值小于计算精度时，停止
    return g;
}
int main()
{
    double k,r,s;
    cout<<"r=";
    cin>>r;
    cout<<"s=";
    cin>>s;
    if(r*r<=s*s)
    {
        k=sqrt(tsin(r)*tsin(r)+tsin(s)*tsin(s));
    }
    else
        k=tsin(r*s)/2;
    cout<<k<<endl;
    return 0;
}