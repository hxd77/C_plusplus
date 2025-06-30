//exp2_30:声明一个表示时间的结构体,然后完整地显示出来
#include<iostream>
using namespace std;
struct Time
{
    int Year;
    int Month;
    int Day;
    int Hour;
    int Minute;
    int Second;
};

int main()
{
    Time time;
    int year,month,day,hour,minute,second;
    cout<<"Please Enter the year,month,day,hour,minute,second: ";
    cin>>year>>month>>day>>hour>>minute>>second;
    time={year,month,day,hour,minute,second};
    cout<<"It 's "<<time.Year<<" year "<<time.Month<<" month "<<time.Day<<" day "<<time.Hour<<" hour "<<time.Minute<<" minute "<<time.Second<<" second "<<endl;
    return 0;
   
}