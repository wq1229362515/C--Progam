#include<iostream>

using namespace std;
#if 0
//在编译期间,若没有相应的代码对应函数模板那么就不会编译相应的函数模板
//如果有参数,有代码生成了,那么就要进行参数推演,在编译期进行函数推演
//调用的时候是调用的生成的函数,
//函数模板只是编译器生成代码的模具,不是真正的函数,
//运用不同的参数使用函数模板的时候,称为函数模板的实例化,有隐式实例化,显式实例化


//函数模板的创建
//1.创建模板,class h ,typename 都是用来定义模板参数的关键字
template <class T> 
//template <typename T>
T Add(T left, T right){
	return left + right;
}

int  main(){

	cout << Add(1, 2) <<  endl;
	Add<double>(1.0, 2);

	return 0;
}

#endif



#if 0
#include "Test.h"

int main(){


	//类模板的实例化和函数模板的实例化是不同的,需要在类模板名字后面加上<>,然后将实例的类型放在<>中
	//类模板的名字不是真正的类,实例化的结果才是真正的类

	SeqList <int>s1;
	s1.Pushback(1);
	s1.Pushback(2);
	s1.Pushback(3);
	s1.Pushback(4);
	s1[1];
	//将这个空间初始化为10
	//int *ptr = new int(10);
	//动态分配十个连续的空间
	//int *ptr = new int[10];
	return 0;
}

#endif 

#if 0
/*
	this 指针存放在ecx寄存器里面,当我们与多个对象的时候,当我们调用对象的函数的时候,是怎么区分不同的对象的
	这就是this指针需要解决的问题
	编译器给每一个成员函数加入了隐藏的指针参数,让这个指针作为形参,这个指针指向了当前的对象,在函数体里面对变量的操作都是
	通过这个指针去访问的,对于用户来说这个过程是透明的,由编译器来自动完成

	this指针的特性:

	1.this指针的类型 : 类类型 *const
	2.只能在成员函数的内部使用
	3.this本质其实是一个成员函数的形参,对象调用成员函数的时候,对象地址作为实参传递给了this形参,所以对象不存储指针
	4.this是成员函数的第一个形参,一般由便一起去通过ecx寄存器自动传递,不需要用户来传递,

	this指针可以为空吗?
	this指针可以为空,当我们不需要this指针来做操作的时候,也就是我们对成员变量不做任何操作的时候,可以为空,当需要对变量进行操作的时候
	那么代码就会奔溃
	this指针存放在哪里? 
	定义完类的对象就开始调用构造函数,完成之后,编译器将对象的首地址传给了ecx寄存器,类的其他成员函数存放在栈中
	this 指针参数存放在ecx寄存器当中,类的静态成员函数因为没有this指针这个参数，所以类的静态成员函数也就无法调用类的非静态成员变量。
*/
class Date {
public:
	Date(int _year = 1990, int _month = 1, int _day = 1)
		:year(_year)
		, month(_month)
		, day(_day)
	{}
	void printDate(){
		cout << year << " " << month << " "
			<< day << endl;
	}
	void Show(){
		cout << "123" << endl;
	}
private:
	int year;
	int month;
	int day;
};

int main(){

	Date d1;
	d1.printDate();
	d1.Show();

	Date* d2 = nullptr;
	d2->Show();
	d2->printDate();
	return 0;
}

#endif

class Date {
public:
	Date(int _year = 1990, int _month = 1, int _day = 1)
		:year(_year)
		, month(_month)
		, day(_day)
		{}
	/*拷贝构造函数,若生成的是系统默认的拷贝构造函数,那么就是浅拷贝(值拷贝)
	//针对的是管理了一段空间的对象,比如说string类
	//对于空间类对象,并不会产生如此的问题
	//拷贝构造函数
	1.是构造函数的一种重载形式
	2.拷贝构造函数参数只有一个,且必须使用引用传参数,使用传值的方式会引发无穷递归调用	
	*/
	Date(const Date& d)
		:year(d.year)
		, month(d.month)
		, day(d.day)
	{}
	void Display() const{
		cout << year << "-" << month;
		cout << "-" << day << endl;
	}
	/*void Display(const Date *this){
	}*/
	/*const 在前不能修改this的指向
	  const 在后面不能修改 this指向的内容 
	 const 限制了this指针,const函数只能进行读 
	  */
	bool operator==(const Date &d2){
		//Data temp(d2);
		return this->day == d2.day
		&& this->month == d2.month
		&& this->year == d2.year;
	}
	//不等于
	bool  operator!=(const Date &d){
		return !(*this == d);
	}
	//赋值运算符,按照连续赋值顺序, a1 = a2 = a3;
	//自定义类型对象方式返回,按照引用方式返回,效率高,引用低下是个指针
	//按照引用的方式返回
	Date& operator=(const Date &d2){
		if (this != &d2){
			this->day = d2.day;
			this->year = d2.year;
			this->month = d2.month;
		}
		return *this;
	}
	//前置加加
	Date& operator++(){

		
		if (this->day == 30 && (this->month == 4 || this->month == 6 ||
			this->month == 9 || this->month == 11)){
			this->month++;
			this->day = 1;
		}
		else if (this->day == 31){
			this->month++;
			this->day = 1;
		}
		else {
			this->day++;
		}
		return *this;
	}

	//后置加加
	Date& operator++(int){
		Date temp(*this);
		if (this->day == 30 && (this->month == 4 || this->month == 6 ||
			this->month == 9 || this->month == 11)){
			this->month++;
			this->day = 1;
		}
		else if (this->day == 31){
			this->month++;
			this->day = 1;
		}
		else {
			this->day++;
		}
		return temp;
	}	
	//+ 号不能修改,那么就不能改变+号的内容
	Date operator+(int days){
		Date temp(*this);
		temp.day += days;
		return temp;
	}
	Date& operator+=(int day){
		this->day += day;
		return *this;
	}
private:
	//如果要进行判断的话那么就要放开权限了
	int year;
	int month;
	int day;
};
//运算符重载
//运算符重载是具有特殊函数名的函数
//必须是这个语言所支持的运算符,不能臆造一个运算符  .*     ::   sizeof   ?:  .(类似成员访问运算符)
//重载运算符必须有一个类类型或者枚举操作符!
//不能改变运算符的原有意思
/*bool operator==(const Data& d1, const Data &d2){
	return d1.day == d2.day
		&& d1.month == d2.month
		&& d1.year == d2.year;
				
}*/
void TestDate(){
	Date d1(2019, 6, 28);
	Date d2(d1);
	//两种方式是等价的,编译器就忽略了
	d1 = d2;
	d1.operator=(d2);   // Date::operator = (&d1,d2);
	system("pause");
}

int  main(){

	TestDate();

	return 0;

}