#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

/*


	String 类的模拟实现
	1.构造函数
	2.赋值运算符重载
	3.拷贝构造函数
	4.析构函数

	

*/
namespace wq
{
	typedef char* iterator;
	class String {
	public:
		String(const char *str);
		String();
		String(const String& s);
		//String &operator=(const String& s);
		String &operator=(String s);
		String &operator+=(char c);
		~String();

		size_t Size();
		int Empty();
		void Swap(const string &s);
		iterator begin(){ return _str; }
		iterator end(){ return _str + _size; };


		void pushback(char s);
		void Resrve(int newcapacity);


	private:
		char *_str;
		size_t _size;
		size_t _capacity;
	};
}
