//Point���ʵ��
#include"Point.h"
#include<iostream>
#include<cmath>
using namespace std;

//ֱ��������ϣ�pointsΪ���㣬nPointΪ����
float lineFit(const Point points[], int nPoint)
{
    float avgX=0,avgY=0;
    float lxx=0,lyy=0,lxy=0;    //����x��y��ƽ��ֵ
    for(int i=0;i<nPoint;i++)
    {
        avgX+=points[i].getX()/nPoint; //��������ó���Ա����
        avgY+=points[i].getY()/nPoint;
    }
    for(int i=0;i<nPoint;i++)       //�����Lxx��Lyy��Lxy
    {
        lxx+=(points[i].getX()-avgX)*(points[i].getX()-avgX);
        lxy+=(points[i].getX()-avgX)*(points[i].getY()-avgY);
        lyy+=(points[i].getY()-avgY)*(points[i].getY()-avgY);
    }
    cout<<"This line can be fitted by y=ax+b."<<endl;
    cout<<"a="<<lxy/lxx<<endl;              //����ع�ϵ��a
    cout<<"b="<<avgY-lxy*avgX/lxx<<endl;    //����ع�ϵ��b
    return static_cast<float>(lxy/sqrt(lxx*lyy)); //�������ϵ��r
}

int main()
{
    Point p[10]={
        Point(6,10), Point(14,20), Point(26,30),
        Point(33,40), Point(46,50), Point(54,60),
        Point(67,70), Point(75,80), Point(84,90),
        Point(100,100)
    };  //��ʼ�����ݵ�
    float r=lineFit(p,10); //����������Ϻ���
    cout<<"Line coefficient r="<<r<<endl; //������ϵ��r
    return 0;
}