#include<iostream>
using namespace std;

class Cat
{
public:
    Cat(int age):itsAge(age){}
    int getNumOfCats();
private:
    static int numOfCats;
    int itsAge;
};