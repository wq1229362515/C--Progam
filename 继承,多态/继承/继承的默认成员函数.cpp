#if 0
#include<iostream>
#include<string>
using namespace std;
/*
	����Ĭ�ϵĺ�����:
	����,����(��ɶ���Ĵ���������)
	����(����������ʹ��ͬ�������б�����ĳ�ʼ����������)
	��ֵ(��ɶ���֮����໥��ֵ)
	ȡ��ַ(ȡ��ַ��Ҫ����ͨ�����const�����ȡ��ַ����)
	����(���е��Ƕ��������������)
*/

/*
	ʹ�����޷����̳е�����:

		1.final ��һ��������Ĺؼ���,����������ʹ���޷����̳�
		  class Person final{};



*/

class NoInherit{
public:
	//��Ϊ�㽫���캯��˽�л�֮��,���޷������Ĵ�����,�������Ҫ���һ����Ĵ���
	//���Ǿ���Ҫ����һ���ӿ�,�������������ӵķ���������캯��.
	//���������������ͱ�����һ����̬�ĺ���,
	//����Ļ����ǲ�����ɶ���������ķ���,��Ϊ����û��ֱ�Ӷ���һ����
	static NoInherit GetInstance(){
		return NoInherit();
	}
	

private:
	//�����캯����˽�л�,��������ò�������Ĺ��캯��,��ô���޷��̳�
	NoInherit(){
	}
};
class Test :public NoInherit{

};



 class Person {
 public:
	
	Person(){
		cout << "Preson create" << endl;
	}

	Person(const string name, int age) :_name(name), _age(age) {
		cout << "Preson()" << endl;
	}
	//Person �Ŀ������캯��
	Person(const Person& per):_age(per._age),_name(per._name){
		cout << "Preson(const Preson& per)" <<  endl;
	}
	~Person(){
		cout << "~Person()" << endl;
	}

public:
	int _age;
	string _name;
};

class Student :public Person{

public:
	//�̳��˸���ĳ�Ա,��ô��Ҫ���õ�ʱ����û���Ĺ��캯��,����ʼ���������һ����,�������û��Ĭ�ϵ�
	//���캯��,������������๹�캯���ĳ�ʼ���б�׶���ʾ����.������صĲ���Ӧ��������������.
	//�������Ǹ���Ķ���,�ȵ����Ķ��Ĺ��캯��,���๹�캯����������ĳ�ʼ���б�

	//����ֱ���ڲ����б���ֱ��д��_name(name)���ַ�ʽ��,��Ϊ_name����,�����ڻ���ĳ�Ա,����Ҫ�ڻ����
	//���캯����ȥ������ֳ�ʼ��.
	//Student(string name,int age,int num):
	//	Person(name,age)
	//	,_num(num){
	//}
	Student(){
		cout << "Student create" << endl;
	}
	Student(const string& name, int age,int num) :
		Person(name,age)
		,_num(num)
	{
		cout << "Student()" << endl;
	}
	//����п�������,��ô�͹��캯��Ҳһ��,ҲҪ�ڳ�ʼ���б�������û���Ŀ������캯��
	//�����ʾ�ĵ��������������Ļ�,��ô�������Ĭ�ϵĹ��캯��
	Student(const Student& stu) :Person(stu) ,_num(stu._num)
	{
		cout << "Student(const Student& stu)" << endl;
	}
	//�ڽ�������������ʱ��,��������������������������������,�������û���Ĺ��캯��
	//���������������һ��call Person::~Person()
	
	~Student(){
		cout << "~Student()" << endl;
	}
protected:
	int _num;	//ѧ��
};
void Test(){
	Student stu1("Li",18,001);
}
int main(){
	
	Test();

	NoInherit Test1 = NoInherit::GetInstance();

	return 0;

}
#endif
