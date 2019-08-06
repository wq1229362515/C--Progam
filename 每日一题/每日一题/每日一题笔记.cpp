//1. for (x = 0, y = 0; (y = 123) && (x < 4); x++); 执行四次,因为y = 123 

//2.输出格式
/*
［标志］［输出最少宽度］［．精度］［长度］类型  
printf("%s , %5.3s\n", "computer", "computer");
		computer		
"%m.nf"：输出浮点数，m为宽度，n为小数点右边数位
"%3.1f"    输入3852.99
输出			3853.0

int a=10 ; double b=3.14 ; 则表达式 'A'+a+b 被转换为double类型



3.在32位cpu上选择缺省对齐的情况下，有如下结构体定义： 
struct A{
unsigned a : 19;
unsigned b : 11;
unsigned c : 4;
unsigned d : 29;
char index;
};
则sizeof（struct A）的值为（）
由于在32位cpu上选择缺省对齐的情况下，所以每行支持4个字节即32bit
一行是32个bit位 
19+11  第一行 4字节
4	   第二行 4字节
29	   第三行 4字节
8      第四行 内存对齐 4字节

sizeof(A) 16 字节



4.以下不是double compare(int,int)的重载函数的是()
A int compare(double,double) 
B double compare(double,double) 
C double compare(double,int) 
D int compare(int,int)


函数被重载的特征：

相同的范围（在同一个类中）； 函数名字相同但函数类型可以不同，参数类型或个数不同

重载与函数的类型没有关系,功能的不同主要来自于参数,D选项中参数是相同的,那么编译器无法做出区分


由多个源文件组成的C程序，经过编辑、预处理、编译、链接等阶段会生成最终的可执行程序。下面哪个阶段可以发现被调用的函数未定义？
A 预处理 
B 编译 
C 链接 
D 执行

earse函数
在进行单个元素删除后，传入的迭代器指向不变，仍然指向被删除元素的位置，而被删除元素之后的所有元素都向前移动一位，
也就是该迭代器实际上是指向了原来被删除元素的下一个元素。
其实vector还维持着一个last指针，开始的时候=end，随着删除，last前移，最终vector的size是last-begin，
或者我们可以认为end值改变了，但最初传入的end没有变。



delete只会调用一次析构函数，而delete[]还会调用后续所有对象的析构函数。
当数据类型为基本数据类型时，用delete和delete[]都可以，因为基本数据类型没有析构函数。

64位系统下指针大小为8字节
short 为8字节


n=0;for(ch=getchar();ch!='\n';n++);
只会执行一次 getchar函数


if(b!=2||c--!=3)	//当b条件成立的时候,那么c条件就不会被执行到了

类成员的缺省访问权限是私有的



使用const比使用define有一下几种好处：
（1）const会进行数据类型检查，而define不会
（2）const效率高，因为const定义的常量，没有在内存中存储，而是在符号表中，每次访问这个数据的时候，少了从内存中读取和存储过程，效率高。
因此尽量还是使用const常量


代码生成阶段的主要任务是：
把中间代码变换成依赖具体机器的目标代码


int i=0,a=1,b=2,c=3; i=++a||++b||++c; printf("%d %d %d %d",i,a,b,c);
执行++a之后为真就不再去执行其他的
1 2 2 3 


在C++中，mutable也是为了突破const的限制而设置的。
被mutable修饰的变量，将永远处于可变的状态，即使在一个const函数中。

x是一个行列数均为1000二维数组，下面代码效率执行最高的是（）
x[i][j] = +x[i][j]
因为顺序寻址的速度是最快的

const int a = 10;
int *ptr = (int *)&a;
*p = 20;
cour<<a<<*p<<endl;
在编译期间,编译器看见这个a就会替换成10 ,所以一开始打印的时候是0 但是在程序执行期间会改变a那块地址的内容所以取地址之后解引用一下就是20


struct Test {
	Test( int ) {}
	Test() {}
	void fun() {}
};
void main( void )
{
	Test a(1);
	a.fun();
	Test b();
	b.fun();
}

 Test b();
 是声明了一个函数,那么b.fun(),肯定是不会成功的

 在类的构造函数中,使用默认的构造函数是不能加小括号的,加上小括号就成为了一个函数
 Test b; 才是真正的创建了一个对象

 char *p = "abc";
 char *q = "abc123";
 //字符串的常量没办法赋值的
 while (*p = *q)
 printf("%c %c",*p, *q);



  #include <stdio.h>
  int main(){
    long long a = 1, b = 2, c = 3;
    printf("%d %d %d\n", a, b, c);
   return 0;
  }

	long long 是一个八字节的数字
	%d只能打印4字节的位
	函数调用都是从右往左来进行入栈的,栈的方向是从高往低走的
	小端模式这些低地址数据在低位

	高位                  低位
	0000 0011 0000 0010 0000 0001
					2	 0	   1
	在进行数据操作的时候进行数据取出的时候 a = 1 ,b = 0,c = 2

	template <class T> 
	struct sum {  
		static void foo(T op1 , T op2){   
			cout << op1 <<op2;   
		} 
	}; 
		sum::foo(1,3);

		既然是函数模板,那么在调用的时候就需要类型的说明,否则是不能编译的



		class A{
		public:
		A(){p();}
		virtual void p(){print("A")}
		virtual ~A(){p();}
		};
		class B:public A{
		public:
		B(){p();}
		void p(){print("B")}
		~B(){p();}
		};
		int main(int, char**){
		A* a=new B();
		delete a;
		}


题目想构造一个B类的对象，B继承自A，所示首先构造A，A中构造函数调用P，虽然P是虚函数，按理来说应该动态绑定，
但是此时B并没有被构造，所以只能调用自己的P函数（输出A），接下来构造B，调用B的P函数（输出B），
接着析构从派生类到基类，首先析构B，调用B的P函数（输出B），接着调用A的析构函数，
按理来说应该动态绑定，但是此时B已经被析构，所以只能调用自己的P函数（输出A）。









*/
