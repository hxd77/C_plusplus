//定义一个Dog类，包括age，weight属性，以及对这些属性操作的方法。实现并测试这个类
#include<iostream>
using namespace std;
class Dog{
public:
    Dog(int initialAge=0,int initialWeight=5);
    ~Dog();
    int getAge(){return age;}
    void setAge(int age){this->age=age;}
    int getWeight(){return weight;}
    void setWeight(int weight){this->weight=weight;}

private:
    int age,weight;
};
//在类外定义构造函数时，参数不能带默认值，默认参数只能在类内声明的时候写。
Dog::Dog(int initialAge,int initialWeight){
    age=initialAge;
    weight=initialWeight;
}
Dog::~Dog(){}
int main()
{
    Dog Jack(2,10);
    cout<<"Jack is a Dog who is ";
    cout<<Jack.getAge()<<" years old and "<<Jack.getWeight()<<" pounds weight"<<endl;
    Jack.setAge(7);
    Jack.setWeight(120);
    cout<<"Now Jack is ";
    cout<<Jack.getAge()<<" years old and "<<Jack.getWeight()<<" pounds weight"<<endl;
    return 0;
}