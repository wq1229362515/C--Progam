#if 0
#include<iostream>
#include<string>
using namespace std;



/*
	�̳�������Ʋ�εĸ���,�ڱ���ԭ��(����)���ԵĻ����϶��������չ,���ӹ���,��������Ϊ������
*/

class Person{
public:

	Person(){
	}
	Person(const string name  ,int age ,int num):_name(name),_age(age),_num(num){
	}
	void print(){
		cout << "����: " << _age << endl;
		cout << "����: " << _name << endl;
	}

	public:
	int _age ;
	string _name ;
	int _num;			//id����
};
/*
	�ڽ��м̳е�ʱ��,�̳еķ�ʽҲ��ʮ�ֵ���Ҫ,Ĭ�ϵļ̳з�ʽ��˽�еļ̳�,��ô��Ͳ�������������������
	������κ���Ϣ.�����������������������е����Ի��߷���
	ѡ�񱣻��ķ�ʽ�̳�,�Ͳ����������������������Щ����,�Լ�����
	ѡ���еļ̳�,��ô���ڻ����еĳ�Ա�Ͳ���ȥ�����ǲ��ɼ���,�����й��еĲ���,��ô������Ҳ���������һ��
	���ڻ����б����ĳ�Ա���߷���,���������п���ȥ����,���������ⲻ��
	
*/
class Teacher :public Person{
};
class Student:public Person{

public:
	
	void getStudent_info(string name,int age,int num){
		Student::_name = name;
		Student::_age = age;
		_num = num;
	}
	//����ǳ�Ա����������,��ô�ͳ�֮Ϊͬ������
	void print(){
		cout << "����: " << _age << endl;
		cout << "����: " << _name << endl;
		cout << "ѧ��: " << _num << endl;
		cout << "���֤: " << Person::_num << endl;

	}
	

protected:
	//�ͻ����г�Ա��id��������ͬ,��ô����������,��ô���ʵ��������е������Ա
	int _num;	//ѧ��
	
};
int main(){


	Student stu1;
	Person  per1;
	//stu.print();

	stu1.getStudent_info("li", 18, 001);

	//�и�	
#if 0
	/*
		�ڽ��и�ֵת����ʱ��,������Ķ�����Ը�ֵ������,�Լ������ָ��/�����ǿ���ָ���������,
		��Ƭ����˼���ǽ�������ͻ�����ͬ�Ĳ�����Ƭ��ֵ������,���Ƿ������ǲ��е�
		��Ϊ�ڻ�������û�����������������Ķ������ǲ�֪����,��ô��Ҫ����Ѱ��,���ʱ��
		���ܻᷢ�����ǵĵ�ַ����.���³�����
	*/
	per1 = stu1;
	//��ʱ�򴴽���һ�������ָ��,����ָ��������Ķ���
	Person*	per2 = &stu1;
	//��Ȼ˵���ַ�ʽҲ���Խ����������ת������������,���ǻ��ǲ���ȫ��,�����Խ����ʵ�����
	Student* stu2 = (Student *)per2;
#endif
	//�ߴ��С	
#if 0
	//����������̳��˻���,��ô��СӦ���ڻ���Ĵ�С֮��
	Person test1;
	Teacher test2;
	cout << sizeof(test1._name) << endl;
	cout << sizeof(test2) << endl;

#endif	

	//����������
	/*
		������߸����������ͬ���ĳ�Ա,�����Ա�����ε�����,ֱ�ӷ����Լ��ĳ�Ա,�������������,Ҳ���ض���
		Ҫ��ô����ؾ��ǻ���::�����Ա 

	
	*/
	per1 = stu1;
	
	per1.print();
	stu1.print();
	
	return 0;

	
}


#endif
