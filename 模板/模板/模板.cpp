#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
/*
		�ػ����ǲ�����������Ϊ����Ҫ������
		�ⲻ�����ģ����Ƚ�����
		��ģ�������Ĳ����������⻯����


		��ģ���ػ��ļ��ַ�ʽ:
		ȫ�ػ�
		���������ػ�
		�Բ������н�һ�����ƶ������⻯����

*/
template<class T1,class T2>
class Date {
public:
	Date(){
		cout << "Date<T1,T2>" << endl;
	}

private: 
	T1 _d1;
	T2 _d2;
};

//ȫ�ػ�,���������ͽ������⻯����
template<>
class Date<int,char>{
public:
	Date() {
		cout << "Date<int,char>" << endl;
	}
private:
	int  _d1;
	char _d2;
};


// �����ػ�,���������ͽ������⻯�Ĵ���
template<class T1>
class Date<char ,T1> {
public:
	Date() {
		cout << "Date<T1,char>" << endl;
	}

private:
	T1 _d1;
	char _d2;
};

//�����ĸ���һ��������
template<>
class Date<int *,char*>
{
public:
	Date(){
		cout << "Date<int *,char *>" << endl;
	}

private:
	int* _d1;
	char* _d2;

};

class String {
public:
	String(const char *str = ""){
		if (str == nullptr) {
			_str = "";
		}
		_str = new char(strlen(str) + 1);
		strcpy(_str, str);
	}

	String(const String& s):_str(new char[strlen(s._str)+1]) {
		if (this != &s) {
			strcpy(_str, s._str);
		}
	}
	String& operator=(const String& s) {
		if (this != &s) {
			/*char* newstr = new char[strlen(s._str) + 1];
			strcpy(newstr, s._str);
			free(_str);
			_str = newstr;*/
			String s1(s);
			char* tmp = s1._str;
			s1._str = _str;
			_str = tmp;
		}
		return *this;
	}
	~String() {
		if (_str == nullptr) {
			return;
		}
		delete[]_str;
		_str = nullptr;
	}

private:
	char *_str;
};

//bool IsPODType(const string& type) {
//	string strType[] = { "char", "int", "long long", "float" };
//	for (auto e : strType) {
//		if (e == type)
//			return true;
//	}
//}



//������ȡ������ģ���ػ���Ӧ��
template<class T>
//ͨ�ÿ�����:��������Ͷ����Խ��п���
void Copy(T* dst, T* src, size_t size) {
	//��������,�Զ���������Ҫ��������
	//ö�ٵķ���,�ȽϷ���   	if(IsPODType(typeid(T).name())){

	
	//����������ȡ�ķ���
	//��һ�ν�����ʱ�����Ǳ������Ѿ���������������˴�����һ��int,��ʱ���ߵ��ػ��汾
	//template<>
	/*struct TypeTraits<int> {
		typedef TrueType  IsPODType	
	}*/
	if (TypeTraits<T>::IsPODType::Get()) {
		//����ַ������ֱ�ӿ���,���ǵ�ַ������������ʵ���ǵ�ַ
		//�ڴ�й¶
		//ǳ����
		//Ч�ʸ�
		memcpy(dst, src, sizeof(T)*size);
	}
	else {
		//�ŵ�:һ���������.����Ҫ������ֵ����
		//ȱ��:Ч�ʵ�
		for (size_t i = 0; i < size; ++i) {
			//��ʱ���������͵�ʱ��ͻ�ȥ������������������غ���
			dst[i] = src[i];
		}
	}
}
//�����������涼�о�̬�ĳ�Ա����,��ʱ�����һ��,�Ϳ�������������,�ڱ����ڼ����ǵı��������Ѿ�
//��T����������������
struct FalseType {
	static bool Get() {
		return false;
	}
};
struct TrueType { 
	static bool Get() {
		return true;
	}
};

//����ģ��
template<class T> 
struct TypeTraits {
	//�����IsPODType ȡ��һ������,�����Ļ�IsPODTYpe����ʹfalsetype,Ҳ������truetype
	//falseType --- ������������
	//trueType ����һ�����õ�����,���������ػ��Ĵ���ʽ
	//��һ���ṹ��TypeTraitsģ��` 
	typedef FalseType IsPODType;
};


//����ģ����ػ�
template<>
struct TypeTraits<int> {
	typedef TrueType IsPODType;
};


template<>
struct TypeTraits<long> {
	typedef TrueType IsPODType;
};


/*
		
	
*/


#include"head.hpp"


int main() {

	A<int> a;


	a.Func();




	return 0;
}

