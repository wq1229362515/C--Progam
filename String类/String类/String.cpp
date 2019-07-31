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
String::String(const String& s):_str(nullptr){

	String temp(s._str);
	swap(_str, temp._str);

}

int  String::Empty(){
	return (this->_size == 0)?0:1;
}
size_t String::Size(){
	return this->_size;
}
//模拟实现赋值运算符的重载
//浅拷贝的问题就是和要拷贝的对象里面的字符串他们指向了同一块内存空间
//他意味着:
//			1.如果有一方发生了修改,那么另外一方也会发生修改
//			2.原来准备拷贝的成员里面的内容没有被释放,造成了内存的泄露问题
//			3.对象在被析构的时候,将会调用两次析构函数
//如果他们我们想要的字符串一串常量内容,只是拿来用用而已,那么就可以用浅拷贝来解决
//但是说如果我们要改变拷贝的内容的话,那么是不可以的
/*
	为了解决这个浅拷贝的问题
	1.解决拷贝构造的浅拷贝问题
	我们先创建一个临时的对象,执行构造函数之后就会将要拷贝的内容拷贝到我们的这个新对象中
	然后用交换函数完成里面对象地址的交换
	在函数出去之后,因为函数作用域的关系,那个临时的对象就会被销毁掉,原来对象里面的内容也会被销毁掉(析构)

	2.赋值运算的浅拷贝问题的解决方案
	我们首先传的是一个值,并不是一个引用,在我们传值的时候,就是一份拷贝的内容
	将这个拷贝的对象和我们要进行赋值的对象交换内容,那么内容就会完成一个交换
	这个拷贝的临时在作用域结束时候,就会进行析构函数,销毁掉拷贝的内容,那么原来赋值的对象的内容就不会存在
	内存泄露的问题.
	我们的浅拷贝问题也就解决了.

	
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
	//在完成这个过程的时候,我们利用的是一个临时的变量去使我们的源变量去改变了地址指向
	//假如我们先释放,直接不利用临时变量来间接地址赋值,如果内存不够的话,那么程序就凉了
	//我们原先保存的数据也会被销毁.
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

