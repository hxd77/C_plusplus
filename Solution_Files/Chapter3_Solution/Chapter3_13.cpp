//exp3_13:用递归的方法求Fibonacci级数
#include<iostream>
using namespace std;
int fib(int n);

int main()
{
    int n,answer;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"\n\n";
    answer=fib(n);
    cout<<answer<<" is the "<<n<<" the Fibonacci number\n";
    return 0; 
}
int fib(int n)
{
    cout<<"Processing fib("<<n<<")...";
    if(n<3)
    {
        return 1;
    }
    else
    {
        cout<<"Call fib("<<n-2<<") and fib("<<n-1<<").\n";
        return fib(n-1)+fib(n-2);
    }
}