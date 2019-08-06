/*
在C++中 NULL和0 被看做是同一种东西,C++不允许(void *)被隐式转换为其他类型 
那么 char* ptr = NULL;
中的NULL会被当做0来处理那么在进行函数重载的时候


void Func(int num);
void Func(char *ptr);
重载的时候会去调用第一个函数,因为NULL被当做0了

#define NULL    0

#define NULL    ((void *)0)


nullptr 类型为nullptr_t (包含在std命名空间里面),能够隐式转换为所有指针的类型,所以在初始化指针的
时候尽量的去使用nullptr来初始化指针


int *ptr = NULL;
int *ptr2 = nullptr;
nullptr_t ptr;

void* 指针
他可以存放任意对象的地址,一个(void *)指针存放着一个地址,不同于其他类型指针的是,我们不清楚这个地址中到底
是一个什么类型的对象
(void *)指针做的事情比较有限,和其他指针做比较,作为函数的输入输出,或者赋值给另外一个指针,不能操作(void* )指针
所指向的对象,因为我们并不知道这个对象到底是什么类型,也就不能确定在这个对象上能做哪些操作
*/
#pragma pack(4)
struct test{
	char a;      //1
	int b;       //4
	char c;      //1
	double d;    //8
	char e = 0;  //1

};

/*
32bit
	a b b b
	b c


内存对齐是一种提高内存访问速度的策略,cpu在访问未对齐的内存可能需要两次访问,经过对齐的大多数情况就访问一次就够了
假如没在一条地址里面,可能就涉及到cpu指令集调用和总线的读写操作


	内存对齐原则:
		0.设置一个初始地址一般是0x00开始
		1.结构体内成员按自身长度自行对齐
		2.结构体总的大小为结构体有效对齐值的整数倍
		

		结构体的有效对齐值的确定:
			1>当没有明确说明时候,以结构体中最长的成员长度为有效值
			2>当用#pragma pack(n)指定的时候,以n和结构体中最长的成员中比较小者为它的值
			2>当_attribute_((_packed)_)指定长度的时候,强制按照此值为结构体的有效对齐值





*/
#include<iostream>
#include<memory>
using namespace std;
int main(){

	test a;

	shared_ptr<int>ptr = make_shared<int>(42);
	shared_ptr<int>ptr2(ptr);

	unique_ptr<int>ptr3 = make_unique<int>(43);
	//unique_ptr<int>ptr4(ptr3);
	cout<<sizeof(test);

	
}
