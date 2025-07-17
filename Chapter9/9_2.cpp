//类模板应用举例
#include<iostream>
#include<cstdlib>
using namespace std;

struct Student{         //结构体Student
    int id;
    float gpa;
};

template<class T>
class Store{
public:
    Store();
    T &getElem();
    void putElem(const T&x);//存入数据函数
private:
    T item;     //item用于存放任意类型的数据
    bool haveValue;     //haveValue标记item是否已存入内容
};

//以下实现各成员函数
template <class T>
Store<T>::Store():haveValue(false){}

template<class T>
T &Store<T>::getElem()      //提取数据函数的实现
{
    if(!haveValue)      //如果试图提取未初始化的的数据，则终止程序
    {
        cout<<"No item present!"<<endl;
        exit(1);    
    }
    return item;
}

template <class T>
void Store<T>::putElem(const T&x)
{
    haveValue=true;         //将haveValue置为true,表示item已存入数值
    item=x;
}

int main()
{
    Store<int>s1,s2;        //定义两个Store<int>类对象，其中数据成员item为int类型
    s1.putElem(3);          //向对象s1中存入数据(初始化对象s1)
    s2.putElem(-7);         //向对象s2中存入数据(初始化对象s2)
    cout<<s1.getElem()<<" "<<s2.getElem()<<endl;

    Student g={1000,23};
    Store<Student>s3;
    s3.putElem(g);
    cout<<"The student id is "<<s3.getElem().id<<endl;
    
    Store<double>d;
    cout<<"Retrieving object d...";
    cout<<d.getElem()<<endl;
    //由于d未经初始化，在执行函数d.getElem()过程中导致程序终止
    return 0;
}