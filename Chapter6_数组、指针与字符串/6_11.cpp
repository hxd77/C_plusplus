//函数指针实例
#include<iostream>
using namespace std;
void printStuff(float)      //传参但不使用
{
    cout<<"This is the print stuff function."<<endl;
}

void printMessage(float data)
{
    cout<<"The data to be listed is "<<data<<endl;
}

void printFloat(float data)
{
    cout<<"The data to be printed is "<<data<<endl;
}
const float PI=3.14159f;
const float TWO_PI=PI*2.0f;

int main()
{
    void (*functionPointer)(float); //函数指针
    printStuff(PI);
    functionPointer=printStuff;     //函数指针指向printStuff
    functionPointer(PI);
    functionPointer=printMessage;   //函数指针指向printMessage
    functionPointer(TWO_PI);
    functionPointer(13.0);
    functionPointer=printFloat;
    functionPointer(PI);
    printFloat(PI);
    return 0;
}