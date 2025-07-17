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
    cout<<"��������εĳ���: ";
    cin>>length;
    cout<<"��������εĿ��: ";
    cin>>width;
    Rectangle r(length,width);
    cout<<"��Ϊ"<<length<<"��Ϊ"<<width<<"�ľ��ε����Ϊ: "<<r.getArea()<<endl;
    return 0;
}