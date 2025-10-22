# 第七章习题解答
## 7-1 比较类的三种继承方式public（公有继承）、proteced（保护继承）、private（私有继承）之间的差别。

解：不同的继承方式，导致不同访问属性的基类成员在派生类中的访问属性也有所不同：

公有继承，使得基类public（公有）和protected（保护）成员的访问属性都已在派生类中不变，而基类private（私有）成员不可访问。

私有继承，使得基类public（公有）和protected（保护）成员都以private（私有）成员身份出现在派生类中，而基类private（私有）成员不可访问。

保护继承中，基类public（公有）和protected（保护）成员都已protected（保护）成员身份出现在派生类中，而基类private（私有）成员不可访问。



## 7-2 派生类构造函数执行的次序是怎样的？

解：派生类构造函数执行的一般次序为：调用基类构造函数；调用成员对象的构造函数；调用派生类的构造函数体中的内容。



## 7-3 如果派生类B已经重载了基类A的一个成员函数fn1()，没有重载基类的成员函数fn2()，如何在派生类中调用基类的成员函数fn1()，fn2()？

解：调用方法为：

```c++
A::fn1();
fn2();
```



## 7-4 什么叫做虚基类？它有何作用？

解：当某类的部分或全部直接基类是从另一个基类派生而来，这些直接基类中，从上一个基类继承来的成员就拥有相同的名称，派生类对象的这些同名成员在内存中同时拥有多个拷贝，我们可以使用作用域分辨符来唯一标识并分别访问它们。我们也可以将直接基类的共同基类设置为虚基类，这是从不同的路径继承过来的该类成员在内存中只拥有一个拷贝，这样就解决了同名成员的唯一标识问题。

虚基类的声明实在派生类的声明过程中，其语法格式为：

`class 派生类名: virtual 继承方式 基类名`

上述语句声明基类为派生类的虚基类，在多继承情况下，虚基类关键字的作用范围和继承方式关键字相同，只对紧跟其后的基类起作用。声明了虚基类之后，虚基类的成员在进一步派生过程中，和派生类一起维护一个内存数据拷贝。



## 7-5 定义一个基类Shape，在此基础上派生出Rectangle和Circle，二者都有getArea()函数计算对象的面积。使用Rectangle类创建一个派生类Square。

解：源程序：

```cpp
#include<iostream>
using namespace std;
class Shape{
public:
	Shape(){};
	~Shape(){}
	virtual float getArea(){return -1;}	//将这个函数声明为虚函数，则可以通过基类的指针指向派生类的对象，并访问某个与基类同名的成员
};

class Circle:public Shape
{
public:
	Circle(float radius):itsRadius(radius){}
	~Circle(){}
	float getArea(){return 3.14*itsRadius*itsRadius;}
	private:
	float itsRadius;
};

class Rectanle:public Shape{
public:
	Rectanle(float len,float width):itsLength(len),itsWidth(width){}
	~Rectanle(){};
	virtual float getArea(){return itsLength*itsWidth;}
	virtual float getWidth(){return itsWidth;}
	virtual float getLength(){return itsLength;}
private:
	float itsWidth;
	float itsLength;
};

class Square:public Rectanle{
public:
	Square(float len);
	~Square(){}
};

Square::Square(float len):Rectanle(len,len)//正方形
{
	//Rectanle(len,len);
	/*在 C++ 中，子类对象的父类部分在构造函数开始前就必须初始化，不能在构造函数体里再去“调用父类构造函数*/
}

int main()
{
	Shape*sp;
	sp=new Circle(5);//类型兼容规则
	cout<<"The area of the Circle is " <<sp->getArea()<<endl;
	delete sp;
	sp=new Rectanle(4,6);
	cout<<"The area of the Rectanle is "<<sp->getArea()<<endl;
	delete sp;
	sp=new Square(5);
	cout<<"The area of the Square is "<<sp->getArea()<<endl;
	delete sp;
	
	return 0;
	
}
```





## 7-6 定义一个哺乳动物类Mammal，再有此派生出狗类Dog，定义一个Dog类的对象，观察基类与派生类的构造函数与析构函数的调用顺序

解：源程序：

```c++
#include<iostream>
using namespace std;
enum myColor{BLACK,WHITE};
class Mammal{
public:
	//constructors
	Mammal();
	~Mammal();

	//accessors
	int getAge() const{
		return itsAge;
	}
	void setAge(int age)
	{
		itsAge=age;
	}
	int getWeight() const
	{
		return itsWeight;
	}
	void setWeight(int weight)
	{
		itsWeight=weight;
	}
	//other methods
	void speak()const{
		cout<<"Mammal sound!\n";
	}
protected:
	int itsAge;
	int itsWeight;
};

class Dog:public Mammal
{
public:
	Dog();
	~Dog();

	myColor getColor() const{
		return itsColor;
	}
	void setColor(myColor color)
	{
		itsColor=color;
	}
	void wagTail()
	{
		cout<<"Tail waggling...\n";
	}
private:
	myColor itsColor;
};

Mammal::Mammal():itsAge(1),itsWeight(5){
	cout<<"Mammal constructor...\n";
}

Mammal::~Mammal(){
	cout<<"Mammal destructor...\n";
}

Dog::Dog():itsColor(WHITE){
	cout<<"Dog constructor...\n";
}

Dog::~Dog(){
	cout<<"Dog deconstructor...\n";
}

int main()
{
	Dog jack;
	jack.speak();
	jack.wagTail();
	cout<<" jack is "<<jack.getAge()<<" years old\n";
	return 0;
}
```

程序运行输出：

```
Mammal constructor...
Dog constructor...
Mammal sound!
Tail waggling...
 jack is 1 years old
Dog deconstructor...
Mammal destructor...
```



## 7-7 定义一个基类及其派生类，在构造函数中输出提示信息，构造派生类的对象，观察构造函数的执行情况。

