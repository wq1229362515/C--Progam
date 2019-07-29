#include"String.h"
using namespace wq;
//首先是构造函数
//首先是默认的构造函数,设置一个尺寸,size = 0,容量capacity  = 15;
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
//复制拷贝函数
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
//模拟实现赋值运算符的重载
//浅拷贝的问题就是和要拷贝的对象里面的字符串他们指向了同一块内存空间
//他意味着如果有一方发生了修改,那么另外一方也会发生修改
//如果他们我们想要的字符串一串常量内容,只是拿来用用而已,那么就可以用浅拷贝来解决
//但是说如果我们要改变拷贝的内容的话,那么是不可以的
/*
	为了解决这个浅拷贝的问题
	1.可以利用复制拷贝函数去创建一个对象,然后swap里面的str

	String temp(s);
	_str = temp._str;
	_size = temp._size;
	_capacity = temp._capacity;
	在出了作用域之后,这个temp对象会被析构掉


	不用自己手动去创建一个变量,利用swap函数函数传参进去是一个值的拷贝,完成一个拷贝
	
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
	//1.释放旧内存中的内容
	//2.创建一个新对象,赋值到新对象中
	//3.将新地址传给旧内存中去
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

