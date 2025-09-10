//exp2_6:输出一个整数，将各位数字反转后输出
#include<iostream>
using namespace std;
int main()
{
    int num,right_digit;
    cout<<"Enter the number: "<<endl;
    cin>>num;
    cout<<"The number in reverse order is ";
    do
    {
        right_digit=num%10;
        cout<<right_digit;
        num/=10;
        /* code */
    } while (num!=0);
    cout<<endl;
    return 0;
}