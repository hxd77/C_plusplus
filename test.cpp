<<<<<<< HEAD
s#include<iostream>
using namespace std;

class Cat
{
public:
    Cat(int age):itsAge(age){       //���캯��
        numOfCats++;
    }
    virtual ~Cat(){                 //��������
        numOfCats--;
    }
    virtual int getAge(){
        return itsAge;
    }
    virtual void setAge(int age)
    {
        itsAge=age;
    }
    static int getNumOfCats()       //��̬����
    {  
        return numOfCats;
    }
private:
    static int numOfCats;       //��̬���ݳ�Ա
    int itsAge;
};

int Cat::numOfCats=0;       //��̬���ݳ�Ա�������ʼ��

void telepathicFunction()
{
    cout<<"There are "<<Cat::getNumOfCats()<<" cats alive!\n";
}

=======
#include <iostream>
using namespace std;

>>>>>>> 4ae1e979e98b8d10c7a788c9f3c6cab0f0ddb7d7
int main()
{
    int a=10;
    a-=2*3;
    cout<<a<<endl;
    return 0;
}