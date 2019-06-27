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

class Date {
public:
	Date(int _year = 1990, int _month = 1, int _day = 1)
		:year(_year)
		, month(_month)
		, day(_day)
		{}
	bool operator==(const Date &d2){
		//Data temp(d2);
		return this->day == d2.day
		&& this->month == d2.month
		&& this->year == d2.year;
	
	}
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
	Date& operator<<(const Date& d3){
		cout << this->year << "," << this->month << ","
			<< this->day;
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
/*bool operator==(const Data& d1, const Data &d2){
	return d1.day == d2.day
		&& d1.month == d2.month
		&& d1.year == d2.year;
				
}*/

int  main(){

	int  a = 10;
	int  b = 10;
	bool ret = (a == b);
	//在普通的变量中都可以进行这样的赋值,但是在类中就是不可以的
	Date d1(2002,2,2);
	Date d2(d1);	// 完成的是一个拷贝函数
	//d1 == d2;   在类中进行这样的操作那么就是不行的,所以引入了运算符重载
	//在本质上来也是一个特殊的函数,因为执行了一段代码,用来判断两个类是否是相等的
	//当然我们也可以在可以直接定义一个函数,来对两个类来进行判断
	cout << (d1 == d2) << endl;
	Date d3(2019, 6, 30);
	d1 = d3;
	d3++;
	++d1;
	d3 += 30;

	return 0;

}