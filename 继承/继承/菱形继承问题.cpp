#include<iostream>
#include<string>

using namespace std;
#if 0
/*
	�̳е����ַ�ʽ :
		1.���̳�
		2.��̳�
		3.���μ̳�

			Person
			||   ||
		Teacher  Student
			||   ||
			Assiant
	���μ̳��Ƕ�̳е�һ���������
	���μ̳г�������Ч���ݵ�������,�Ͷ����Ե�����,��Assiant��Ա�й���Person�����ݻ�������



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
	int  _id;			//ְ�����
};
class Assiant :public Student, public Teacher{
protected:
	string _majorCourse;
};
void Test(){
	Assiant test;
	//���ڶ�����,���ʵĵ������ĸ�������Ĳ���ȷ
	//_name._name;


	//�����Ϳ��Խ������Ķ�����,�������ݵ������Բ�û�еõ����
	//����������������̳мȿ��Խ������
	//ʹ��virtual�ȿ��Խ����������,���ݾͶ���ͳһ��5
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
