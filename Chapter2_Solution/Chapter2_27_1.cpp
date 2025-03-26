//exp2_27:实现一个简单的菜单程序
//(1)用if-else实现
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
        if(choice=='A')
        {
            cout<<"数据已经增加. "<<endl;
            continue;
        }
        else if(choice=='D') 
        {
            cout<<"数据已经删除. "<<endl;
            continue;
        }
        else if(choice=='S')
        {
            cout<<"数据已经排序. "<<endl;
            continue;
        }
        else if(choice=='Q')
        {
            break;
        }
    }
    return 0;
}
