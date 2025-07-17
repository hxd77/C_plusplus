# 第五章习题解答


### 5-1 什么叫做作用域？有哪几种类型的作用域？

解：作用域讨论的是标识符的有效范围，作用域是一个标识符在程序正文中有效的区域。C++的作用域分为函数**原型作用域、块作用域（局部作用域）、类作用域和文件作用域。**



### 5-2 什么叫做可见性？可见性的一般规则是什么？

解：可见性是标识符是否可以引用的问题。

可见性的一般规则是：标识符要声明在前，引用在后；在同一作用域中，不能声明**同名的标识的标识符**。对于在不同的作用域声明的标识符，遵循的规则是：若有两个或多个具有包含关系的作用域，外层声明的标识符如果在内层没有声明同名标识符时仍可见，如果内层声明了同名标识符则外层标识符不可见。



### 5-3 下面的程序运行结果是什么？实际运行一下，看看与你的设想有何不同？

```c++
#include<iostream>
using namespace std;
int x=5,y=7;
void myFunction()
{
    int y=10;
    
    cout<<"x from myFunction: "<<x<<"\n";
 	cout<<"y from myFunction: "<<y<<"\n\n";
}
int main()
{
    cout<<"x from main: "<<x<<"\n";
	cout<<"y from main: "<<y<<"\n";
    myFunction();
    cout<<"Back from myFunction!\n\n";
    cout<<"x from main: "<<x<<"\n";
	cout<<"y from main: "<<y<<"\n";
    return 0;
}
```

解：程序运行输出：

```c++
x from main: 5
y from main: 7
x from myFunction: 5
y from myFunction: 10

Back from myFunction!

x from main: 5
y from main: 7
```



### 5-4 假设有两个无关系的类Engine和Fuel，使用时，怎样允许Fuel成员访问Engine中的私有和保护的成员?

解：源程序：

```c++
class fuel;
class engine
{
	friend class fuel;	//fuel类是engine类的友元类
	private:
		int powerlevel;
	public:
		engine(){powerlevel=0;}
		void engine_fn(fuel &f);
};
class fuel
{
    friend class engine;	//engine类是fuel类的友元类
    private:
    	int fuelLevel;
   	public:
    	fuel(){fuelLevel=0;}
    	void fuel_fn(engine &e);
};
```



### 5-5 什么叫做静态数据成员？它有何特点？

解：类的静态数据成员是类的数据成员的一种特例，采用static关键字来声明。对于类的普通数据成员，每一个类的对象都拥有一份存储，就是说每个对象的同名数据成员可以分别存储不同的数值，这也是保证对象拥有自身区别于其他对象的特征的需要，但是静态数据成员，每个类只要一份存储，由所有该类的对象共同维护和使用，这个共同维护、使用也就实现了同一类的不同对象的数据共享。



### 5-6 什么叫做静态函数成员？它有何特点？

解：使用static关键字声明的函数成员是静态的，静态函数成员属于整个类，同一个类的所有对象共同维护，为这些对象所共享。静态函数成员具有以下两个方面的好处，一是由于静态成员函数只能访问同一个类的静态数据成员，可以保证不会对该类的其余数据成员造成负面影响；二是同一个类只维护一个静态函数成员的拷贝，节约了系统的开销，提高程序的运行效率。



### 5-7 定义一个Cat类，拥有静态数据成员numOfCats，记录Cat的个体数目；静态成员函数getNumOfCats()，存取numOfCats。设计程序测试这个类，体会静态数据成员和静态成员函数的用法。

解：源程序：



### 5-8 什么叫做友元函数？什么叫做友元类？

解：友元函数是使用friend关键字声明的函数，它可以访问相应类的保护成员和私有成员。友元类是使用friend关键字声明的类，它的所有成员函数都是相应类的友元函数。

 
