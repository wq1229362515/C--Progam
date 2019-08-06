
#define _CRT_SECURE_NO_WARNINGS
/*


	typedrf 这个关键字允许我们来自己来为各种数据类型取一个新的名字,typedef这个声明的写法和普通声明是基本相同的,
	只是把typedef 这个关键字出现在声明的前面,

	1.首先我们要写出一个标准的数据类型声明
			char *str;
	2.写出来之后在前面加上这个关键字来修饰他;
			typedef char *str;
	3.用新定义的数据类型来定义别的变量
		str s1,s2;


	用#define 的方式是不行的,宏的意思是这个定义的名字代表的是这个类型名字

	#define char*  STR

	STR s1,s2;

	s1 被定义成了一个字符型指针,但是s2,却是没有的,因为就像我们普通的声明一样.



*/
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
size_t _strlen(char *str){
	
	assert(str);
	int length = 0;
	for (length; *str++ != '\0';)
		++length;

		return length;
}


/*
	字符串的拷贝
*/

#include<string.h>
#include<assert.h>
/*
	断言就是声明某种东西应该为真,ANSI C实现了一个assert 宏,
		void assert (int expression);
	如果他的值为假的话,那么就打印一条诊断信息,并终止程序

	调试完成可以在assert.h 头文件中增加定义
	#define NDEBUG
	在这个被定义之后,预处理器将丢弃所有的断言,消除了开销,

		
*/
char * _stcpy(const char *str){
	assert(str);
	char *new_str = (char*)malloc(strlen(str)+1);
	if (new_str == NULL){
		assert(new_str);
		return NULL;
	}
	strcpy(new_str, str);

	return new_str;
}
/*
	查找字符串最右边第一次出现的那个要查找的字符串
	在受str1字符串中去查找str2
*/
char * _strrstr(const char* str1,const char* str2){

	assert(str1);
	assert(str2);

	char *last = NULL;
	char *current;

	current = strstr(str1, str2);
	while (current != NULL){
		last = current;
		current = strstr(last + 1, str2);
	}

	return last;
}

int  main1(){

	char *_str = "12345";
	size_t ret = _strlen(_str);
	
	/*
		malloc 函数是向内存申请一块连续的地址空间,如果申请成功就把这个地址空间的首地址返回
		如果申请失败,就返回一个空值
		void *malloc(size_t size);
		void free(void *pointer);
	*/
	int *ptr = malloc(4);
	if (ptr == NULL){
		return -1;
	}
	/*
		实际上malloc分配的内存要比实际的多一点,但是也是根据编译器来看的
	*/
	for (int i = 0; i < 4; ++i){
		//下标和解引用的功能在这里是相同的
		//ptr[i] = i;
		*(ptr + i) = i;
	}
	/*
	
		realloc 用于修改已经分配好内存的块的大小,但是仅仅限于没有被初始化内容的指针,

		int *ptr = (int *)malloc(4);
		realloc(ptr, 2);	
	
	*/


	/*
	
		变量的存储类型有三种:普通变量,运行时堆栈,硬件寄存器



		全局变量: 具有全局的属性,被一次定义,就能作用于所有的源文件中.
		局部变量：具有局部作用域，它是自动对象（auto），它在程序运行期间不是一直存在，
				  而是只在函数执行期间存在，函数的一次调用执行结束后，变量被撤销，其所占用的内存也被收回。

		静态局部变量：具有局部作用域，它只被初始化一次，自从第一次被初始化直到程序运行结束都一直存在。
		静态全局变量: 具有全局的属性,他和全局变量的区别就是,他只能作用与当前所定义他的文件中,
						被static修饰过的变量具有文件作用域
						初始化：未经初始化的全局变量会被自动初始化为0
						（使得作用域仅限于被定义的文件中 即，从变量定义到本文件结尾处，其他文件不论通过什么方式都不能访问）。
						


						静态存储区 (static) ,全局变量和静态变量是在同一地方存储的

						static 修饰的函数,只能在当前定义的文件中去运行,也只能作用当前定义他的文件中去,别的文件使用不了他
						这样的话有一个好处:程序员不用担心自己编写的函数与其他文件的函数同名
						静态函数只是在声明他的文件当中可见,当然要是再头文件中标明了这个函数,那么全体是可见的
	
	*/

	int array[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

	
	
	return 0;
}
