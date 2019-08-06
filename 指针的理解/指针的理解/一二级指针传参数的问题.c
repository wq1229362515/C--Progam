#if 0
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


//当我们传一级指针的话其实不会对原来的字符串造成任何影响
//因为一级指针传过来的话相当于对这个值的拷贝了一份,在我们执行完函数操作之后,是不会对
//字符串造成任何影响的
//需要牢记的是如果需要对指针进行操作的话,那么一级指针传过去是不能对其造成影响的
//我们需要传的是二级指针
char temp[] = "1234";
int find_char1(char *strs, char val){
	assert(strs != NULL);
	//strs = temp;
	//在这个代码段里面改变了strs的指向,但是带不出去,因为出了函数调用栈这个空间就被释放了
	//如果用return返回的话也是徒劳的,因为已经被释放掉了空间,所以接收的也是一段无用的空间'
	//得不到我们想要的结果
	// str在栈上申请空间，将文字常量区的字符串内容复制进来，所以"xxxxx"变成局部变量。
	//在进行赋值的时候,这个字符串就是字符串常量,字符串常量是存放于只读数据区的
	//也就是"i am  a boy"的地址，准确来说是起始地址----赋给字符指针 strs
	//所以str 存放的是一个只读数据区的地址，对只读区的数据进行写操作是禁止，具体由相应的操作系统进行判断以及处理。
	

	//str[]是一个字符数组，编译器首先在栈中分配一定的连续空间用于存放“hello”中的字符以及结尾符，然后把字符串常量的内容，也就是
	//"hello world"中的各个字符和结尾符复制到这个栈中的连续空间中。str是数组名，用来表示这个连续栈空间的起始地址，所以str中存放的是栈地址，这个地址的数据是可写的。
	//一般来说，32位机器上，在Linux中，栈地址空间从3G（0xbfffffff）开始向下增长。
	//也就是说是一个值的拷贝过程,与指针赋地址是不同的,
	char temp[] = "hello world";

	strs = temp;
	printf("%s\n", strs);
	return 1;
	while (*strs != (void*)NULL){
		while (*strs != '\0'){
			if (*strs++ == val){
				return 1;
			}
		}
	}
	return 0;
}

int find_char2(char **strs, char val){
	assert(strs != NULL);
	while (*strs != (void*)NULL){
		while (*strs != '\0'){
			//这样做++运算的话,会改变数组指针
			//会通过间接访问操作,造成指针的改变
			if (*(*strs)++ == val){
				return 1;
			}
		}
	}
	return 0;
}
int find_char3(char **strs, char val){
	assert(strs != NULL);
	//定义了一个临时变量对strs的地址进行了拷贝一份
	//我们通过temp这个一级指针来判断不会对strs造成影响
	char *temp;
	while ((temp = *strs++)!= NULL){
		while (*temp != '\0'){
			if (*temp++ == val){
				return 1;
			}
		}
	}
	return 0;
}
/*
int b = 520;
void Func1(int *str){
	//*str = 10;
	str = &b;

}
void Func2(int **str){
	
	*str = &b;

}
*/
/*void swap(int left, int right){
	int temp = left;
	left = right;
	right = temp;
}*/
int temp2 = 100;
void swap(int* left, int* right){
	int temp =*left;
	*left = *right;
	*right = temp;
	left = &temp2;
	*left = 500;
}
void change1(char *str2){
	str2 = "11";

	return;
}
void change2(char **str2){
	*str2 = "11";

	return;
}

int main1(){
#if 0 
	/*
	int a = 10;
	int *p1;
	p1 = &a;
	int ** p2;
	//p2 就代表的是地址是二级指针的地址
	p2 = &p1;
	system("pause");
	*/
	int a = 10;
	int  *ptr = &a;
	//ptr = *ptr - 10;
	//*ptr = *ptr - *(int *)10;
	*ptr = 10;


	//int  b = NULL;
	int *ptr1 = NULL;

	//char *str = temp;
	//*str = "hello world";
	const char *str = "i am a boy";
	int i = find_char1(str, 'a');
	printf("%s\n", str);
	int j = find_char2(&str, 'a');
	printf("%d\n", i);
	printf("%s\n", str);

	//int *ptr3;
	//*ptr3 = 10;


	int *ptr4 = (int*)malloc(sizeof(int));
	*ptr4 = 10;
;
	double add = 10;
	double *ptr5 = &add;

	return 0;
#endif


	/*
	char *str = (char*)malloc(sizeof(char)*20);
	str = "1";
	Func(str);
	printf("%s\n", str);

	*/


	/*int a = 100;
	int *ptr = &a;
	Func(ptr);
	printf("%d", *ptr);
	*/

	int a = 1;
	//Func2(ptr);

	int b = 2;
	//swap(a, b);
	swap(&a, &b);

	char *str1 = "1234";
	change1(str1);
	change2(&str1);
	return 0;
}

#endif
