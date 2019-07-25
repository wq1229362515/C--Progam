#include<iostream>
using namespace std;



/*

	每一个对象中除了存储自己的成员,还要存储一个虚函数表指针,_vfptr  v代表vitural ,f代表function的意思
	每一个含有虚函数的对象里面都会存在这样一个虚函数表指针,因为虚函数的地址要被放到虚函数的表中去
	虚函数表简称虚表


*/
#if 0
class Base {
public:    virtual void Func1()    { cout << "Base::Func1()" << endl; }

		   virtual void Func2()    { cout << "Base::Func2()" << endl; }

		   void Func3()    { cout << "Base::Func3()" << endl; }

private:    int _b = 1;
};

class Derive : public Base { 
public:    virtual void Func1()    { cout << "Derive::Func1()" << endl; }

private:    int _d = 2;

};
/*
	1.	可以看到的是d对象也有自己虚函数指针,也维护着自己的虚函数表
		d对象由两部分组成第一部分是继承下来父类的成员变量,虚函数指针就是存在于这个部分
		第二部分就是自己的成员
	2.	b和d对象的虚表不一样,因为d对象中有自己重写的虚函数func1 所以存储的这个地址就是关于自己
		这个虚函数的地址,所以构成了覆盖,就是指虚函数的覆盖.重写是语法的叫法,覆盖是原理层的叫法
	3.	
*/
int main(){
	Base b;
	Derive d;
	return 0;
}
#endif

#if 0
class Person{

public:
	virtual void buyticket(){
		cout << "成人票" << endl;
	}

};
class Student :public Person{
public:
	virtual void buyticket(){
		cout << "学生票" << endl;
	}
};

void Testbuyticket(Person &p){
	p.buyticket();
}
int main(){


	Person per;
	Testbuyticket(per);				//运用多态的调用是发生在函数运行期间来调用的
	per.buyticket();				//虽然这个buyticket是一个虚函数,但是在调用的时候是对象来调用的,
									//不满足多态的条件,多态的条件是必须用基类的引用或者指针来调用
									//被调用的函数必须是虚函数
	/*
		动态的绑定(晚绑定):在程序的编译期间确定了程序的行为,也叫静态多态----函数的重载
		我的理解是你得让编译器知道你在这个时候是要运行什么函数,或者要进行什么参数的加载
		如果函数并不知道你具体的加载内容,那么就在你程序运行的时候再来确定你的具体行为是什么
		静态的绑定(静态的绑定):具体就是根据具体拿到的类型来确定程序的具体的行为
		所以说这个对象的调用不满足第一点,在他调用的时候其实是,在程序编译器来解决的事情


		普通的对象在去调用虚函数或者是成员的普通函数的时候,速度是一样快的,
		但是如果是指针或者是对象的引用去调用虚函数的时候,那么肯定是普通对象快一点,
		因为在我们调用的时候,虚函数是要去访问这个虚函数表的,这也是操作
	*/


	Student stu; 
	Testbuyticket(stu);

	return 0;
}



#endif 

/*
		二.设法来拿到这个虚函数的地址
		利用虚函数表中最后一列内容肯定是NULL的特性


*/

typedef void(*vptr)();					//定义一个函数指针
typedef void(*v_ptr[])();				//函数指针数组(int )
typedef int*   a;
class Base {
public:    virtual void Func1()
			{
			   cout << "Base::Func1()" << endl;
			}

		   virtual void Func2()    { cout << "Base::Func2()" << endl; }

		   void Func3()
		   {
			   cout << "Base::Func3()" << endl;
		   }

private:
	int _b = 1;
};

class Derive : public Base {
public: 
	virtual void Func1()
	{
		   cout << "Derive::Func1()" << endl;
	}
private:   
	int _d = 2;
};

void Test_vptr(vptr ptr[]){
	while (ptr++ != nullptr){
		cout << ptr << endl;
	}

}

int main(){
	/*
		首先要取到这个虚表指针,这个虚表指针就是类的前 4个字节
		也就是说b的地址内容就是存的这个虚表指针,那么需要将其转换为一个函数指针

	*/

	Base b;
	Derive d;

	vptr _ptr1 = (vptr)(*(int *)&b);
	vptr *_ptr2 = (vptr*)(*(int *)&b);

	Test_vptr(_ptr2);

	
	



	return 0;
} 