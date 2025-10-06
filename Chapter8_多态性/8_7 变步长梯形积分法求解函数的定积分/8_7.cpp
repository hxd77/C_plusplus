#include"Trapzint.h"
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    MyFunction f; //定义被积函数对象
    Trapz trapz(f); //定义积分对象
    //计算并输出积分结果
    cout<<"TRAPZ INT: "<<setprecision(7)<<trapz(0,2,1e-7)<<endl;
    return 0;
}