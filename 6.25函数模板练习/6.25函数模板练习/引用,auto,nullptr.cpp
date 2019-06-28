#include<iostream>
using namespace std;
/*1.概念
  2.特性
  3.常引用
  4.应用的场景  1.作为函数的参数{需要/不需要,通过形参来改变外部的实参  const 来修改}
				2.作为函数的返回值 :(不能返回函数栈上的空间)  函数调用过程
*/
//引用不是新定义一个变量,而是给一个存在的变量取了一个别名,他们共用一块内存空间
//如果以引用类型返回,返回值的生命周期必须不受函数的限制(比函数的生命周期长)
//函数直接传值的话那么效率就会低下,因为要临时拷贝,但是引用底层还是地址传递,不需要临时拷贝数据
//函数返回值类型的在值返回和类型值返回上的效率也是比较大的,值传递更占优一点
//在底层实现上引用也是有空间的,反汇编之后发现引用就是用指针来实现的
//
double d = 12.34;
const int &rd = d;
/*必须要加const才可以通过编译
因为在我们定义的时候,我们不知道这块空间的内容,地址,要修改的话没办法,(名字,地址都不可知道)
临时的空间是具有常性的,常量,既然是一个常量,普通类型是没有办法引用的,既然是常量就要加const,
这个rd不是d的引用,因为他们的地址不一样


*/
struct A {
	int b;
	int c;
};
A aa;
int &rb = aa.b;
//上面的例子方便操作,给aa.b取了一个别名

//1.引用类型做参数
//为了防止变量被修改,增加const 增加安全性
void print(const int &a){
	cout << a << endl;
}
void Swap(int& left,int&right){
	int temp = left;
	left = right;
	right = temp;
}
/* 
 引用作为参数,和实参的地址是一样的,可以不用指针的方式来操作了
 别名的话,和外部的实参是一个实体,不需要解引用,

*/
//2.引用类型作为返回类型

/*int& Add(int right, int left){
	int ret = left + right;
}*/
/*
int &ret = Add(1, 2);
Add(3,4);
printf("%d", ret);
printf("%d", ret);
*/
/*没有修改ret,但是内容已经变了
esp 栈顶
ebp 栈底   mian函数
函数运行栈空间 push  参数压栈

push 2   (栈顶)
push 1
call  Add(...)
继续压下一条指令的地址esp往下走 Add函数进来  esp  ebp重新定义,重新压栈
找到ret变量的位置
接下来左右要相加,左右就是刚才main函数栈里面的位置,保存起来ret = 3;
对于Add里面的操作已经做完了,那么就返回 做完了,Add这个函数加法栈的位置就回收了(该部分空间不受程序控制了,但是操作系统没有删除)
只是不受程序控制了
恢复位置
ret相当于是Add加法的一个别名,但是上个空间已经不是一段有用的空间了,不受程序控制了
这时候引用的是一个被释放的空间了,接下来再次执行Add函数 ,传参,压栈,压在栈顶的位置 覆盖掉原来的1 2 下一条指令位置 esp
调用Add函数,划分栈的环境,划分好了,划分多大的空间是和上一次是一样的,esp ebp标记  ebp移动到esp 的位置,代码完成之后,
系统知道esp给ebp减同一个值就行了,因为两次函数是一样的,那么操作系统划分的空间是一样的 ,ret和 上次的调用是一样的位置
3+4 相加就改成7了


ret一直一直引用的是同一个位置 第一次能记录到 3 是因为,空间只是不受代码控制,但是并没有清空空间
所以ret 能够指向3 
所以空间是什么内容,ret就是什么内容,


int ret   这个内容一直在主函数栈帧里面,所以如果再次调用的话,不会影响主函数里面的ret   




*/
/*
返回局部变量或临时空间地址
你按照这种方式返回,外面引用接受接受的可能就是非法的空间了
引用一定不能返回函数栈上的空间,
返回结果的生命周期不受函数控制就可以(实体的生命周期要比函数长才可以)
定义一个全局变量不会受函数生命周期的影响了
1.全局变量
2.static类型的变量
3.引用类型的变量,因为相当于外部调用函数的实体,所以可以传引用
ret和g_a的地址是一样的相当于g_a的别名

引用---->实体的别名,在底层编译器把引用当成指针来处理了,
引用只能指向一个
T&<==>T* const   修饰的是一个指针,这个指针修改不了
const T&  这个引用不能修改指向  ===>const T* const

*/
int g_a;

int& Add(int left, int right){
	g_a = left + right;
	return g_a;
	//return a;
}
int& ret = Add(1, 2);
/*传值和传地址的效率差不多是一样的 */
//-----------------------------------------
// 宏的优缺点
/*
	宏的优点:
		1.增强代码的可读性
		2.提高性能
	宏的缺点:
		1.不方便调试宏
		2.导致代码的可读性变差
		3.没有类型的安全检查
	改进方法 :
		对于常量:用const来定义
		对于函数:用内联函数




*/
#if 0
int& Add(int a, int b){


	int c = a + b;
	return c;
}
int add(int a, int b){
	int  d = 10;
	int& pa = d;
	int c = a + b;
	return pa;
}
int Test(){
	return 0;
}

int  main(){

	int& ret = Add(1, 2);
	int b = Add(1, 2);
	
	Add(3, 4);
	b = add(1, 2);
	cout << ret << endl;
	cout << b << endl;
	return 0;
}
#endif

#if  0
#include<time.h>


struct A {
	int  a[10000];
};


A a;

A TestFunc1(){
	return a;
}
A& TestFunc2(){
	return a;
}
void TestReValue(){
	size_t begin1 = clock(); 
	for (size_t i = 0; i < 10000; i++){
		TestFunc1();
	}
	size_t end1 = clock();

	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; i++){
		TestFunc2();
	}
	size_t end2 = clock();
	

	cout << "Test1 time" << end1 - begin1 << endl;
	cout << "Test2 time" << end2 - begin2 << endl;
}
int main(){
	/*for (int i = 0; i < 10000; i++){
		TestReValue();
	}*/

	int A;
	int&a = A;
	cout << typeid(a).name() <<" "<<sizeof(a)<< endl;


	return 0;
}

#endif



/*
	C++11:
	auto 不能使用的场景
		1.auto不能作为函数的参数,不能作为函数的参数类型,因为编译器无法对参数类型做出实际推导
		2.auto不能直接来声明数组
	范围for()循环
*/
void  Testauto(/*auto a*/){
	int array1[] = { 1, 2, 3 };
	/*auto array2[] = { 1, 2, 3 };*/
}
int main(){
	//C++11新特性
	//对于有范围的集合而言,由程序员来说明循环的范围是多余的
	int array[] = { 1, 2, 3, 4 };
	//for循环后面的括号分为两部分,是由 : 来分的,第一部分范围内用于迭代的变量,第二部分则表示被迭代的范围
	//需要注意的是for的范围是确定的
	/*下面的式中相当于     int&e = array*/
	for (auto&e : array){
		e *= 2;
	}
	//e 就是迭代的变量 ,相当于一个融合---->array[i]
	for (auto e : array){
		cout << e << endl;
	}


	/*在C98中NULL可能被定义为字面常量0,或者被定义为无类型指针(void*),产生了二义性,
	C++11 中引入了nullptr 来表示指针的空值常量,类型为nullptr_t,仅仅可被隐式转化为指针类型      */
	int *a = nullptr;
	int *b = NULL;



	return 0;
}

