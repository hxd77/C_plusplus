class Function{ //抽象类Function定义
public:
    virtual double operator()(double x)const=0; //纯虚函数重载运算符()
    virtual ~Function(){}; //虚析构函数
};

class MyFunction:public Function{ //共有派生类MyFunction定义
public:
    double operator()(double x)const; //覆盖虚函数
};

class Integratino{//抽象类Integration定义
public:
    virtual double operator()(double a,double b,double eps)const=0;
    virtual ~Integratino(){}; //虚析构函数
};

class Trapz:public Integratino{ //共有派生类Trapz定义
public:
    Trapz(const Function &f):f(f){}; //构造函数
    double operator()(double a,double b,double eps)const; //覆盖虚函数
private:
    const Function &f;
};

