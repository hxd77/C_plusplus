#include<iostream>
using namespace std;
class Tree{
public:
    Tree(int ages):ages(ages){}
    ~Tree(){}
    void grow(int years);
    void age();
private:
    int ages;
};
void Tree::grow(int years)
{
    ages+=years;
}
void Tree::age()
{
    cout<<"这颗树的年龄为: "<<ages<<endl;
}

int main()
{
    Tree t(12);
    t.age();
    t.grow(4);
    t.age();
    return 0;
}