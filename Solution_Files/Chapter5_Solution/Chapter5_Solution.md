# 第五章习题解答


### 5-1 什么叫做作用域？有哪几种类型的作用域？

解：作用域讨论的是标识符的有效范围，作用域是一个标识符在程序正文中有效的区域。C++的作用域分为函数**原型作用域、块作用域（局部作用域）、类作用域和文件作用域。**



### 5-2 什么叫做可见性？可见性的一般规则是什么？

解：可见性是标识符是否可以引用的问题。

可见性的一般规则是：标识符要声明在前，引用在后；在同一作用域中，不能声明**同名的标识的标识符**。对于在不同的作用域声明的标识符，遵循的规则是：**若有两个或多个具有包含关系的作用域，外层声明的标识符如果在内层没有声明同名标识符时仍可见，如果内层声明了同名标识符则外层标识符不可见。**



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

>在myFuncton函数之外，可以引用具有文件作用域的变量，可就是可见的。但当程序进入myFunction之后，就只能引用具有局部作用域的同名变量，具有文件作用域的同名变量被隐藏的。



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

>根据友元函数的特性，友元函数是一个普通的函数，也可以是其他类的成员函数。虽然它不是本类的成员函数，但是在它的函数体中可以通过对象名访问类的私有和保护成员，



### 5-5 什么叫做静态数据成员？它有何特点？

解：类的静态数据成员是类的数据成员的一种特例，采用static关键字来声明。对于类的普通数据成员，每一个类的对象都拥有一份存储，就是说每个对象的同名数据成员可以分别存储不同的数值，这也是保证对象拥有自身区别于其他对象的特征的需要，但是静态数据成员，每个类只要一份存储，由所有该类的对象共同维护和使用，这个共同维护、使用也就实现了同一类的不同对象的数据共享。



### 5-6 什么叫做静态函数成员？它有何特点？

解：使用static关键字声明的函数成员是静态的，静态函数成员属于整个类，同一个类的所有对象共同维护，为这些对象所共享。静态函数成员具有以下两个方面的好处，一是由于静态成员函数只能访问同一个类的静态数据成员，可以保证不会对该类的其余数据成员造成负面影响；二是同一个类只维护一个静态函数成员的拷贝，节约了系统的开销，提高程序的运行效率。



### 5-7 定义一个Cat类，拥有静态数据成员numOfCats，记录Cat的个体数目；静态成员函数getNumOfCats()，存取numOfCats。设计程序测试这个类，体会静态数据成员和静态成员函数的用法。

解：源程序：

```c++
#include<iostream>
using namespace std;

class Cat
{
public:
    Cat(int age):itsAge(age){       //构造函数
        numOfCats++;
    }
    virtual ~Cat(){                 //析构函数
        numOfCats--;
    }
    virtual int getAge(){
        return itsAge;
    }
    virtual void setAge(int age)
    {
        itsAge=age;
    }
    static int getNumOfCats()       //静态函数
    {  
        return numOfCats;
    }
private:
    static int numOfCats;       //静态数据成员
    int itsAge;
};

int Cat::numOfCats=0;       //静态数据成员的类外初始化

void telepathicFunction()
{
    cout<<"There are "<<Cat::getNumOfCats()<<" cats alive!\n";
}

int main()
{
    const int maxCats=5;
    Cat*catHouse[maxCats];
    int i;
    for(i=0;i<maxCats;i++)
    {
        catHouse[i]=new Cat(i);
        telepathicFunction();
    }

    for(i=0;i<maxCats;i++)
    {
        delete catHouse[i];
        telepathicFunction();
    }
    return 0;
}
```

运行结果：

```c++
There are 1 cats alive!
There are 2 cats alive!
There are 3 cats alive!
There are 4 cats alive!
There are 5 cats alive!
There are 4 cats alive!
There are 3 cats alive!
There are 2 cats alive!
There are 1 cats alive!
There are 0 cats alive!
```



### 5-8 什么叫做友元函数？什么叫做友元类？

解：友元函数是使用friend关键字声明的函数，它可以访问相应类的保护成员和私有成员。友元类是使用friend关键字声明的类，它的所有成员函数都是相应类的友元函数。



### 5-9 如果类A是类B的友元类，类B是类C的友元类，类D是类A的派生类，那么类B是类A的友元类吗？类C是类A的友元类吗？类D是类B的友元吗？

解：类B不是类A的友元类，友元关系不具有交换性。

类C不是类A的友元类，友元关系不具有传递性。

类D不是类B的友元类，友元关系不能被继承。



### 5-10 静态成员变量可以为私有的吗？声明一个私有的静态整型成员变量。

解：可以，例如：

private:

​	static int a;

### 5-11 在一个文件中定义一个全局变量n，主函数main()，在另一个文件中定义函数fnl()，在main()中对n赋值，再调用fn1()，在fn1()中也对n赋值，显示n最后的值。

解：

```cpp
#include<iostream>
using namespace std;

#include "fn1.h"

int n;
int main()
{
    n=20;
    fnl();
    cout<<"n的值为"<<n;
    return 0;
}

//fn1.h文件
extern int n;
void fn1()
{
    n=30;
}
```

程序运行输出：

```markdown
n的值为10
```



### 5-12 在函数fn1()中定义一个静态变量n，fn1()中对n的值加1，在主函数中，调用fn1()10次，显示n的值。

解：

```c++
#include<iostream>
using namespace std;

void fn1()
{
    static int n=0;
    n++;
    cout<<"n的值为"<<n<<endl;
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        /* code */
        fn1();
    }
    return 0;
}
```

程序运行输出：

```markdown
n的值为1
n的值为2
n的值为3
n的值为4
n的值为5
n的值为6
n的值为7
n的值为8
n的值为9
n的值为10
```



### 5-13 定义类X、Y、Z，函数h(X\*)，满足：类X有私有成员i，Y的成员函数g(X\*\是X的友元函数，实现对X的成员i加1；类Z是类X的友元类，其成员函数f(X*)实现对X的成员i加5；函数h(X\*)是X的友元函数，实现对X的成员i加10。在一个文件中定义和实现类，在另一个文件中实现main()函数。

解：

```c++
#include"my_x_y_z.h"
int main()
{
    X x;
    Z z;
    z.f(&x);
    return 0;
}

//my_x_y_z_h文件
#ifndef MY_X_Y_Z_H

class X;
class Y{
public:
    void g(X*);//省略形参名
};
class X
{
private:
    int i;
public:
    X(){i=0;}
    friend void h(X*);
    friend void Y::g(X*);
    friend class Z;
};
void h(X*x) {x->i+=10;}
void Y::g(X*x){x->i+=1;}

class Z{
public:
    void f(X*x){x->i+=5;}
};
#endif
```

程序运行输出：

无



### 5-14 定义Boat与Car两个类，二者都有weight属性，定义二者的一个友元函数getTotalWeight()，计算二者重量和。

解：源程序：

```c++
  #include<iostream>
using namespace std;

class Boat;
class Car{
private:
    int weight;
public:
    Car(int j) { weight = j; }
    friend int getTotalWeight(Car &aCar, Boat &aBoat);
};

class Boat{
private:
    int weight;
public:
    Boat(int j) { weight = j; }
    friend int getTotalWeight(Car &aCar, Boat &aBoat);
};

int getTotalWeight(Car &aCar, Boat &aBoat)
{
    return aCar.weight + aBoat.weight;
}

int main()
{
    Car c1(4);
    Boat b1(5);

    cout << getTotalWeight(c1, b1) << endl; 
    return 0;
}

```

程序运行输出：

```c++
9
```



### 5-15 在函数内部定义的普通局部变量和静态局部变量在功能上有何不同？计算机底层变量做了怎样的不同处理，导致了这种差异？

解：局部作用域中静态变量的特点是：它并不会随着每次函数调用而产生一个副本，也不会随着函数返回而失效，定义时未指定初值的基本类型静态生存期变量，会被以0值初始化；局部作用域中的局部变量诞生于声明点，结束与声明所在的块执行完毕之时，并且不指定初值意味着初值不确定。

普通局部变量存放于栈区超出作用域后，变量被撤销，其所占用的内存也被收回；静态局部变量存放于静态数据存储区，全局可见，但是作用域是局部作用域，超出作用域后变量仍然存在。

**举例说明：**

```cpp
#include <iostream>
using namespace std;

void testNormal() {
    int x = 0;  // 普通局部变量
    x++;
    cout << "普通局部变量 x = " << x << endl;
}

void testStatic() {
    static int y = 0;  // 静态局部变量
    y++;
    cout << "静态局部变量 y = " << y << endl;
}

int main() {
    cout << "第一次调用函数" << endl;
    testNormal();
    testStatic();

    cout << "第二次调用函数" << endl;
    testNormal();
    testStatic();

    cout << "第三次调用函数" << endl;
    testNormal();
    testStatic();
}

```

运行结果：

```c++
第一次调用函数
普通局部变量 x = 1
静态局部变量 y = 1
第二次调用函数
普通局部变量 x = 1
静态局部变量 y = 2
第三次调用函数
普通局部变量 x = 1
静态局部变量 y = 3
```

底层差异（为什么会这样）

* **普通局部变量**：  
    每次函数被调用时，系统会在**栈区**分配内存存放 `x`，函数结束时**弹栈**释放内存，下次调用会重新分配新的空间，所以它的值不会保留。
    
* **静态局部变量**：  
    编译器会把它放在**静态数据区**，这个区域的变量在程序运行期间一直存在。  
    只是编译器会限制它的**作用域**在函数内部（函数外访问不到）。  
    所以即使函数结束，这块内存依然保留数据，下次调用直接用上一次的值。



### 5-16 编译和连接两个步骤的输入、输出分别是什么类型的文件？两个步骤的任务有什么不同？在以下几种情况中，在对程序进行编译、连接时是否会报错？会在哪一个步骤报错？

(1) 定义了一个函数`void f(int x,int y)`，以`f(1)`的形式调用。

(2) 在源文件起始处声明了一个函数`void f(int x)`，但未给出其定义，以`f(1)`的形式调用。

(3) 在源文件起始处声明了一个函数`void f(int x)`，但未给出其定义，也未对其进行调用。

(4) 在源文件a.cpp中定义了一个函数`void f(int x)`，在源文件b.cpp中也定义了一个函数`void f(int x)`，试图将两个源文件编译后连接在一起。

解：编译的输入文件是源文件，输出是目标文件；连接的输入文件是目标文件，输出是可执行文件。

编译器对源代码进行编译，是将以文本形式存在的源代码翻译为机器语言形式的目标文件的过程。连接是将各个编译单元的目标文件和运行库当中被调用过的单元加以合并后生成的可执行文件的过程。

(1) 编译时报错，函数参数不匹配。

(2) 连接错误，函数未定义。

(3) 不报错。

(4) 连接错误，函数重复定义



