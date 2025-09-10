//exp3_4:寻找并输出11~999的数，它满足m、m^2、m^3均为回文数
//回文数是指其各位数字左右对称的整数。例如121、676、94249等。满足上述条件的数如m=11.m^2=121,m^3=1331
#include<iostream>
using namespace std;
//判断是否是回文数
bool symm(unsigned n)
{
    unsigned i=n;
    unsigned m=0;
    while (i>0)
    {
        m=m*10+i%10;//最后一位数
        i/=10;//依次取出该数的各位数字
    }
    return m==n;
    
}
int main()
{
    for (unsigned m = 11; m < 1000; m++)
    {
        if (symm(m)&&symm(m*m)&&symm(m*m*m))
        {
            cout<<"m="<<m;
            cout<<"  m*m="<<m*m;
            cout<<"  m*m*m="<<m*m*m;
            cout<<endl;
        }
        
    }
    return 0;
}


 