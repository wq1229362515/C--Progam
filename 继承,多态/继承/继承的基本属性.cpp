#if 0
#include<iostream>
#include<string>
using namespace std;



/*
	继承是类设计层次的复用,在保持原类(基类)特性的基础上对其进行扩展,增加功能,这个新类称为派生类
*/

class Person{
public:

	Person(){
	}
	Person(const string name  ,int age ,int num):_name(name),_age(age),_num(num){
	}
	void print(){
		cout << "年龄: " << _age << endl;
		cout << "姓名: " << _name << endl;
	}

	public:
	int _age ;
	string _name ;
	int _num;			//id号码
};
/*
	在进行继承的时候,继承的方式也是十分的重要,默认的继承方式是私有的继承,那么你就不能在派生类中来访问
	基类的任何信息.更别提在类外来操作对象中的属性或者方法
	选择保护的方式继承,就不能在类外来操作对象的这些属性,以及方法
	选择公有的继承,那么对于基类中的成员就不能去操作是不可见的,基类中公有的操作,那么派生类也可以像基类一样
	对于基类中保护的成员或者方法,在派生类中可以去操作,但是在类外不能
	
*/
class Teacher :public Person{
};
class Student:public Person{

public:
	
	void getStudent_info(string name,int age,int num){
		Student::_name = name;
		Student::_age = age;
		_num = num;
	}
	//如果是成员函数的隐藏,那么就称之为同名隐藏
	void print(){
		cout << "年龄: " << _age << endl;
		cout << "姓名: " << _name << endl;
		cout << "学号: " << _num << endl;
		cout << "身份证: " << Person::_num << endl;

	}
	

protected:
	//和基类中成员中id号名字相同,那么根据作用域,那么访问的是子类中的这个成员
	int _num;	//学号
	
};
int main(){


	Student stu1;
	Person  per1;
	//stu.print();

	stu1.getStudent_info("li", 18, 001);

	//切割	
#if 0
	/*
		在进行赋值转换的时候,派生类的对象可以赋值给基类,以及基类的指针/引用是可以指向派生类的,
		切片的意思就是将派生类和基类相同的部分切片赋值给基类,但是反过来是不行的
		因为在基类中有没有派生类所新增出的对象这是不知道的,那么需要进行寻找,这个时候
		可能会发生我们的地址错误.导致程序奔溃
	*/
	per1 = stu1;
	//这时候创建了一个基类的指针,他来指向派生类的对象
	Person*	per2 = &stu1;
	//虽然说这种方式也可以将基类的内容转换到派生类中,但是还是不安全的,会存在越界访问的问题
	Student* stu2 = (Student *)per2;
#endif
	//尺寸大小	
#if 0
	//派生类如果继承了基类,那么大小应该在基类的大小之上
	Person test1;
	Teacher test2;
	cout << sizeof(test1._name) << endl;
	cout << sizeof(test2) << endl;

#endif	

	//作用域问题
	/*
		子类或者父类中如果有同名的成员,子类成员将屏蔽掉父类,直接访问自己的成员,这种情况叫隐藏,也是重定义
		要怎么解决呢就是基类::基类成员 

	
	*/
	per1 = stu1;
	
	per1.print();
	stu1.print();
	
	return 0;

	
}


#endif
