#if 0
#include<iostream>
using namespace std;

/*

	多态表示的是,不同对象的同种操作产生出来不同的状态
	多态的构成必须是在有继承关系的类中去实现的,他们各自去进行不同的操作,产生了不同的状态,
		1.必须通过基类的指针或者引用去调用虚函数
		2.被调用的函数必须是虚函数,并且派生类必须对基类的虚函数进行重写
		
	虚函数:
		按照virtual 这个关键字来修饰的类的成员函数称为虚函数

	虚函数的重写(覆盖):派生类中有一个和基类完全相同的虚函数
	(派生类的虚函数和基类的虚函数返回值类型,函数名字,函数参数列表完全相同)
	那么就称为子类的虚函数重写了基类的虚函数.
	

	虚函数重写的两个例外: 1.协变 基类和派生类各自返回各自的指针或者引用时候,称为协变
						  2.析构函数的重写(基类与派生类析构函数的名字的不同){
							 只要基类的析构函数被追加为虚函数,那么派生类不管加不加关键字
							 都和基类析构函数构成重写.
						  }
						  override  检查派生类虚函数是否重写了基类的某个虚函数,如果没有的话,重写编译报错

	抽象类: 在虚函数的后面写上 = 0 ,则这个函数称为纯虚函数,包含纯虚函数的类称为抽象类(接口类),抽象类不能实例化出对象
*/
/*
class Person { 
public:    
	virtual void BuyTicket() { 
		cout << "买票-全价" << endl; 
	} 
};

class Student : public Person {
public:
	virtual void BuyTicket() {
		cout << "买票-半价" << endl;
	}
};
*/

//在调用的过程中必须通过基类的指针或者引用来调用这个虚函数
//void Func(Person& p) {
//	p.BuyTicket(); 
//}
class Person{
public:
	virtual ~Person(){
		cout << "~Person()" << endl;
	}
};
class Student:public Person{
public:
	virtual ~Student()override{
		cout << "~Student()" << endl;
	}
};
void Test(){
		
}

int main() {
	Person *p1 = new Person;
	Student *p2 = new Student;

	delete p1;
	delete p2;

	return 0;
}
#endif
