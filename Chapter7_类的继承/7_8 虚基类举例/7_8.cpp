#include<iostream>
using namespace std;

class Base0{        //�������Base0
public:
    int var0;
    void fun0(){cout<<"Member of Base0"<<endl;}
};

class Base1:virtual public Base0{   //����������Base1
public:
    int var1;               //�����ⲿ�ӿ�
};

class Base2:virtual public Base0{   //����������Base2
public:
    int var2;                       //�����ⲿ�ӿ�
};

class Derived:public Base1,public Base2{    //����������Derived
public:                             //�����ⲿ�ӿ�
    int var;
    void fun(){cout<<"Member of Derived"<<endl;}
};

int main()
{
    Derived d;
    d.var0=2;       //ֱ�ӷ������������ݳ�Ա
    d.fun0();        //ֱ�ӷ��������ĺ�����Ա
    return 0;
}