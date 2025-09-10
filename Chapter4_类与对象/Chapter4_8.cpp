//exp4_8:使用联合体保存成绩信息，并且输出
#include<iostream>
#include<string>
using namespace std;
class ExamInfo{
public:
    //三种构造函数，分别用等级、是否通过和百分比来初始化
    ExamInfo(string name,char grade):name(name),mode(GRADE),grade(grade){}
    ExamInfo(string name,bool pass):name(name),mode(PASS),pass(pass){}
    ExamInfo(string name,int percent):name(name),mode(PERCENTAGE),percent(percent){}
    void show();
private:
    string name;
    enum{
        GRADE,PASS,PERCENTAGE
    }mode;
    union 
    {
        char grade;     //等级制的成绩
        bool pass;      //是否通过
        int percent;    //百分制的成绩
    };
};

void ExamInfo::show()
{
    cout<<name<<": ";
    switch (mode)
    {
    case GRADE:cout<<grade; //输出等级制成绩 
    break;
    case PASS:cout<<pass; //输出是否通过
    break;
    case PERCENTAGE:cout<<percent;     //输出百分制成绩
    break;
    }
    cout<<endl;
}

//主函数
int main()
{
    ExamInfo course1("English",'E');
    ExamInfo course2("Calculus",true);
    ExamInfo course3("C++Programming",100);
    course1.show();
    course2.show();
    course3.show();
    return 0;
}