//exp3_10:汉诺塔问题
#include<iostream>
using namespace std;

//将src针的最上面一个盘子移动到dest针上
void move(char src,char dest)
{
    cout<<src<<"-->"<<dest<<endl;
}

//把n个盘子从src针移动到dest针，以medium针作为中介
void hanoi(int n,char src,char medium,char dest)
{
    if(n==1)
    {
        move(src,dest);
    }
    else
    {
        hanoi(n-1,src,dest,medium);
        move(src,dest);
        hanoi(n-1,medium,dest,src);
    }
}

int main()
{
    int m;
    cout<<"Enter the number of disks: ";
    cin>>m;
    cout<<"the steps to move"<<m<<"disks:"<<endl;
    hanoi(m,'A','B','C');
    return 0;
}