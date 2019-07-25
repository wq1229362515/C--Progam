#include<iostream>
using namespace std;



int ret;

int add1(int right, int left){
	return right + left;
}
int* add2(int right, int left){
	ret = right + left;
	return &ret;
}

double add(double left, double right){
	return left + right;
}
double sub(double, double);
double mul(double, double);
double div(double, double);

//回调函数
//const 在*号左边内容不能改变
int comper_ints(void const *a, void const*b){
	if ((*(int *)a) == (*(int *)b)){
		return 0;
	}
	else
		return 1;
}

int compare(int array[],int size, int com_num, int(*comper_ints)(void const *,void const *)){

	int i = 0;
	int temp;
	while (i <= size){
		temp = array[i];
		if (comper_ints(&array[i++], &com_num) == 0){
			break;
		}
	}
	return temp;
}

int main(){

#if 0
	int array[] = { 1, 2, 3 };
	//f是一个数组，里面的元素类型都是指向整形的指针
	//是一个指针数组
	int *f1[] = {&array[0],&array[1],&array[2]};
	//f2是一个指针，根据这个结合的顺序，括号里面的先结合，就是一个指针
	//再结合数组下标符，就是一个数组指针,其中的每一个元素都指向了一个数组的开头
	int(*f2)[3] = &array;


	//函数指针的类型应该是和函数的原型是一致的(也就是说必须把它初始化为某个函数),这样才可以完成相应的地址赋予
	//就像普通指针一样,不可以类型不一样就进行地址赋予操作
	//这个取地址是可以选择的,如果不加的话,编译器也会把它转换为函数指针
	//函数的指针根据结合律,他是一个数组,再结合*地址运算符,是一个指针数组,里面的元素类型都是整形
	//再结合()函数调用符,那么这个数组里面的类型就变为了函数的指针
	//取不取地址这个操作是可以选择的,因为函数名字总是由编译器把它转换为函数指针,&地址操作符只是显式的说明了编译器
	//隐藏执行的任务!
	int(*f3)(int ,int ) = &add1;
	
	//在调用的时候,最底层做的事情就是将这个函数转换为一个函数指针,
	//这个指针指定函数的位置(内存中),然后函数调用符调用这个函数,执行开始于这个地址的代码
	cout << add1(1, 2) << endl;
	//这个函数指针解引用转换为了一个函数名,但是在编译期间在执行函数调用操作符之前又会把它转换回去
	cout << (*f3)(1,2) << endl;

	//这个就是直接换为函数指针,省去了一步操作
	cout << f3(1,2) << endl;

	//是一个函数的指针,返回这个函数返回的类型是一个整形的指针
	int*(*f4)(int, int) = add2;
	//cout << f4(1, 2) << endl;
	cout << *f4(1, 2) << endl;

#endif


	//函数指针数组,也就是函数转移表
	double (*oper[])(double ,double) = { add };

	cout << oper[0](1, 2) << endl;

	//函数指针的另外一个作用就是回调函数

	int  array[] = { 1, 2, 3, 4, 5 };	
	int size = (sizeof(array)/sizeof array[0]);
	ret = compare(array,size, array[4], comper_ints);

	//在C语言中下标的引用和间接访问表达式是一样的.
	//ptr[0] = *(ptr+(0));
	/*
		ptr其实是一个指向整形的常量指针,你不能去改变一个常量的值,除了sizeof和单目运算符&

			int temp1 = ptr[0];
		01218131  mov         eax,4
		01218136  imul        ecx,eax,0
		01218139  mov         edx,dword ptr [ptr]
		0121813C  mov         eax,dword ptr [edx+ecx]
		0121813F  mov         dword ptr [temp1],eax
			int temp2 = *(ptr + (0));
		01218142  mov         eax,dword ptr [ptr]
		01218145  mov         ecx,dword ptr [eax]
		01218147  mov         dword ptr [temp2],ecx
		C的下标检查涉及的开销比较多,在下标运算中,必须插入指令,证实下标表达式的结果和引用元素和指针
		表达式所指向的元素属于同一数组,这个就需要程序中所有数组的位置和长度方面的信息,这会占用一定的内存,
		在程序运行的时候,这些数据必须进行更新,因为保不准你人为的就改变了数据,所以这又会占用一定的时间.
		 
		array[2] =  2[array]

		array是一个常量指针,因此他不可能进行自增自减运算,但是*array是可以的
		不过在ptr没有被初始化之前,对其进行一个解引用也是非法的,因为没有分配内存空间,是一个野指针
		但是此时进行ptr++也是可以的,因为ptr是一个指针变量
	*/
	int *ptr = array;

	int temp1 = ptr[0];
	int temp2 = *(ptr + (0));
	*ptr++;
	
	char str1[] = "hello\n"; //表示一个字符数组元素
	char *str2 = "hello\n"; //表示一个真正的字符串常量

	//创建了matrix ,他可以看做是一个一维数组,包含三个元素,每个元素里面是包含10个整形元素的数组
	//matrix这个名字的值是一个指向它第数组中第一个数组元素的指针,就像一维数组一样,指向了他数组里面的第一个元素
	//那么matrix+1 就是指向了第二个数组
	int matrix[3][8] = { 0 };

	/*
	*(matrix+1)+5		matrix是一个指针,指向了二维数组的第二个元素,也就是matrix[1],他是一个指针,这时候进行+5运算,就是指向了第二行数组元素中的第六个元素
	matrix[1]+5			这个时候其实matrix是一个数组,它代表的是matrix中的第二行元素,下标和解引用的功能是相同的

	*(matrix[1]+5)
	*(*(matrix+1)+5)
	matrix[1][5]
	
	
	*/
	return 0; 
}