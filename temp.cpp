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