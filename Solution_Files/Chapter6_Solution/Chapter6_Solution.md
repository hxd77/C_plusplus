# 第六章习题解答
## 6-1 数组a\[10]\[5][15]一共有多少个元素？

解：$10\times 5\times 15=750$个元素。



## 6-2 在数组a[20]中第一个元素和最后一个元素是哪一个？

解：第一个元素是a[0]，第二个元素是a[19]。



## 6-3 用一条语句声明一个有5个元素的整型数组，并依次赋予1~5的初值。

解：源程序：
```cpp
int integerArrays[5]={1,2,3,4,5};
```

或

```cpp
int integerArrays[]={1,2,3,4,5};
```



## 6-4 已知有一个数组名为oneArray，用一条语句求出其元素的个数。

解：源程序：

```cpp
int nArrayLength=sizeof(oneArray)/sizeof(oneArray[0]);
```



## 6-5  用一条语句声明一个有$5\times 3$个元素的二维整型数组，并依次赋予1~15的初值。

解：源程序：

```c++
int theArray[5][3]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
```

或

```
int theArray[][]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
```



## 6-6 运算符"*"和"&"的作用是什么？

解：*称为指针运算符，是一个一元操作数符，表示指针所指向的对象的值；&称为取地址运算符，也是一个一元操作符，是用来得到一个对象的地址。



## 6-7 什么叫做指针？指针中存储的地址和这个地址中的值有何区别?

解：指针是一种数据类型，具有指针类型的变量称为指针变量。指针

变量存放的是另一个对象的地址，这个地址中的值就是另一个对象的内容。



## 6-8 声明一个int型指针，用new语句为其分配包含10个元素的地址空间。

解：源程序：

```cpp
int *pInteger=new int [10];
```



## 6-9 在字符串"Hello，world！"中，结束符是什么？

解：是'\0'字符。



## 6-10 声明一个有5个元素的int型数组，在程序中提示用户输入元素值，最后再在屏幕上显示出来。

解：源程序

```c++
#include<iostream>
using namespace std;

int main()
{
	int myArray[5];
	int i;
	for(i=0;i<5;i++)
	{
		cout<<"Value for myArray["<<i<<"]: ";
		cin>>myArray[i];
	}
	for(i=0;i<5;i++)
	{
		cout<<i<<": "<<myArray[i]<<endl;
	}
	return 0;
}
```

程序运行输出：

```
Value for myArray[0]: 2
Value for myArray[1]: 5
Value for myArray[2]: 7
Value for myArray[3]: 8
Value for myArray[4]: 3
0: 2
1: 5
2: 7
3: 8
4: 3
```





## 6-11 引用和指针有何区别？何时只能使用指针而不能使用引用？

解：引用是一个别名，不能为NULL值，不能被重新分配；指针是一个存放地址的变量。当需要对变量重新赋值以另外的地址或赋值为NULL时只能使用指针。



## 6-12 声明下列指针：float类型变量的指针pfloat，char类型的指针pstr和struct Customer型的指针pcus。

解：

```c++
float *pfloat;
char *pstr;
struct customer*pcus;
```



## 6-13 给定float类型的指针fp，写出显示fp所指向的值的输出流语句。

解：

```c++
cout<<"Value=="<<*fp;
```



## 6-14 在程序中声明一个double类型变量的指针，分别显示指针占了多少字节和指针所指的变量占了多少字节。

解：

```c++
double *counter;
cout<<"\nSize of pointer=="<<sizeof(counter);
cout<<"\nSize of addressed value=="<<sizeof(*counter);
```





## 6-15 const int *p1 和 int *const p2的区别是什么？

解：

const int \*p1 声明了一个指向整型常量的指针p1，因此不能通过指针p1来改变它所指向的整型值；int* const p2声明了一个指针型常量，用于存放整型变量的地址，这个指针一旦初始化后，就不能被重新赋值了。



## 6-16 声明了一个int型变量a，一个int型指针p，一个引用r，通过p把a的值改为10，通过r把a的值改为5。

解：

```c++
int a;
int *p=&a;
int &r=a;
*p=10;
r=5;
```



## 6-17 下列程序有何问题？请仔细体会使用指针应避免出现这样的问题。

```c++
#include<iostream>
using namespace std;
int main()
{
    int *p;
    *p=9;
    cout<<"The value at p:	"<<*p;
   	return 0;
}
```

解：指针p没有初始化，也就是没有指向某个确定的内存单元，它指向内存中的一个随机地址，给这个地址赋值是非常危险的。



## 6-18 下列程序有何问题？请改正。仔细体会使用指针时应避免出现这样的问题。

```c++
#include<iostream>
using namespace std;
int fn1();
int main()
{
	int *a=fn1();
    cout<<"the value of a is:	"<<a;
    return 0;
}

int *fn1()
{
    int *p=new int(5);
    return *p;
}
```

解：此程序中给*p分配的内存没有被释放掉。

改正：

```c++
#include<iostream>
using namespace std;
int fn1();
int main()
{
	int *a=fn1();
    cout<<"the value of a is:	"<<a;
    delte a;
    return 0;
    
}

int *fn1()
{
    int *p=new int(5);
    return *p;
}
```





## 6-19 声明一个参数为整型，返回值为长整型的函数指针；声明类A的一个成员函数指针，其参数为整型，返回值为长整型。

解：

```c++
long (*p_fn1)(int);
long (A::*p_fn2)(int);
```



## 6-20 实现一个名为SimpleCircle的简单圆类，其数据成员 int*itsRadius为一个指向其半径值的指针，设计对数据成员的各种操作，给出这个类的完整实现并测试这个类。

解：源程序：

```c++
#include<iostream>
using namespace std;

class SimpleCircle{
public:
	SimpleCircle();
	SimpleCircle(int radius);
	SimpleCircle(const SimpleCircle&rhs);
	~SimpleCircle(){}

	void setRadius(int radius);
	int getRadius()const ;	//常数据成员函数
private:
	int*itsRadius;
};

SimpleCircle::SimpleCircle()
{
	itsRadius=new int (5);
}

SimpleCircle::SimpleCircle(int radius)
{
	itsRadius=new int (radius);
}

SimpleCircle::SimpleCircle(const SimpleCircle&rhs)
{
	int val=rhs.getRadius();
	itsRadius=new int (val);
}

int SimpleCircle::getRadius()const{
	return *itsRadius;
}

int main()
{
	SimpleCircle CircleOne,CircleTwo(9);
	cout<<"CircleOne:	"<<CircleOne.getRadius()<<endl;
	cout<<"CircleTwo:	"<<CircleTwo.getRadius()<<endl;
	return 0;
}
```

程序运行输出：

```c++
CircleOne:      5
CircleTwo:      9
```



## 6-21 编写一个函数，统计一条英文句子中字母的个数，在主程序中实现输入/输出。

解：源程序：

```c++
#include<iostream>
#include<cstdio>
using namespace std;

int count(char*str)
{
	int i,num=0;
	for(i=0;str[i]!=0;i++)
	{
		if(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z')
		{
			num++;
		}
	}
	return num;
}

int main()
{
	char text[100];
	cout<<"输入一个英语句子:	"<<endl;
	gets(text);//读取一整行
	cout<<"这个句子里有"<<count(text)<<"个字母。"<<endl;
}
```

程序运行输出：

```
输入一个英语句子:
It is very interesting!
这个句子里有19个字母。
```



## 6-22 编写函数 void reverse(string&s)，用递归算法使字符串s倒序。

解：源程序：

```c++
#include<iostream>
#include<string>
using namespace std;

string reverse(string&str)
{
	if(str.length()>1)
	{
		string sub =str.substr(1,str.length()-2);//取中间字串，去除首尾 substr参数表示起始位置和长度
		return str.substr(str.length()-1,1)+reverse(sub)+str.substr(0,1);//末尾+翻转中间+首字符
	}
	else
	{
		return str;
	}
}

int main()
{
	string str;
	cout<<"输入一个字符串:	";
	cin>>str;
	cout<<"原字符串为:	"<<str<<endl;
	cout<<"倒序反转后为:	"<<reverse(str)<<endl;
	return 0;
}
```

程序运行输出：

```
输入一个字符串: abcdefghijk
原字符串为:     abcdefghijk
倒序反转后为:   kjihgfedcba
```



## 6-23 设学生人数为N=8，提示用户输入N个人的考试成绩，然后计算他们的平均成绩并显示出来。

解：源程序：

```c++
#include<iostream>
#include<string>
using namespace std;

#define N 8
float grades[N];	//存放成绩的数组

int main()
{
	int i;
	float total,average;

	//提示输入成绩
	for(i=0;i<N;i++)
	{
		cout<<"Enter grade #"<<(i+1)<<": ";
		cin>>grades[i];
	}

	total=0;
	for(i=0;i<N;i++)
	{
		total+=grades[i];
	}
	average=total/N;
	cout<<"\nAverage grade:	"<<average<<endl;
	return 0;
}
```

程序运行输出：

```
Enter grade #1: 86
Enter grade #2: 98
Enter grade #3: 67
Enter grade #4: 80
Enter grade #5: 78
Enter grade #6: 95
Enter grade #7: 78
Enter grade #8: 56

Average grade:  79.75
```



## 6-24 基于char*设计一个字符类MyString，具有构造函数、析构函数、拷贝构造函数、重载运算符“+”，“+=”，“=”，“[]”，尽可能完善它，使之能满足各种需要。

解：源程序如下：

```c++
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

class MyString{
public:
	MyString();
	MyString(const char*const cMyString);//双常量，常量字符的常量指针
	MyString(const MyString&rhe);
	~MyString();

	char &operator[](unsigned short offset);//返回引用可以修改数据，适用于非const对象
	char operator[](unsigned short offset)const;//返回char型，不可以修改数据适用于const常对象
	MyString operator+(const MyString&s);
	void operator+=(const MyString&s);
	MyString & operator=(const MyString&s);//重载=号，在自身字符串上修改

	unsigned short getLen()const{
		return itsLen;
	}
	const char*getMyString() const {
		return itsMyString;
	}
private:
	MyString(unsigned short len);//私有构造函数体
	char *itsMyString;
	unsigned short itsLen;
};

MyString::MyString()
{
	itsMyString=new char[1];
	itsMyString[0]='\0';
	itsLen=0;
}

MyString::MyString(unsigned short len)//私有构造函数
{
	itsMyString=new char [len+1];
	for(unsigned short i=0;i<=len;i++)
	{
		itsMyString[i]='\0';
	}
	itsLen=len;
}

MyString::MyString(const char*const cMyString)
{
	itsLen=strlen(cMyString);
	itsMyString=new char [itsLen+1];
	for(unsigned short i=0;i<itsLen;i++)
	{
		itsMyString[i]=cMyString[i];
	}
	itsMyString[itsLen]='\0';
}

MyString::MyString(const MyString &rhs)//复制构造函数
{
	itsLen=rhs.getLen();
	itsMyString=new char[itsLen+1];
	for(unsigned short i=0;i<itsLen;i++)
	{
		itsMyString[i]=rhs[i];
	}
	itsMyString[itsLen]='\0';
}

MyString::~MyString()
{
	delete [] itsMyString;
	itsLen=0;
}

/*按值返回）
❌ 问题 1：性能差

按值返回意味着：

会调用拷贝构造函数

会生成一个临时对象

可能再次分配内存

这是 完全多余的。

❌ 问题 2：无法链式赋值*/
MyString& MyString::operator=(const MyString&rhs)	//重载=号，在自身字符串上修改
{
	if(this==&rhs)//如果当前对象和rhs指向同一块对象
	{
		return *this;
	}
	delete[]itsMyString;//先删除原有的字符串
	itsLen=rhs.getLen();
	itsMyString=new char[itsLen+1];
	for(unsigned short i=0;i<itsLen;i++)
	{
		itsMyString[i]=rhs[i];
	}
	itsMyString[itsLen]='\0';
	return *this;
}

//第一个返回引用，允许修改；第二个返回值，是只读版本，用于 const 对象。
char & MyString::operator[](unsigned short offset)
{
	if(offset>itsLen)
	{
		return itsMyString[itsLen-1];
	}
	else
		return itsMyString[offset];
}

char MyString::operator[](unsigned short offset)const
{
	if(offset>itsLen)
	{
		return itsMyString[itsLen-1];
	}
	else
		return itsMyString[offset];
}

MyString MyString::operator+(const MyString&rhs)
{
	unsigned short totalLen=itsLen+rhs.getLen();
	MyString temp(totalLen);
	unsigned short i=0;
	for(i=0;i<totalLen;i++)
	{
		temp[i]=itsMyString[i];
	}
	for(unsigned short j=0;j<rhs.getLen();j++,i++)
	{
		temp[i]=rhs[i-itsLen];
	}
	temp[totalLen]='\0';
	return temp;
}

void MyString::operator+=(const MyString&rhs)
{
	unsigned short rhsLen=rhs.getLen();
	unsigned short totalLen=itsLen+rhsLen;
	MyString temp(totalLen);
	unsigned short i=0;
	for(i=0;i<itsLen;i++)
	{
		temp[i]=itsMyString[i];
	}
	for(unsigned short j=0;j<rhs.getLen();j++,i++)
	{
		temp[i]=rhs[i-itsLen];
	}
	temp[totalLen]='\0';
	*this=temp;
}

int main()
{
	MyString s1("initial test");
	cout<<"S1:	\t"<<s1.getMyString()<<endl;

	const char*temp="Hello World";//先自动转为 MyString(temp)，再调用 operator=
	s1=temp;
	cout<<"S1:	\t"<<s1.getMyString()<<endl;

	char tempTwo[20];
	strcpy(tempTwo,";	nice to be here!");
	s1+=tempTwo;//也是先自动转为MyString(tempTwo),在调用operator+=
	cout<<"tempTwo:	\t"<<tempTwo<<endl;
	cout<<"S1:	\t"<<s1.getMyString()<<endl;

	cout<<"S1[4]:	\t"<<s1[4]<<endl;//调用引用的[],可以修改值
	s1[4]='x';
	cout<<"S1:	\t"<<s1.getMyString()<<endl;
	
	cout<<"S1[999]:	\t"<<s1[999]<<endl;

	MyString s2("Another myString");
	MyString s3;
	s3=s1+s2;
	cout<<"S3:	\t"<<s3.getMyString()<<endl;
	MyString s4;
	s4="Why does this work?";
	cout<<"S4:	\t"<<s4.getMyString()<<endl;
	return 0;
}
```

程序运行输出结果：

```
S1:             initial test
S1:             Hello World
tempTwo:                ;       nice to be here!
S1:             Hello World;    nice to be here!
S1[4]:          o
S1:             Hellx World;    nice to be here!
S1[999]:                !
S3:             Hellx World;    nice to be here!
S4:             Why does this work?
```



## 6-25 编写一个3$\times$3矩阵转置的函数，在main()函数中输入数据。

解：源程序如下：

```c++
#include<iostream>
using namespace std;

void move(int matrix[3][3])
{
	int i,j,k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<i;j++)
		{
			k=matrix[i][j];
			matrix[i][j]=matrix[j][i];
			matrix[j][i]=k;
		}
	}
}

int main()
{
	int i,j;
	int data[3][3];
	cout<<"输入矩阵的元素"<<endl;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<"第"<<i+1<<"行第"<<j+1<<"个元素为:	";
			cin>>data[i][j];
		}
	}
	cout<<"输入的矩阵为:	"<<endl;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<data[i][j]<<" ";
		}
		cout<<endl;
	}
	move(data);
	cout<<"转置后的矩阵为:	"<<endl;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<data[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
```

程序运行输出：

```
输入矩阵的元素
第1行第1个元素为:       1
第1行第2个元素为:       2
第1行第3个元素为:       3
第2行第1个元素为:       4
第2行第2个元素为:       5
第2行第3个元素为:       6
第3行第1个元素为:       7
第3行第2个元素为:       8
第3行第3个元素为:       9
输入的矩阵为:
1 2 3 
4 5 6 
7 8 9 
转置后的矩阵为:
1 4 7 
2 5 8 
3 6 9 
```



## 6-26 编写一个矩阵转置的函数，矩阵的行数和列数在程序中由用户输入。

解：源程序如下：

```c++
#include<iostream>
using namespace std;
void move(int *matrix,int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			k=*(matrix+i*n+j);
			*(matrix+i*n+j)=*(matrix+j*n+i);
			*(matrix+j*n+i)=k;
		}
	}
}

int main()
{
	int n,i,j;
	int *p;
	cout<<"请输入矩阵的行、列数:	"<<endl;
	cin>>n;
	p=new int[n*n];
	cout<<"输入矩阵的元素"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<"第"<<i+1<<"行第"<<j+1<<"个元素为:	";
			cin>>p[i*n+j];
		}
	}
	cout<<"输入的矩阵为:	"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<p[i*n+j]<<"	";
		}
		cout<<endl;
	}
	move(p,n);
	cout<<"转置后的矩阵为:	"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<p[i*n+j]<<"	";
		}
		cout<<endl;
	}
	return 0;
}
```

程序运行输出：

```
请输入矩阵的行、列数:
4
输入矩阵的元素
第1行第1个元素为:       1
第1行第2个元素为:       2
第1行第3个元素为:       3
第1行第4个元素为:       4
第2行第1个元素为:       5
第2行第2个元素为:       6
第2行第3个元素为:       7
第2行第4个元素为:       8
第3行第1个元素为:       9
第3行第2个元素为:       10
第3行第3个元素为:       11
第3行第4个元素为:       12
第4行第1个元素为:       13
第4行第2个元素为:       14
第4行第3个元素为:       15
第4行第4个元素为:       16
输入的矩阵为:
1       2       3       4
5       6       7       8
9       10      11      12
13      14      15      16
转置后的矩阵为:
1       5       9       13
2       6       10      14
3       7       11      15
4       8       12      16
```



## 6-27 定义一个Employee类，其中包括表示姓名、地址、城市和邮编等属性，包括setName()和display()函数。display()使用cout语句显示姓名、地址、城市和邮编等属性，函数setName()改变对象的姓名属性，实现并测试这个类。

解：源程序：

```c++
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

class Employee
{
private:
	char name[30];
	char street[30];
	char city[30];
	char zip[6];
public:
	Employee(char*n,char*str,char*ct,char*z);
	void setName(char*n);
	void display();
};

Employee::Employee(char*n,char*str,char*ct,char*z)
{
	strcpy(name,n);
	strcpy(street,str);
	strcpy(city,ct);
	strcpy(zip,z);
}

void Employee::setName(char*n)
{
	strcpy(name,n);
}

void Employee::display()
{
	cout<<name<<"\t"<<street<<"\t";
	cout<<city<<"\t"<<zip;
}

int main()
{
	Employee e1("张三","平安大街3号","北京","100000");
	e1.display();
	cout<<endl;
	e1.setName("李四");
	e1.display();
	cout<<endl;
	return 0;
}
```

程序运行输出：

```
张三    平安大街3号     北京    100000
李四    平安大街3号     北京    100000
```



## 6-28 分别将例6-10和例6-16程序中对指针的所有使用都改写成为与之等价的引用形式，比较修改后的程序，体会在哪些情况下使用指针更好，哪些情况下使用引用更好。

解：源程序如下：

```cpp
//6-10.cpp
#include<iostream>
using namespace std;

//将实数x分成整数部分和小数部分，形参intpart、fracpart是引用
void splitFloat(float x,int &intPart,float &fracPart)
{
	intPart=static_cast<int>(x);	//取x的整数部分
	fracPart=x-intPart;				//取x的小数部分
}

int main()
{
	cout<<"Enter 3 float point numbers:	"<<endl;
	for(int i=0;i<3;i++)
	{
		float x,f;
		int n;
		cin>>x;
		splitFloat(x,n,f);		//变量地址作为实参
		cout<<"Integer Part="<<n<<" Fraction Part="<<f<<endl;
	}
	return 0;
}
```

程序运行输出：

```
Enter 3 float point numbers:
4.7
Integer Part=4 Fraction Part=0.7
8.913
Integer Part=8 Fraction Part=0.913
-4.7518
Integer Part=-4 Fraction Part=-0.7518
```

源程序如下：

```c++
//6-16.cpp
#include<iostream>
using namespace std;
class Point{
public:
	Point():x(0),y(0)
	{
		cout<<"Default Constructor called."<<endl;
	}
	Point(int x,int y):x(x),y(y)
	{
		cout<<"Constructor called."<<endl;
	}
	~Point(){}
	int getX()const{return x;}
	int getY()const{return y;}
	void move(int newX,int newY)
	{
		x=newX;
		y=newY;
	}
private:
	int x,y;
};

int main()
{
	cout<<"Step one:"<<endl;
	Point&ptr1=*new Point;	//动态创建对象，没有给出参数列表，因此调用缺省构造函数
	delete &ptr1; //ptr1是对象引用，取地址&得到Point* 删除对象，自动调用析构函数
	cout<<"Step two:"<<endl;
	ptr1=*new Point(1,2);	//动态创建对象，并给出参数列表，因此调用有形参的构造函数
	delete &ptr1;
	return 0;
}
```

程序输出如下：

```
Step one:
Default Constructor called.
Step two:
Constructor called.
```



## 6-29 运行下面的程序，观察执行结果，指出该程序是如何通过指针造成安全性的？思考如何避免这种情况发生：

```c++
#include<iostream>
using namespace std;
int main()
{
	int arr[]={1,2,3};
	double *p=reinterpret_cast<double*>(&arr[0]);//reinterpret_cast可以将一种类型的指针转化为另一种类型指针
	*p=5;
	cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
	return 0;
}
```

解：在32位平台下，一般int是4个字节，double是8个字节，reinterpret_cast是和static_cast并列的一种类型转换操作符，它可以将一种类型的指针转化为另一种类型的指针，这里把int*类型的&arr[0]转化为float\*类型。无论是int型还是float型的指针，存储的都是一个地址，它们的区别只是相应地址中的数据被解释为不同类型而已。代码第5、6行强制转换后的赋值过程中，给double指针赋值，操作的是double变量，内存覆盖前两个 int修改了arr[0],arr[1]的内存空间，因此导致arr[1]的非预期输出。避免这种情况的措施：

1. 尽量避免使用类型转化。
2. 必须使用类型转换时，尽量开辟新的内存空间，在新内存空间中完成转换。
3. 必须使用原有内存空间时，要特别注意各种数据类型在不同平台下的内存占用大小。



## 6-30 static_cast、const_cast和reinterpret_cast各自应在哪种情况下使用？

解：static_cast运算符实现类型间的转换，但没有运行时类型检查来保证转换的安全性。

const_cast运算符用来修改类型的const或volatic属性。可以去除对象或变量的const或volatic属性。

reinterpret_cast可以把一个指针转换成一个整数，也可以把一个整数转换为一个指针。

