//exp2_7:用do...while语句求自然数1~10的和
#include<iostream>
using namespace std;
int main()
{
    int i=1,sum=0;
    do
    {
        sum+=i;
        i++;
    } while (i<=10);
    cout<<"sum="<<sum<<endl;
    return 0;
}