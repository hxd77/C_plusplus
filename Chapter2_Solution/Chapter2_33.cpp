//声明枚举类型Weekday,包括SUNDAY到SAYURDAY7个元素在程序中声明Weekday类型的变量...
#include<iostream>
using namespace std;
enum Weekday{
    SUNDAY,MONDAY,TUESDAY,WEDNESDAY,THURSDAY,FRIDAY,SATURDAY
};
int main()
{
    int i;
    Weekday  d=THURSDAY;
    cout<<"d="<<d<<endl;
    i=d;
    cout<<"i="<<i<<endl;

    d=(Weekday)6;
    cout<<"d="<<d<<endl;
    d=Weekday(4);
    cout<<"d="<<d<<endl;
    return 0;

}