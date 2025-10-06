#include"Trapzint.h"
#include<cmath>

//被积函数
double MyFunction::operator()(double x)const{
    return log(1.0+x)/(1.0+x*x);
}

//积分运算过程，重载为运算符()
double Trapz::operator()(double a,double b,double eps)const
{
    bool done=false; //积分是否完成标志
    int n=1;
    double h=b-a; 
    double tn=h*(f(a)+f(b))/2.0; //计算n=1时的积分值
    double t2n;
    do{
        double sum=0;
        for(int k=0;k<n;k++)
        {
            double x=a+(k+0.5)*h; //计算中点
            sum+=f(x); //累加中点处函数值
        }
        t2n=(tn+h*sum)/2.0; //变步长梯形计算
        if(fabs(t2n-tn)<eps) done=true; //判断是否满足精度要求
        else{
            tn=t2n; //更新tn值
            n*=2; //步长减半
            h/=2;
        }
    }while(!done);
    return t2n;
}
