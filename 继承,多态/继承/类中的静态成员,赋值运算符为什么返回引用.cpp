#define _CRT_SECURE_NO_WARNINGS
#if 0
#include<iostream>
using namespace std;
//����һ��ͨ���������þ�̬��Ա�����ͷǾ�̬��Ա����


/*

		1.������һ���������ݵ�����,��������,
	���������֮��ĳ�Ա�������໥�����ġ�Ҫ�빲�����ݣ�����Ҫʹ�þ�̬��Ա�;�̬������
		2.��Ϊ��̬��Ա�����ڶ��󴴽�֮ǰ���Ѿ����������ڴ�ռ�,�ڱ�����
	��̬��Ա�������ڳ������ʱ����ռ䣬���ڳ������ʱ�ͷſռ䡣
	��ʼ����̬��Ա����Ҫ�����������С���ʼ���ĸ�ʽ���£���������  ����::��̬��Ա������ = ��ֵ��
		3.���Ǿ�̬��Ա����û��thisָ��,��֪��Ӧ�÷����ĸ������е�����,
	�����ڳ����в������þ�̬��Ա�����������е���ͨ����.���Ǿ�̬��Ա�������Է������еľ�̬����,���Է���ȫ������
	�������е���ͨ��Ա�������������е��������̬��Ա����
		4.��̬�����ķ���ռ��ڱ�����,�����еĳ�Ա��ʵ��������֮��Ż����ռ�,
		5.���еľ�̬��Ա������ʹ��֮ǰ��Ҫ���г�ʼ��,���ұ����������������г�ʼ��
		  ���ô��ؼ���static 
		  int Point :: count = 0;




*/
int a;
class Point{
public:
	void init()
	{}

	static void output();
	/*
	static void output(){
		cout<<"------"<<endl;
	}
	*/

public:
	static int count;
};

void Point::output(){
	cout << "--------" << endl;
}


//int Point::count = 10;

int  main()
{
	Point test;
	test.init();

	//�Ǿ�̬��Ա�����ķǷ�����
	//Point::init();
	//��̬�ĳ�Ա�����ĵ���
	Point::output();

	test.output();
	return 0;
}
#endif





#if 1
#include <iostream>
using namespace std;
class String
{
private:
	char *str;
	int len;
public:
	String(const char* s);//���캯������
	/*
	����ֵ�����û��߷��ض����ǿ��Ե�,�����������������Ǿͱ����������������

	1.�������������ֵ
	2.��ֹ���ض��󣨷��ض���Ҳ���Խ���������ֵ��������������a = b = c�������ǣ�a = b�� = c������ʱ����ÿ������캯���������������²���Ҫ�Ŀ�����
	���͸�ֵ�������Ч�ʡ�

		����������󷵻�Ҳ���Դﵽ���ǵĸ�ֵ��Ч��,ֻ���ڴ��ݵ�ʱ��,return�����˶���,Ҳ����˵�´�����һ������,��ô����Ҫ�Զ���
		�������(��������������ǶԶ�����п��������)������,�����ڴ��ʱ��,������������ֵ��ʱ��,��Ҫ���ÿ������캯������������ӵĸ�ֵ
	*/
	String operator=(const String& another)//��������أ���ʱ���ص��Ƕ���
	{
		if (this == &another)
			return *this;
		        //return another;
		delete[] str;
		len = another.len;
		str = new char[len + 1];
		strcpy(str, another.str);
			return *this;
		    //return another;
	}
	void show()
	{
		cout << "value = " << str << endl;
	}

	/*copy construct*/
	
	String(const String& other)
	{
		len = other.len;
		str = new char[len + 1];
		strcpy(str, other.str);
		cout << "copy construct" << endl;
	}
	

	~String()
	{
		delete[] str;
		cout << "deconstruct" << endl;
	}
};

String::String(const char* s)//���캯������
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
}



int main()
{
	String str1("abc");
	String str2("123");
	String str3("456");
	str1.show();
	str2.show();
	str3.show();
	str3 = str1 = str2;//str3.operator=(str1.operator=(str2))    
	str3.show();
	str1.show();
	return 0;
}
#endif





#if 0

#include<iostream>
#include<string>


using namespace std;



int main(){




	string a("str");
	string b("124");
	b = a;




	return 0;
}
#endif


/*

	λ�εĳ�Ա��һ�����߶�����ֶ�,��Щ��ͬ�ֶ�ʵ���ϴ洢��һ�����߶�����εı�����	

	λ�εĳ�Ա������unsigned int  ,int ,signed int �⼸�����͵�
	λ���ϵĿռ��ǰ���4���ֽڻ���1���ֽ������п��ٵ� 
	���������� ��Ա���������һ��ð��+����,�������ָ���������Ա���λ����ռ���˼���λ�ĸ���
	λ�β����п���ֲ��
	��Ϊλ���ڲ�ͬ��ϵͳ�п��ܾ��в�ͬ�Ľ��   1. intλ�α������з��Ż����޷���֤��
	2.λ����λ�������Ŀ
	3.λ���еĳ�Ա���ڴ����Ǵ���������仹�Ǵ�������ȥ����

*/

#if 0

#include<iostream>
using namespace std;

typedef struct  CHAR{
	unsigned ch : 7;
	unsigned font : 8;
	unsigned size : 19;


}test;

/*
	�ۺϵ���������,C�����ṩ����������,һ��������,����һ�־��ǽṹ��,
	��������ͬ����Ԫ�صļ���,�ṹҲ��һЩֵ�ļ���,ֻ������Щֵ����Ϊ�˳�Ա
	�������ͨ���±�������,���ǳ�Ա����ͨ�������Ա��������,`
*/
struct Test {
	//struct Test b;		�������ظ��Եĵ���	
	//struct Test* b;
	int a;
};
/* ----��ǩ
struct tag{

	member-list

}variable-list;
-------�����б�
*/


int main(){



	struct CHAR test;



	return 0;
}
#endif