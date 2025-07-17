//exp2_28:用穷举法找出1~100间的质数
//(1)用while循环实现
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int i,j,k,flag;
    i=2;
    while (i<=100)
    {
        flag=1;
        k=sqrt(i);
        j=2;
        while (j<=k)
        {
            if (i%j==0)
            {
                flag=0;
                break;
            }
            j++;
        }
        if(flag)
            cout<<i<<"是质数."<<endl;
        i++;
    }
    return 0;
}