#if 0
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
	//ʹ��virtual�ȿ��Խ����������,����Ҳ��ͳһ��
	test.Student::_name = "Li";
	test.Teacher::_name = "Wang";
}
int main(){

	Test();


	return 0;
}
#endif

/*
	ʹ����������̳�,�������������ݵ�����

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
	ʹ����ͨ�����μ̳�
0x007EFAF0  01 00 00 00  ....
0x007EFAF4  03 00 00 00  ....
0x007EFAF8  02 00 00 00  ....
0x007EFAFC  04 00 00 00  ....
0x007EFB00  05 00 00 00  ....

ʹ�����μ̳оͿ��Խ���������������,��Ϊ�����ָ���Ե��,ָ���������,���Զ�λ������������Լ���λ��
ͨ�����λ��,���޸����ݵ�ʱ��,�Ϳ���ͨ��ָ��������,�����ҵ�������������λ��,�Ӷ��޸�

ͨ�����ǵ� ����:��Ա�������Խ�����ݶ����Ե�����,
ͨ��virtual ����Խ������Ժ��������඼�������
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
