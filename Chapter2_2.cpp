//exp2_2，输入一个年份，判断是否是闰年
#include<iostream>
using namespace std;
int main()
{
    int year;
    bool isLeapYear;
    cout<<"Enter the year: ";
    cin>>year;
    isLeapYear=(year%100!=0&&year%4==0)||(year%400==0);
    if (isLeapYear)
    {
        cout<<year<<" is a leap year"<<endl;
    }
    else
    {
        cout<<year<<" is not a leap year"<<endl;
    }

    return 0;
}