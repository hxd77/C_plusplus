//判断一个数是否为质数
#include<iostream>
#include<cmath>
using namespace std;

int prime(int i);

int main()
{
    int i;
    cout<<"请输入一个整数: ";
    cin>>i;
    if(prime(i))
    {
        cout<<i<<"是质数"<<endl;
    }
    else
        cout<<i<<"不是质数"<<endl;
    return 0;
}

int prime(int i)//试除法
{
    int flag=1;//相当于bool中的判断
    for (int j = 2; j < sqrt(i); j++)
    {
        if (i%j==0)
        {
            flag=0;
            break;
            return flag;
        }
    }
    return flag;
    
}