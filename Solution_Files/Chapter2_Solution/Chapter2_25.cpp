//编写一个程序，实现功能，向用户提问“现在正在下雨吗”，提示用户输入Y或N，若输入为Y，显示“现在正在下雨。”；若输入为N，显示“现在没有下雨。
//否则继续提问“现在正在下雨吗”
#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    char flag;
    while (1)
    {
    
        cout<<"现在正在下雨吗?(Y or N):";
        cin>>flag;
        if(toupper(flag)=='Y')
        {
            cout<<"现在正在下雨。";
            break;
        }
        if(toupper(flag)=='N')
        {
            cout<<"现在没有下雨。";
            break;
        }
        cout<<endl;
    }
    return 0;
}