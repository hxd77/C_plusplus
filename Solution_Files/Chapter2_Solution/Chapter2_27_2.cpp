//(2)使用switch来实现
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    char choice,c;
    while (1)
    {
        cout<<"Menu: A(dd),D(elete),S(ort),Q(uit),Select one: ";
        cin>>c;
        choice=toupper(c);
        switch (choice)
        {
        case 'A':
            cout<<"数据已经增加. "<<endl;
            break;
        case 'D':
            cout<<"数据已经删除. "<<endl;
            break;
            default:
        case 'S':
            cout<<"数据已经排序. "<<endl;
            break;
        case 'Q':
            exit(0);
            break;
        }
    }
    return 0;
}
