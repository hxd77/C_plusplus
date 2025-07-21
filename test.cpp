#include<iostream>
using namespace std;

class Cat
{
public:
    Cat(int age):itsAge(age){       //构造函数
        numOfCats++;
    }
    virtual ~Cat(){                 //析构函数
        numOfCats--;
    }
    virtual int getAge(){
        return itsAge;
    }
    virtual void setAge(int age)
    {
        itsAge=age;
    }
    static int getNumOfCats()       //静态函数
    {  
        return numOfCats;
    }
private:
    static int numOfCats;       //静态数据成员
    int itsAge;
};

int Cat::numOfCats=0;       //静态数据成员的类外初始化

void telepathicFunction()
{
    cout<<"There are "<<Cat::getNumOfCats()<<" cats alive!\n";
}

int main()
{
    const int maxCats=5;
    Cat*catHouse[maxCats];
    int i;
    for(i=0;i<maxCats;i++)
    {
        catHouse[i]=new Cat(i);
        telepathicFunction();
    }

    for(i=0;i<maxCats;i++)
    {
        delete catHouse[i];
        telepathicFunction();
    }
    return 0;
}
