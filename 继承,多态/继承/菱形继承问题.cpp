#if 0
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
	//使用virtual既可以解决这种问题,数据也会统一了
	test.Student::_name = "Li";
	test.Teacher::_name = "Wang";
}
int main(){

	Test();


	return 0;
}
#endif

/*
	使用菱形虚拟继承,这样避免了数据的冗余

*/
class A {
public:
	int _a;
};

class B :  virtual public A {
public:
	int _b;
};

class C :virtual public A {
public:
	int _c;
};

class D : public B, public C {
public:
	int _d;
};

/*
	使用普通的菱形继承
0x007EFAF0  01 00 00 00  ....
0x007EFAF4  03 00 00 00  ....
0x007EFAF8  02 00 00 00  ....
0x007EFAFC  04 00 00 00  ....
0x007EFB00  05 00 00 00  ....

使用菱形继承就可以解决数据冗余的问题,因为虚基表指针的缘故,指向了虚基表,可以定位数据冗余距离自己的位置
通过这个位置,在修改内容的时候,就可以通过指针来操作,最终找到这个数据冗余的位置,从而修改

通过我们的 类名:成员变量可以解决数据二义性的问题,
通过virtual 则可以将二义性和数据冗余都给解决掉
*/
void Test2(){
	D d;
	d.C::_a = 2;
	d.B::_a = 1;
	d._b = 3;
	d._c = 4;
	d._d = 5;
}
int main() {

	Test2();
	return 0;
}
#endif
