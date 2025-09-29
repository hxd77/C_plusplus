//本例将运算符"+"重载为对Complex类的加法运算，并将其声明为Complex类的友元函数
#include<iostream>
using namespace std;

class Complex{       //复数类定义
public:             //外部接口
    Complex(double r=0,double i=0.0):real(r),imag(i){}  //构造函数
    friend Complex operator+(const Complex &c1,const Complex &c2); //重载加法运算符
    friend Complex operator-(const Complex &c1,const Complex &c2); //重载减法运算符
    friend ostream & operator <<(ostream &out,const Complex &c); //运算符<<重载
private:            //私有数据成员
    double real;    //实部
    double imag;    //虚部
};

Complex operator+(const Complex &c1,const Complex &c2)//重载运算符函数实现
{
    return Complex(c1.real+c2.real,c1.imag+c2.imag);
}

Complex operator-(const Complex &c1,const Complex &c2)//重载运算符函数实现
{
    return Complex(c1.real-c2.real,c1.imag-c2.imag);
}

ostream & operator <<(ostream &out,const Complex &c)//重载运算符函数实现
{
    out<<"("<<c.real<<","<<c.imag<<"i)";
    return out;
}

int main()
{
    Complex c1(3.0,4.0),c2(1.0,2.0);
    Complex c3;
    c3=c1+c2;   //调用重载的加法运算符
    cout<<"c1+c2="<<c3<<endl; //调用重载的输出运算符
    c3=c1-c2;   //调用重载的减法运算符
    cout<<"c1-c2="<<c3<<endl; //调用重载的输出运算符
    return 0;
    cout<<"c3=c1+c2="<<c3<<endl;
    return 0;       
}