/*exp3_9:用递归法计算从n个人中选择k个人组成一个委员会的不同组合数
=由n-1个人里选k个人的组合数+由n-1个人里选k-1个人的组合数*/
#include<iostream>
using namespace std;

//计算从n个人里选k个人的组合数
int comm(int n,int k)
{
    if (k>n)
    {
        return 0;    
    }
    else if (n==k||k==0)
    {
        return 1;
    }
    else
        return comm(n-1,k)+comm(n-1,k-1);
}
int main()
{
    int n,k;
    cout<<"Please enter two integers n and k: ";
    cin>>n>>k;
    cout<<"C(n,k)="<<comm(n,k)<<endl;
    return 0;
}



