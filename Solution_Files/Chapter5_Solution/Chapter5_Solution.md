# ������ϰ����


### 5-1 ʲô�������������ļ������͵�������

�⣺���������۵��Ǳ�ʶ������Ч��Χ����������һ����ʶ���ڳ�����������Ч������C++���������Ϊ����**ԭ�������򡢿������򣨾ֲ������򣩡�����������ļ�������**



### 5-2 ʲô�����ɼ��ԣ��ɼ��Ե�һ�������ʲô��

�⣺�ɼ����Ǳ�ʶ���Ƿ�������õ����⡣

�ɼ��Ե�һ������ǣ���ʶ��Ҫ������ǰ�������ں���ͬһ�������У���������**ͬ���ı�ʶ�ı�ʶ��**�������ڲ�ͬ�������������ı�ʶ������ѭ�Ĺ����ǣ�**���������������а�����ϵ����������������ı�ʶ��������ڲ�û������ͬ����ʶ��ʱ�Կɼ�������ڲ�������ͬ����ʶ��������ʶ�����ɼ���**



### 5-3 ����ĳ������н����ʲô��ʵ������һ�£���������������кβ�ͬ��

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

�⣺�������������

```c++
x from main: 5
y from main: 7
x from myFunction: 5
y from myFunction: 10

Back from myFunction!

x from main: 5
y from main: 7
```

>��myFuncton����֮�⣬�������þ����ļ�������ı������ɾ��ǿɼ��ġ������������myFunction֮�󣬾�ֻ�����þ��оֲ��������ͬ�������������ļ��������ͬ�����������صġ�



### 5-4 �����������޹�ϵ����Engine��Fuel��ʹ��ʱ����������Fuel��Ա����Engine�е�˽�кͱ����ĳ�Ա?

�⣺Դ����

```c++
class fuel;
class engine
{
	friend class fuel;	//fuel����engine�����Ԫ��
	private:
		int powerlevel;
	public:
		engine(){powerlevel=0;}
		void engine_fn(fuel &f);
};
class fuel
{
    friend class engine;	//engine����fuel�����Ԫ��
    private:
    	int fuelLevel;
   	public:
    	fuel(){fuelLevel=0;}
    	void fuel_fn(engine &e);
};
```

>������Ԫ���������ԣ���Ԫ������һ����ͨ�ĺ�����Ҳ������������ĳ�Ա��������Ȼ�����Ǳ���ĳ�Ա���������������ĺ������п���ͨ���������������˽�кͱ�����Ա��



### 5-5 ʲô������̬���ݳ�Ա�����к��ص㣿

�⣺��ľ�̬���ݳ�Ա��������ݳ�Ա��һ������������static�ؼ��������������������ͨ���ݳ�Ա��ÿһ����Ķ���ӵ��һ�ݴ洢������˵ÿ�������ͬ�����ݳ�Ա���Էֱ�洢��ͬ����ֵ����Ҳ�Ǳ�֤����ӵ�����������������������������Ҫ�����Ǿ�̬���ݳ�Ա��ÿ����ֻҪһ�ݴ洢�������и���Ķ���ͬά����ʹ�ã������ͬά����ʹ��Ҳ��ʵ����ͬһ��Ĳ�ͬ��������ݹ���



### 5-6 ʲô������̬������Ա�����к��ص㣿

�⣺ʹ��static�ؼ��������ĺ�����Ա�Ǿ�̬�ģ���̬������Ա���������࣬ͬһ��������ж���ͬά����Ϊ��Щ������������̬������Ա����������������ĺô���һ�����ھ�̬��Ա����ֻ�ܷ���ͬһ����ľ�̬���ݳ�Ա�����Ա�֤����Ը�����������ݳ�Ա��ɸ���Ӱ�죻����ͬһ����ֻά��һ����̬������Ա�Ŀ�������Լ��ϵͳ�Ŀ�������߳��������Ч�ʡ�



### 5-7 ����һ��Cat�࣬ӵ�о�̬���ݳ�ԱnumOfCats����¼Cat�ĸ�����Ŀ����̬��Ա����getNumOfCats()����ȡnumOfCats����Ƴ����������࣬��ᾲ̬���ݳ�Ա�;�̬��Ա�������÷���

�⣺Դ����

```c++
#include<iostream>
using namespace std;

class Cat
{
public:
    Cat(int age):itsAge(age){       //���캯��
        numOfCats++;
    }
    virtual ~Cat(){                 //��������
        numOfCats--;
    }
    virtual int getAge(){
        return itsAge;
    }
    virtual void setAge(int age)
    {
        itsAge=age;
    }
    static int getNumOfCats()       //��̬����
    {  
        return numOfCats;
    }
private:
    static int numOfCats;       //��̬���ݳ�Ա
    int itsAge;
};

int Cat::numOfCats=0;       //��̬���ݳ�Ա�������ʼ��

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

���н����

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



### 5-8 ʲô������Ԫ������ʲô������Ԫ�ࣿ

�⣺��Ԫ������ʹ��friend�ؼ��������ĺ����������Է�����Ӧ��ı�����Ա��˽�г�Ա����Ԫ����ʹ��friend�ؼ����������࣬�������г�Ա����������Ӧ�����Ԫ������

 
