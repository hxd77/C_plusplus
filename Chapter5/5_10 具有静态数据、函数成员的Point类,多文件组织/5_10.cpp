//�ļ�3��������
#include"Point.h"
#include<iostream>
using namespace std;

int main()
{
    Point a(4,5);       //�������a���乹�캯����ʹcount��1
    cout<<"Point A: "<<a.getX()<<","<<a.gety()<<endl;
    Point::showCount(); //��ʾ��ǰ�������
    Point b(a);         //�������b���乹�캯����ʹcount��1
    cout<<"Point B: "<<b.getX()<<","<<b.gety()<<endl;
    Point::showCount(); //��ʾ��ǰ�������
    return 0;
    
}