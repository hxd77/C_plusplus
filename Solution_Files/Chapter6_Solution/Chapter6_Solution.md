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



### 6-6 运算符"*"和"&"的作用是什么？

解：*称为指针运算符，是一个一元操作数符，表示指针所指向的对象的值；&称为取地址运算符，也是一个一元操作符，是用来得到一个对象的地址。



### 6-7 什么叫做指针？指针中存储的地址和这个地址中的值有何区别?

解：指针是一种数据类型，具有指针类型的变量称为指针变量。指针

变量存放的是另一个对象的地址，这个地址中的值就是另一个对象的内容。



### 6-8 声明一个int型指针，用new语句为其分配包含10个元素的地址空间。

解：源程序：

```cpp
int *pInteger=new int [10];
```



### 6-9 在字符串"Hello，world！"中，结束符是什么？

解：是'\0'字符。



### 6-10 声明一个有5个元素的int型数组，在程序中提示用户输入元素值，最后再在屏幕上显示出来。

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





### 6-11 引用和指针有何区别？何时只能使用指针而不能使用引用？

解：引用是一个别名，不能为NULL值，不能被重新分配；指针是一个存放地址的变量。当需要对变量重新赋值以另外的地址或赋值为NULL时只能使用指针。



### 6-12 声明下列指针：float类型变量的指针pfloat，char类型的指针pstr和struct Customer型的指针pcus。

解：

```c++
float *pfloat;
char *pstr;
struct customer*pcus;
```



### 6-13 给定float类型的指针fp，写出显示fp所指向的值的输出流语句。

解：

```c++
cout<<"Value=="<<*fp;
```



### 6-14 在程序中声明一个double类型变量的指针，分别显示指针占了多少字节和指针所指的变量占了多少字节。

解：

```c++
double *counter;
cout<<"\nSize of pointer=="<<sizeof(counter);
cout<<"\nSize of addressed value=="<<sizeof(*counter);
```



