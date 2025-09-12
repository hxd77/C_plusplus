#include<iostream>
using namespace std;

class Base0{        //定义基类Base0
public:
    int var0;
    void fun0(){cout<<"Member of Base0"<<endl;}
};

class Base1:virtual public Base0{   //定义派生类Base1
public:
    int var1;               //新增外部接口
};

class Base2:virtual public Base0{   //定义派生类Base2
public:
    int var2;                       //新增外部接口
};

class Derived:public Base1,public Base2{    //定义派生类Derived
public:                             //新增外部接口
    int var;
    void fun(){cout<<"Member of Derived"<<endl;}
};

int main()
{
    Derived d;
    d.var0=2;       //直接访问虚基类的数据成员
    d.fun0();        //直接访问虚基类的函数成员
    return 0;
}