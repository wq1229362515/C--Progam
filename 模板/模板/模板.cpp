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

bool IsPODType(const string& type) {
	string strType[] = { "char", "int", "long long", "float" };
	for (auto e : strType) {
		if (e == type)
			return true;
	}
}



template<class T>
//ͨ�ÿ�����:��������Ͷ����Խ��п���
void Copy(T* dst, T* src, size_t size) {
	//��������,�Զ���������Ҫ��������
	typeid(T).name();	//"int" "class Date" ����ת�����ַ���
	//ö�ٵķ���,�ȽϷ���   	if(IsPODType(typeid(T).name())){
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
template<class T> 
struct TypeTraits {
	typedef FalseType IsPODType;
};
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
int main() {

	Date<int, int> arr1;
	Date<int, char> arr2;
	Date<char, char> arr3;
	Date<int*, char*>arr4;
	int array1[] = { 1, 2, 3, 4, 5 };
	int array2[sizeof(array1) / sizeof(array1[0])];
	Copy(array2, array1, 5);



	String str1[] = { "1234", "124","55" };
	String str5[3];
	Copy(str5, str1, 3);
	
	return 0;
}

