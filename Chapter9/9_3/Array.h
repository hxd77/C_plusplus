//������
#ifndef ARRAY_H
#define ARRAY_H
#include<cassert>

//������ģ�嶨��
template <class T>
class Array{
private:
    T*list;     //T����ָ�룬���ڴ�Ŷ�̬����������ڴ��׵�ַ
    int size;   //�����С(Ԫ�ظ���)
public:
    Array(int sz=50);       //���캯��
    Array(const Array<T> &a);   //���ƹ��캯��
    ~Array();               //��������
    Array<T>  
};
#endif