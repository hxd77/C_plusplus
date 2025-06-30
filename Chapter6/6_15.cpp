//ͨ��ָ�������ľ�̬������Ա
#include<iostream>
using namespace std;
class Point{
public:
    Point(int x=0,int y=0):x(x),y(y){
        count++;
    }
    Point (const Point &p):x(p.x),y(p.y)
    {
        count++;
    }
    ~Point(){count--;}
    int getX()const{return x;}
    int getY()const {return y;}
    static void showCount()
    {
        cout<<"Object count="<<count<<endl;
    }
private:
    static int count;
    int x,y;
};

int Point::count=0;
int main()
{
    void (*funcPtr)() = Point::showCount;        //����һ��ָ������ָ�룬��Ϊָ����ľ�̬��Ա��������˿�������ͨ�ĺ���ָ��
    Point a(4,5);
    cout<<"Point A: "<<a.getX()<<", "<<a.getY();
    funcPtr();                                  //������������ֱ��ͨ��ָ����ʾ�̬������Ա

    Point b(a);
    cout<<"Point B: "<<b.getX()<<", "<<b.getY();
    funcPtr();
    return 0;
}