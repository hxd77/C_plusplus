//���һ��Rectangle��
#include<iostream>
using namespace std;
class Rectangle{
public:
    Rectangle(int top,int left,int bottom,int right);
    ~Rectangle(){};
    int getTop()const {return top;}   //����Ա����
private:
    int top;
    int bottom;
    int left;
    int right;
}