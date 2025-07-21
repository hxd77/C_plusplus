//读入三个浮点数，将整数部分和小数部分分别输出
#include<iostream>
using namespace std;
//将实数x分成整数部分和小数部分，形参intPart、fracPart是指针
void splitFloat(float x,int *intPart,float*fracPart)
{
    *intPart=static_cast<int>(x);
    *fracPart=x-*intPart; //小数部分等于实数减去整数部分
}

int main()
{
    cout<<"Enter 3 float point numbers:"<<endl;
    for(int i=0;i<3;i++)
    {
        float x,f;
        int n;
        cin>>x;
        splitFloat(x,&n,&f);
        cout<<"Integer Part="<<n<<" Fraction Part="<<f<<endl;
    }
    return 0;
}