//二维数组举例
#include<iostream>
using namespace std;
int main()
{
    int array2[3][3]={{11,12,13},{21,22,23},{31,32,33}}; //定义二维数组
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<*(*(array2+i)+j)<<" "; //输出二维数组的元素
        }
        cout<<endl;
    }
}