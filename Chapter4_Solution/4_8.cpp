//����һ��Dog�࣬����age��weight���ԣ��Լ�����Щ���Բ����ķ�����ʵ�ֲ����������
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
//�����ⶨ�幹�캯��ʱ���������ܴ�Ĭ��ֵ��Ĭ�ϲ���ֻ��������������ʱ��д��
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