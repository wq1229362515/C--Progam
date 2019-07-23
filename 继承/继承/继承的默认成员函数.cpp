#if 0
#include<iostream>
#include<string>
using namespace std;
/*
	六个默认的函数是:
	构造,析构(完成对象的创建和销毁)
	拷贝(拷贝构造是使用同类对象进行本对象的初始化创建工作)
	赋值(完成对象之间的相互赋值)
	取地址(取地址主要是普通对象和const对象的取地址操作)
	重载(进行的是对象运算符的重载)
*/

/*
	使得类无法被继承的例子:

		1.final 是一个修饰类的关键字,他的作用是使类无法被继承
		  class Person final{};



*/

class NoInherit{
public:
	//因为你将构造函数私有化之后,是无法完成类的创建的,如果你需要完成一个类的创建
	//我们就需要定义一个接口,是这个函数来间接的访问这个构造函数.
	//因此这个函数的类型必须是一个静态的函数,
	//否则的话我们不能完成对这个函数的访问,因为我们没法直接定义一个类
	static NoInherit GetInstance(){
		return NoInherit();
	}
	

private:
	//将构造函数给私有化,派生类调用不到基类的构造函数,那么将无法继承
	NoInherit(){
	}
};
class Test :public NoInherit{

};



 class Person {
 public:
	
	Person(){
		cout << "Preson create" << endl;
	}

	Person(const string name, int age) :_name(name), _age(age) {
		cout << "Preson()" << endl;
	}
	//Person 的拷贝构造函数
	Person(const Person& per):_age(per._age),_name(per._name){
		cout << "Preson(const Preson& per)" <<  endl;
	}
	~Person(){
		cout << "~Person()" << endl;
	}

public:
	int _age;
	string _name;
};

class Student :public Person{

public:
	//继承了父类的成员,那么就要调用的时候调用基类的构造函数,来初始化基类的那一部分,如果基类没有默认的
	//构造函数,则必须在派生类构造函数的初始化列表阶段显示调用.而且相关的参数应该由子类来给出.
	//创建了那个类的对象,先调用哪儿的构造函数,基类构造函数在派生类的初始化列表

	//不能直接在参数列表中直接写成_name(name)这种方式的,因为_name这种,是属于基类的成员,所以要在基类的
	//构造函数中去完成这种初始化.
	//Student(string name,int age,int num):
	//	Person(name,age)
	//	,_num(num){
	//}
	Student(){
		cout << "Student create" << endl;
	}
	Student(const string& name, int age,int num) :
		Person(name,age)
		,_num(num)
	{
		cout << "Student()" << endl;
	}
	//如果有拷贝函数,那么和构造函数也一样,也要在初始化列表里面调用基类的拷贝构造函数
	//如果显示的调用这个拷贝构造的话,那么将会调用默认的构造函数
	Student(const Student& stu) :Person(stu) ,_num(stu._num)
	{
		cout << "Student(const Student& stu)" << endl;
	}
	//在进行析构函数的时候,派生类对象会先来调用派生类析构函数,再来调用基类的构造函数
	//在派生类对象的最后一句call Person::~Person()
	
	~Student(){
		cout << "~Student()" << endl;
	}
protected:
	int _num;	//学号
};
void Test(){
	Student stu1("Li",18,001);
}
int main(){
	
	Test();

	NoInherit Test1 = NoInherit::GetInstance();

	return 0;

}
#endif
