//���ʶ���Ĺ��г�Ա�����Ĳ�ͬ��ʽ
#include<iostream>
using namespace std;
class Point{
public:
    Point(int x=0, int y=0) : x(x), y(y) {}
    int getX() const { return x; }
    int getY() const { return y; }
private:
    int x, y;
};

int main()
{
    Point a(4,5);
    Point *p1=&a; // ָ��p1ָ�����a
    int (Point::*funcPtr)()const = &Point::getX; // �����Ա����ָ��funcPtr Ӧ����һ��ָ�볣��

    cout<<(a.*funcPtr)()<<endl;     //ʹ�ó�Ա����ָ��Ͷ��������ʳ�Ա����
    cout<<(p1->*funcPtr)()<<endl;   //ʹ�ó�Ա����ָ��Ͷ���ָ����ʳ�Ա����
    cout<<a.getX()<<endl;           //ʹ�ö��������ʳ�Ա����
    cout<<p1->getX()<<endl;         //ʹ�ö���ָ����ʳ�Ա����
    return 0;
}