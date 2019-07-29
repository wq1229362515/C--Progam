#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

/*


	String ���ģ��ʵ��
	1.���캯��
	2.��ֵ���������
	3.�������캯��
	4.��������

	

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
