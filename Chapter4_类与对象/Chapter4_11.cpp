//exp4_11:设计一个结构体存储学生的成绩信息，需要包括学号、年级和成绩三项内容，学号的范围是0到99999999，...
#include<iostream>
using namespace std;
enum Level{FRESHMAN,SOPHOMORE,JUNIOR,SENIOR};
enum Grade{A,B,C,D};
class Student{
public:
    Student(unsigned number,Level level,Grade grade):number(number),level(level),grade(grade){}
    void show();
private:
    unsigned number:27;//unsigned number <==>unsigned int number
    Level level:2;
    Grade grade:2;
};

void Student::show()
{
    cout<<"Number:  "<<number<<endl;
    cout<<"Level    ";
    switch (level)
    {
    case FRESHMAN:cout<<"freshman";break;
    case SOPHOMORE:cout<<"sophomore";break;
    case JUNIOR:cout<<"junior";break;
    case SENIOR:cout<<"senior";break;
    }
    cout<<endl;
    cout<<"Grade    ";
    switch (grade)
    {
    case A:cout<<"A"<<endl;break;
    case B:cout<<"B"<<endl;break;
    case C:cout<<"C"<<endl;break;
    case D:cout<<"D"<<endl;break;
    }
    cout<<endl;
}

int main()
{
    Student s(123456778,SOPHOMORE,B);
    cout<<"Size of Student:"<<sizeof(Student)<<endl;
    s.show();
    return 0;
}