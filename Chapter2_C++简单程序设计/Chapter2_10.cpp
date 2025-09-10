//exp2_10:读入一系列整数，统计出正整数个数i和负整数个数j，读入0则结束
#include<iostream>
using namespace std;
int main()
{
    int i=0,j=0,n;
    cout<<"Enter asome integers please(enter 0 to quit): "<<endl;
    cin>>n;
    while (n!=0)
    {
        if(n>0)
            i++;
        else
            j++;
        cin>>n;
    }
    cout<<"Count of negative integers: "<<j<<endl;
    return 0;
}