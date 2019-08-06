#define _CRT_SECURE_NO_WARNINGS
#if 0
#include<iostream>
using namespace std;
//例子一：通过类名调用静态成员函数和非静态成员函数


/*

		1.体现了一个共享数据的作用,共用数据,
	对象与对象之间的成员变量是相互独立的。要想共用数据，则需要使用静态成员和静态方法。
		2.因为静态成员变量在对象创建之前就已经被分配了内存空间,在编译器
	静态成员变量是在程序编译时分配空间，而在程序结束时释放空间。
	初始化静态成员变量要在类的外面进行。初始化的格式如下：数据类型  类名::静态成员变量名 = 初值；
		3.但是静态成员函数没有this指针,不知道应该访问哪个对象中的数据,
	所以在程序中不可以用静态成员函数访问类中的普通变量.但是静态成员函数可以访问类中的静态变量,可以访问全局数据
	而且类中的普通成员函数可以在类中调用这个静态成员函数
		4.静态函数的分配空间在编译器,而类中的成员在实例化对象之后才会分配空间,
		5.类中的静态成员变量在使用之前需要进行初始化,而且必须是在类外来进行初始化
		  不用带关键字static 
		  int Point :: count = 0;




*/
int a;
class Point{
public:
	void init()
	{}

	static void output();
	/*
	static void output(){
		cout<<"------"<<endl;
	}
	*/

public:
	static int count;
};

void Point::output(){
	cout << "--------" << endl;
}


//int Point::count = 10;

int  main()
{
	Point test;
	test.init();

	//非静态成员函数的非法调用
	//Point::init();
	//静态的成员函数的调用
	Point::output();

	test.output();
	return 0;
}
#endif





#if 1
#include <iostream>
using namespace std;
class String
{
private:
	char *str;
	int len;
public:
	String(const char* s);//构造函数声明
	/*
	返回值是引用或者返回对象都是可以的,但是又特殊的情况我们就必须来返回这个引用

	1.允许进行连续赋值
	2.防止返回对象（返回对象也可以进行连续赋值（常规的情况，如a = b = c，而不是（a = b） = c））的时候调用拷贝构造函数和析构函数导致不必要的开销，
	降低赋值运算符的效率。

		利用这个对象返回也可以达到我们的赋值的效果,只是在传递的时候,return返回了对象,也就是说新创建了一个对象,那么就需要对对象
		进行这个(在这个例子里面是对对象进行拷贝构造的)与析构,花费内存和时间,而且在连续赋值的时候,还要调用拷贝构造函数来完成这个间接的赋值
	*/
	String operator=(const String& another)//运算符重载，此时返回的是对象
	{
		if (this == &another)
			return *this;
		        //return another;
		delete[] str;
		len = another.len;
		str = new char[len + 1];
		strcpy(str, another.str);
			return *this;
		    //return another;
	}
	void show()
	{
		cout << "value = " << str << endl;
	}

	/*copy construct*/
	
	String(const String& other)
	{
		len = other.len;
		str = new char[len + 1];
		strcpy(str, other.str);
		cout << "copy construct" << endl;
	}
	

	~String()
	{
		delete[] str;
		cout << "deconstruct" << endl;
	}
};

String::String(const char* s)//构造函数定义
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
}



int main()
{
	String str1("abc");
	String str2("123");
	String str3("456");
	str1.show();
	str2.show();
	str3.show();
	str3 = str1 = str2;//str3.operator=(str1.operator=(str2))    
	str3.show();
	str1.show();
	return 0;
}
#endif





#if 0

#include<iostream>
#include<string>


using namespace std;



int main(){




	string a("str");
	string b("124");
	b = a;




	return 0;
}
#endif


/*

	位段的成员是一个或者多个的字段,这些不同字段实际上存储于一个或者多个整形的变量中	

	位段的成员必须是unsigned int  ,int ,signed int 这几种类型的
	位段上的空间是按照4个字节或者1个字节来进行开辟的 
	他的声明是 成员名后面加上一个冒号+数字,这个数字指定了这个成员这个位段中占有了几个位的个数
	位段不具有可移植性
	因为位段在不同的系统中可能具有不同的结果   1. int位段被当做有符号还是无符号证书
	2.位段中位的最大数目
	3.位段中的成员在内存中是从右向左分配还是从左向右去分配

*/

#if 0

#include<iostream>
using namespace std;

typedef struct  CHAR{
	unsigned ch : 7;
	unsigned font : 8;
	unsigned size : 19;


}test;

/*
	聚合的数据类型,C语言提供了两种类型,一种是数组,另外一种就是结构体,
	数组是相同类型元素的集合,结构也是一些值的集合,只不过这些值被称为了成员
	数组可以通过下标来访问,但是成员必须通过这个成员名来访问,`
*/
struct Test {
	//struct Test b;		包含了重复性的调用	
	//struct Test* b;
	int a;
};
/* ----标签
struct tag{

	member-list

}variable-list;
-------变量列表
*/


int main(){



	struct CHAR test;



	return 0;
}
#endif