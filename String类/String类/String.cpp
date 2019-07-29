#include"String.h"
using namespace wq;
//�����ǹ��캯��
//������Ĭ�ϵĹ��캯��,����һ���ߴ�,size = 0,����capacity  = 15;
String::String():
	_str(new char[15]) 
	,_size(0),
	_capacity(15)
	{}
String::String(const char*str){
	if (str == nullptr){
		assert(false);
		return;
	}
	_str = new char[strlen(str) + 1];
	strcpy(_str, str);
	_size = strlen(_str);
	_capacity = 15;
}
//���ƿ�������
String::String(const String& s)
	:_str(new char[strlen(s._str)+1])
	,_size(strlen(s._str))
	, _capacity(s._capacity)
{
	strcpy(_str, s._str);
}

int  String::Empty(){
	return (this->_size == 0)?0:1;
}
size_t String::Size(){
	return this->_size;
}
//ģ��ʵ�ָ�ֵ�����������
//ǳ������������Ǻ�Ҫ�����Ķ���������ַ�������ָ����ͬһ���ڴ�ռ�
//����ζ�������һ���������޸�,��ô����һ��Ҳ�ᷢ���޸�
//�������������Ҫ���ַ���һ����������,ֻ���������ö���,��ô�Ϳ�����ǳ���������
//����˵�������Ҫ�ı俽�������ݵĻ�,��ô�ǲ����Ե�
/*
	Ϊ�˽�����ǳ����������
	1.�������ø��ƿ�������ȥ����һ������,Ȼ��swap�����str

	String temp(s);
	_str = temp._str;
	_size = temp._size;
	_capacity = temp._capacity;
	�ڳ���������֮��,���temp����ᱻ������


	�����Լ��ֶ�ȥ����һ������,����swap�����������ν�ȥ��һ��ֵ�Ŀ���,���һ������
	
*/
String& String ::operator=(String s){
	if (this == &s){
		return *this;
	}
	swap(_str,s._str);
	swap(_size,s._size);
	swap(_capacity, s._capacity);

	return *this;
}

#if 0
String& String ::operator=(const String& s){

	if (this == &s){
		return *this;
	}
	//1.�ͷž��ڴ��е�����
	//2.����һ���¶���,��ֵ���¶�����
	//3.���µ�ַ�������ڴ���ȥ
	char *temp = new char[strlen(s._str) + 1];
	strcpy(temp, s._str);
	delete[] _str;
	_str = temp;

	return *this;
}
#endif
String ::~String(){
	if (_str){
		delete[] _str;
		_str = nullptr;
	}
}

void String::Resrve(int newcapacity){
	if (newcapacity > _capacity){
		char *str = new char[newcapacity + 1];
		strcpy(str, _str);
		delete[] _str;
		_str = str;
		_capacity = newcapacity;
	}
}
void String::pushback(char c){
	if (_size == _capacity){
		Resrve(2*_capacity);
	}
	_str[_size++] = 'c';
	_str[_size] = '\0';

	return;
}

