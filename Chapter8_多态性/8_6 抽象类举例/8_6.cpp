#include<iostream>
using namespace std;

class Base1{
public:
    virtual void display() const =0; //纯虚函数
};

class Base2:public Base1{ //共有派生类Base2定义
public:
    void display() const; //覆盖纯虚函数
};

void Base2::display() const{
    cout<<"Base2::display()"<<endl;
}

class Derived:public Base2{ //共有派生类Base3定义
public:
    void display() const; //覆盖纯虚函数
};

void Derived::display() const{
    cout<<"Derived::display()"<<endl;
}

void fun(Base1* ptr){ //参数为指向基类对象的指针
    ptr->display();
}

int main(){
    Base2 base2;
    Derived derived;
    fun(&base2); //调用fun函数，传递Base2类对象的地址
    fun(&derived); //调用fun函数，传递Derived类对象的地址
    return 0;
}