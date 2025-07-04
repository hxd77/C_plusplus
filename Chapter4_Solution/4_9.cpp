//设计一个Rectangle类
#include<iostream>
using namespace std;
class Rectangle{
public:
    Rectangle(int top,int left,int bottom,int right);
    ~Rectangle(){};
    int getTop()const {return top;}   //常成员函数
private:
    int top;
    int bottom;
    int left;
    int right;
}