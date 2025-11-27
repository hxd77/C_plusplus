#include<iostream>
#include<string>
using namespace std;

class MyString{
public:
	MyString();
	MyString(const char*str);
	MyString(const MyString&s);
	~MyString();

	char &operator[](unsigned short offset);//返回引用可以修改数据，适用于非const对象
	char operator[](unsigned short offset)const;//返回char型，不可以修改数据适用于const常对象
	MyString operator+(const MyString&s);
	void operator+=(const MyString&s);
	MyString &operator=(const MyString&s);//重载=号

	unsigned short getLen()const{
		return itsLen;
	}
	const char*getMyString() const {
		return itsMyString;
	}
private:
	MyString(unsigned short s);//私有构造函数体
	char *itsMyString;
	unsigned short itsLen;
};

MyString::MyString