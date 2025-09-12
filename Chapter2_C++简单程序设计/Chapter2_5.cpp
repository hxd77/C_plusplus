//exp2_5:求自然数1~10的和
#include<iostream>
using namespace std;
int main()
{
    int i=1,sum=0;
    while (i<=10)
    {
        sum+=i;
        i++;
    }
    cout<<"sum="<<sum<<endl;
    return 0;
}
