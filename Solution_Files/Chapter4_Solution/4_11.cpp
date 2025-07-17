#include<iostream>
using namespace std;
class Rectangle{
public:
    Rectangle(float length,float width)
    {
        this->length=length;
        this->width=width;
    }
    float getArea() const 
    {
        return length*width;
    }
    float getWidth()const{return width;}
    float getLength()const {return length;}
    ~Rectangle(){}
private:
    float length,width;
};

int main()
{
    float length,width;
    cout<<"请输入矩形的长度: ";
    cin>>length;
    cout<<"请输入矩形的宽度: ";
    cin>>width;
    Rectangle r(length,width);
    cout<<"长为"<<length<<"宽为"<<width<<"的矩形的面积为: "<<r.getArea()<<endl;
    return 0;
}