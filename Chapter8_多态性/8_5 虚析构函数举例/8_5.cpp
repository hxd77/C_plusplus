#include<iostream>
using namespace std;

class Base{
public:
    virtual ~Base();
};
Base::~Base(){
    cout<<"Base destructor called"<<endl;
}

class Derived:public Base{
public:
    Derived();
    ~Derived();
private:
    int* p;
};
Derived::Derived(){
    p=new int(0);
    cout<<"Derived constructor called"<<endl;
}
Derived::~Derived(){
    cout<<"Derived destructor called"<<endl;
    delete p;
}  
void fun(Base*b){
    delete b;
}
int main(){
    Base*b=new Derived; //基类指针指向派生类对象
    //Derived derived;fun(&derived);也行
    fun(b);
    return 0;
}
