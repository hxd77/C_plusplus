#include<iostream>
#include<cstring>
using namespace std;
class Date{
public:
    Date(int year=0,int month=0,int day=0):year(year),month(month),day(day){}
    ~Date(){}
    void setDate(){
        cin>>year>>month>>day;
    }
    inline void showDate(){cout<<year<<"年"<<month<<"月"<<day<<"日";}
private:
    int year,month,day;
};

class People{
public:
    People(){}
    People(char na[],char num[] ,char se[],char i[],int year,int month, int day):birthday(year,month,day)
    {
        strcpy(name,na);
        strcpy(number,num);
        strcpy(sex,se);
        strcpy(id,i);
    }
    People(const People&p)
    {
        strcpy(name,p.name);
        strcpy(number,p.number);
        strcpy(sex,p.sex);
        strcpy(id,p.id);
        birthday=p.birthday;
    }
    ~People(){}

    void input(){
        cout<<"姓名: ";
        cin>>name;
        cout<<"编号: ";
        cin>>number;
        cout<<"性别(男/女): ";
        cin>>sex;
        cout<<"出生日期(年/月/日): ";
        birthday.setDate();
        cout<<"身份证号: ";
        cin>>id;
        cout<<endl;
    }
    void showPeople()
    {
        cout<<endl;
        cout<<"姓名: "<<name<<endl;
        cout<<"编号: "<<number<<endl;
        cout<<"性别: "<<sex<<endl;
        cout<<"出生日期: ";
        birthday.showDate();
        cout<<endl;
        cout<<"身份证号: "<<id<<endl;
    }
private:
    char name[11];
    char number[7];
    char sex[4];
    char id[19];
    Date birthday;
};
int main()
{
    int n;//员工数
    cout<<"员工人数: ";
    cin>>n;
    People*p=new People[n];
    for(int i=0;i<n;i++)
    {
        p[i].input();
    }
    People p1(p[0]);
    p1.showPeople();
    for(int i=0;i<n;i++)
    {
        p[i].showPeople();
    }
    return 0;
}