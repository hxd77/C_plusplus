#include "Student.h"
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<fstream>
#include<iomanip>

using namespace std;

ifstream fin;//文件输入流
ofstream fout;//文件输出流

//建立学生管理系统
void StudentBase::buildBaseData()
{
    //提示系统已建立
    if(mNum.size()!=0)
    {
        system("cls");//清空控制台屏幕内容
        cout<<endl<<endl<<setw(25)<<" "<<"学生信息管理系统已建立! "<<endl;
        cout<<endl<<endl<<setw(25)<<" "<<"输入0返回上一层: ";
        string str;
        while(cin>>str)
        {
            if(str=="0")break;
            else cout<<endl<<endl<<setw(20)<<" "<<"输入错误! 按0返回上一层: ";
        }
        return ;
    }
    long num;
    string name,addr,major;
    int sex=1,age;
    
}
