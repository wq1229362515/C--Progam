#include<iostream>
#include<string>

using namespace std;
#if 0
/*
	继承的三种方式 :
		1.单继承
		2.多继承
		3.菱形继承

			Person
			||   ||
		Teacher  Student
			||   ||
			Assiant
	菱形继承是多继承的一种特殊情况
	菱形继承出现了有效数据的冗余性,和二义性的问题,在Assiant成员中关于Person的数据会有两份



*/
class Person{
public:
	string _name;
};
class Student:virtual public Person{
protected:
	int _num;
};
class Teacher:virtual public Person{
protected:
	int  _id;			//职工编号
};
class Assiant :public Student, public Teacher{
protected:
	string _majorCourse;
};
void Test(){
	Assiant test;
	//存在二义性,访问的到底是哪个类里面的不明确
	//_name._name;


	//这样就可以解决代码的二义性,但是数据的冗余性并没有得到解决
	//关于这种问题虚拟继承既可以解决问题
	//使用virtual既可以解决这种问题,数据就都会统一了5
	test.Student::_name = "Li";
	test.Teacher::_name = "Wang";
}
int main(){

	Test();


	return 0;
}
#endif

class A {
public:
	int _a;
};

class B : virtual public A {
public:
	int _b;
};

class C : virtual public A {
public:
	int _c;
};

class D : public B, public C {
public:
	int _d;
};

int main() {
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;

	return 0;
}
