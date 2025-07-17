//��ģ��Ӧ�þ���
#include<iostream>
#include<cstdlib>
using namespace std;

struct Student{         //�ṹ��Student
    int id;
    float gpa;
};

template<class T>
class Store{
public:
    Store();
    T &getElem();
    void putElem(const T&x);//�������ݺ���
private:
    T item;     //item���ڴ���������͵�����
    bool haveValue;     //haveValue���item�Ƿ��Ѵ�������
};

//����ʵ�ָ���Ա����
template <class T>
Store<T>::Store():haveValue(false){}

template<class T>
T &Store<T>::getElem()      //��ȡ���ݺ�����ʵ��
{
    if(!haveValue)      //�����ͼ��ȡδ��ʼ���ĵ����ݣ�����ֹ����
    {
        cout<<"No item present!"<<endl;
        exit(1);    
    }
    return item;
}

template <class T>
void Store<T>::putElem(const T&x)
{
    haveValue=true;         //��haveValue��Ϊtrue,��ʾitem�Ѵ�����ֵ
    item=x;
}

int main()
{
    Store<int>s1,s2;        //��������Store<int>������������ݳ�ԱitemΪint����
    s1.putElem(3);          //�����s1�д�������(��ʼ������s1)
    s2.putElem(-7);         //�����s2�д�������(��ʼ������s2)
    cout<<s1.getElem()<<" "<<s2.getElem()<<endl;

    Student g={1000,23};
    Store<Student>s3;
    s3.putElem(g);
    cout<<"The student id is "<<s3.getElem().id<<endl;
    
    Store<double>d;
    cout<<"Retrieving object d...";
    cout<<d.getElem()<<endl;
    //����dδ����ʼ������ִ�к���d.getElem()�����е��³�����ֹ
    return 0;
}