#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
/*
		特化就是参数类型设置为你想要的类型
		这不过这个模板得先建立好
		在模板的上面的参数进行特殊化处理


		类模板特化的几种方式:
		全特化
		参数部分特化
		对参数进行进一步限制而定特殊化处理

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

//全特化,将所有类型进行特殊化处理
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


// 部分特化,将部分类型进行特殊化的处理
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

//参数的更近一步的限制
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
//通用拷贝函:任意的类型都可以进行拷贝
void Copy(T* dst, T* src, size_t size) {
	//内置类型,自定义类型需要进行区分
	typeid(T).name();	//"int" "class Date" 类型转换成字符串
	//枚举的方法,比较繁琐   	if(IsPODType(typeid(T).name())){
	if (TypeTraits<T>::IsPODType::Get()) {
		//将地址的内容直接拷贝,但是地址的内容里面其实还是地址
		//内存泄露
		//浅拷贝
		//效率高
		memcpy(dst, src, sizeof(T)*size);
	}
	else {
		//优点:一定不会出错.你需要给出赋值重载
		//缺陷:效率低
		for (size_t i = 0; i < size; ++i) {
			//这时候是类类型的时候就会去调用类类型运算符重载函数
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

