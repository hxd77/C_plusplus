//�ļ�2�����ʵ��
#include "Point.h"
#include<iostream>
using namespace std;

int Point::count=0;  //��̬���ݳ�Ա�Ķ���
Point::Point(const Point&p):x(p.x),y(p.y){count++;}
void Point::showCount()
{
    cout<<"Objects count = "<<count<<endl;
}
