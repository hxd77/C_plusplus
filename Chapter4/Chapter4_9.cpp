//exp4_9:设某次体育比赛的结果有四种可能：胜(WIN)、负(LOSE)、平局(TIE)、比赛取消(CACEL)，编写程序顺序输出这四种可能
#include<iostream>
using namespace std;
enum GameResult{WIN,LOSE,PIE,CACEL};

int main()
{
    GameResult result;      //声明变量时，可以不写关键字enum
    enum GameResult omit=CACEL;//也可以写enum

    for(int count=WIN;count<=CACEL;count++)//枚举类型具有默认值，从0开始 //隐式类型转换
    {
        result=GameResult(count);       //显式类型转换
        if(result==omit)
        {
            cout<<"The game was cancelles"<<endl;
        }
        else{
            cout<<"The game was played ";
            if(result==WIN)
            {
                cout<<"and we won!";
            }
            if(result==LOSE){
                cout<<"and we lost.";
            }
            cout<<endl;
        }
    }
    return 0;
}