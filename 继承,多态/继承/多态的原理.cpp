#include<iostream>
using namespace std;



/*

	ÿһ�������г��˴洢�Լ��ĳ�Ա,��Ҫ�洢һ���麯����ָ��,_vfptr  v����vitural ,f����function����˼
	ÿһ�������麯���Ķ������涼���������һ���麯����ָ��,��Ϊ�麯���ĵ�ַҪ���ŵ��麯���ı���ȥ
	�麯���������


*/
#if 0
class Base {
public:    virtual void Func1()    { cout << "Base::Func1()" << endl; }

		   virtual void Func2()    { cout << "Base::Func2()" << endl; }

		   void Func3()    { cout << "Base::Func3()" << endl; }

private:    int _b = 1;
};

class Derive : public Base { 
public:    virtual void Func1()    { cout << "Derive::Func1()" << endl; }

private:    int _d = 2;

};
/*
	1.	���Կ�������d����Ҳ���Լ��麯��ָ��,Ҳά�����Լ����麯����
		d��������������ɵ�һ�����Ǽ̳���������ĳ�Ա����,�麯��ָ����Ǵ������������
		�ڶ����־����Լ��ĳ�Ա
	2.	b��d��������һ��,��Ϊd���������Լ���д���麯��func1 ���Դ洢�������ַ���ǹ����Լ�
		����麯���ĵ�ַ,���Թ����˸���,����ָ�麯���ĸ���.��д���﷨�Ľз�,������ԭ���Ľз�
	3.	
*/
int main(){
	Base b;
	Derive d;
	return 0;
}
#endif

#if 0
class Person{

public:
	virtual void buyticket(){
		cout << "����Ʊ" << endl;
	}

};
class Student :public Person{
public:
	virtual void buyticket(){
		cout << "ѧ��Ʊ" << endl;
	}
};

void Testbuyticket(Person &p){
	p.buyticket();
}
int main(){


	Person per;
	Testbuyticket(per);				//���ö�̬�ĵ����Ƿ����ں��������ڼ������õ�
	per.buyticket();				//��Ȼ���buyticket��һ���麯��,�����ڵ��õ�ʱ���Ƕ��������õ�,
									//�������̬������,��̬�������Ǳ����û�������û���ָ��������
									//�����õĺ����������麯��
	/*
		��̬�İ�(���):�ڳ���ı����ڼ�ȷ���˳������Ϊ,Ҳ�о�̬��̬----����������
		�ҵ����������ñ�����֪���������ʱ����Ҫ����ʲô����,����Ҫ����ʲô�����ļ���
		�����������֪�������ļ�������,��ô������������е�ʱ������ȷ����ľ�����Ϊ��ʲô
		��̬�İ�(��̬�İ�):������Ǹ��ݾ����õ���������ȷ������ľ������Ϊ
		����˵�������ĵ��ò������һ��,�������õ�ʱ����ʵ��,�ڳ�������������������


		��ͨ�Ķ�����ȥ�����麯�������ǳ�Ա����ͨ������ʱ��,�ٶ���һ�����,
		���������ָ������Ƕ��������ȥ�����麯����ʱ��,��ô�϶�����ͨ�����һ��,
		��Ϊ�����ǵ��õ�ʱ��,�麯����Ҫȥ��������麯�����,��Ҳ�ǲ���
	*/


	Student stu; 
	Testbuyticket(stu);

	return 0;
}



#endif 

/*
		��.�跨���õ�����麯���ĵ�ַ
		�����麯���������һ�����ݿ϶���NULL������


*/

typedef void(*vptr)();					//����һ������ָ��
typedef void(*v_ptr[])();				//����ָ������(int )
typedef int*   a;
class Base {
public:    virtual void Func1()
			{
			   cout << "Base::Func1()" << endl;
			}

		   virtual void Func2()    { cout << "Base::Func2()" << endl; }

		   void Func3()
		   {
			   cout << "Base::Func3()" << endl;
		   }

private:
	int _b = 1;
};

class Derive : public Base {
public: 
	virtual void Func1()
	{
		   cout << "Derive::Func1()" << endl;
	}
private:   
	int _d = 2;
};

void Test_vptr(vptr ptr[]){
	while (ptr++ != nullptr){
		cout << ptr << endl;
	}

}

int main(){
	/*
		����Ҫȡ��������ָ��,������ָ��������ǰ 4���ֽ�
		Ҳ����˵b�ĵ�ַ���ݾ��Ǵ��������ָ��,��ô��Ҫ����ת��Ϊһ������ָ��

	*/

	Base b;
	Derive d;

	vptr _ptr1 = (vptr)(*(int *)&b);
	vptr *_ptr2 = (vptr*)(*(int *)&b);

	Test_vptr(_ptr2);

	
	



	return 0;
} 