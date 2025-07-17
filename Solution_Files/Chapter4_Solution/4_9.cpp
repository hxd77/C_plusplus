//���һ��Rectangle��
#include<iostream>
using namespace std;
class Rectangle{
public:
    Rectangle(int top,int left,int bottom,int right);
    ~Rectangle(){};
    int getTop()const {return top;}   //����Ա����
    int getLeft()const {return left;}
    int getRight()const {return right;}
    int getBottom()const {return bottom;}
    void setTop(int top){top=top;}
    void setLeft(int left){left=left;}
    void setBottom(int bottom){bottom=bottom;}
    void setRight(int right){right=right;}
    int getArea()const;
private:
    int top;
    int bottom;
    int left;
    int right;
};

Rectangle::Rectangle(int top,int left,int bottom,int right)
{
    this->top=top;
    this->left=left;
    this->bottom=bottom;
    this->right=right;
}//һ��Ҫдthisָ�����ֻ���ʹ�ó�ʼ���б�ֵ



int Rectangle::getArea()const{
    int width=right-left;
    int height=top-bottom;
    return (width*height);
}

int main()
{
    Rectangle rect(100,20,50,80);
    cout<<"Area: "<<rect.getArea()<<endl;
    return 0;
}