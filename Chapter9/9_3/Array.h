//数组类
#ifndef ARRAY_H
#define ARRAY_H
#include<cassert>

//数组类模板定义
template <class T>
class Array{
private:
    T*list;     //T类型指针，用于存放动态分配的数组内存首地址
    int size;   //数组大小(元素个数)
public:
    Array(int sz=50);       //构造函数
    Array(const Array<T> &a);   //复制构造函数
    ~Array();               //析构函数
    Array<T>  
};
#endif