//exp3_2:观察下面程序的运行输出，与你设想的有何不同，仔细体会引用的用法
#include<iostream>
using namespace std;
int main()
{
    int intOne;
    int &rSomeRef=intOne;
    intOne =5;
    cout<<"intOne: \t"<<intOne<<endl;
    cout<<"rSomeRef: \t"<<rSomeRef<<endl;
    cout<<"&intOne: \t"<<&intOne<<endl;
    cout<<"&rSomeRef: \t"<<&rSomeRef<<endl;

    int intTwo=8;
    rSomeRef=intTwo;
    cout<<"\nintOne: \t"<<intOne<<endl;
    cout<<"intTwo: \t"<<intTwo<<endl;
    cout<<"rSomeRef: \t"<<rSomeRef<<endl;
    cout<<"&intOne: \t"<<&intOne<<endl;
    cout<<"&intTwo: \t"<<&intTwo<<endl;
    cout<<"&rSomeRef: \t"<<&rSomeRef<<endl;
    return 0;

}
//一开始引用&rSomeRef=intOne后说明rSomeRef就是intOne的别名，所以两个地址一样