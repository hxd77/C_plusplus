//�������������������������ֺ�С�����ֱַ����
#include<iostream>
using namespace std;
//��ʵ��x�ֳ��������ֺ�С�����֣��β�intPart��fracPart��ָ��
void splitFloat(float x,int *intPart,float*fracPart)
{
    *intPart=static_cast<int>(x);
    *fracPart=x-*intPart; //С�����ֵ���ʵ����ȥ��������
}

int main()
{
    cout<<"Enter 3 float point numbers:"<<endl;
    for(int i=0;i<3;i++)
    {
        float x,f;
        int n;
        cin>>x;
        splitFloat(x,&n,&f);
        cout<<"Integer Part="<<n<<" Fraction Part="<<f<<endl;
    }
    return 0;
}