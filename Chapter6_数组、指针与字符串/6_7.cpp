//6.7 设有一个数int型数组a，有10个元素。用三种方法输出各元素
#include<iostream>
using namespace std;
int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,0};
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
/*
2. 使用数组名和指针运算
#include<iostream>
using namespace std;
int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,0};
    for(int i=0;i<10;i++)
    {
        cout<<*(a+i)<<" ";          
    }
    cout<<endl;
    return 0;
}

3. 使用指针变量
#include<iostream>
using namepspace std;
int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,0};
    for(int *p=a;p<(a+10);p++)
    {
        cout<<*p<<" ";
    }
    cout<<endl;
    return 0;
}
*/