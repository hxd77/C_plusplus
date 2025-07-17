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
    inline void showDate(){cout<<year<<"��"<<month<<"��"<<day<<"��";}
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
        cout<<"����: ";
        cin>>name;
        cout<<"���: ";
        cin>>number;
        cout<<"�Ա�(��/Ů): ";
        cin>>sex;
        cout<<"��������(��/��/��): ";
        birthday.setDate();
        cout<<"���֤��: ";
        cin>>id;
        cout<<endl;
    }
    void showPeople()
    {
        cout<<endl;
        cout<<"����: "<<name<<endl;
        cout<<"���: "<<number<<endl;
        cout<<"�Ա�: "<<sex<<endl;
        cout<<"��������: ";
        birthday.showDate();
        cout<<endl;
        cout<<"���֤��: "<<id<<endl;
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
    int n;//Ա����
    cout<<"Ա������: ";
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