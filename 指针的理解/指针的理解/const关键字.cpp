#if 0
/*

#include<iostream>
#include<string>
using namespace std;

int main() {

	string s1,s2,s3;
	getline(cin, s1);
	getline(cin, s2);
	int flag = 0;
	auto it1 = s1.begin();
	auto it11 = s1.begin();
	auto it2 = s2.begin();
	auto it22 = s2.begin();
	while (it1 != s1.end()){
		//如果相等字母出现的时候,那么就没必要继续遍历了
		if (*it1 == *it2){
			//s1的这个字母就要跳过了,
			it11++;
			it1 = it11;
			continue;
		}
		it2++;
		//到末尾了也没有相等的字母的时候
		if (it2 == s2.end()){
			s3 += *it11;
			it11++;
			it1 = it11;
			it2 = it22;
		}
	}

	cout << s3 << endl;



	return 0;
}

*/




/*
int main(){

	int n = 2;
	int arr[6];
	for (int i = 0; i < 6; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 6 - i - 1; j++){
			if (arr[j] < arr[j + 1]){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	int sum = 0;
	for (int i = 0,ret = 1 ; ret <= 2*n-1 && i <6; i += 2,ret+=2 ) {
		sum += arr[ret];
	}

	printf("%d", sum);

	return 0;
}
*/






#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int  Add(const int * right, const int *left){
	//*right = 10;
	int temp = *right + *left;
	return temp;
}
int main1()
{

	int  temp = 10;
	int temp2 = 100;
	const int  *a = &temp;
	
	const int Max = 10;
	int const Max2 = Max;

	//int  arr[Max];
	//Max2 = 30;
	//由于使用了const修饰NUM，使得NUM为只读，因此尝试对NUM再次赋值的操作是非法的，编译器将会报错。
	//正因如此，如果需要使用const修饰一个变量，那么它只能在开始声明时就赋值，否则后面就没有机会了



	//const是constant的简写，是不变的意思。但并不是说它修饰常量，而是说它限定一个变量为只读。

	//const用来修饰常量,数组和指针

	//const 位于*  左侧的时候表明修饰指针所指向的变量的内容不能被修改
	//也就是说通过a指针不能修改temp指向的内容
	//*a = 100;      错误
	//int* a1 = &temp;
	//*a1 = 20;
	//但是可以修改指针的指向,也就是说可以让a指向别的int 类型的数据
	//a = &temp2;    //可以修改指针a指向变量
	//*左指向变 , *右 内容变

	int* const  b= &temp;
	//const 位于* 右侧的时候表示指针指向的变量不能变,就是说b原来指向temp ,以后也只能指向temp
	//但是可以通过解引用来改变指针变量的内容
	//b = &temp2;
	*b = 1001;

	//*左*右指向内容都不可变
	const int  * const c = &temp;

	//char *strncpy(char *dest, const char *src, size_t n);//字符串拷贝函数
	//字符串拷贝函数的源字符串不能改变,const在左指向变量的内容不可改变

	//因此在我们编码的时候,如果不需要修改传过来参数内容那么可以增加const关键词,来讲传进来的参数变为
	//只读保护,这样可以防止数据被改变
	

	//const关键字告诉了编译器，它修饰的变量不能被改变，如果代码中发现有类似改变该变量的操作，那么编译器就会捕捉这个错误。
	//同样的也告诉了程序员,这段代码的里面的参数是不可以被修改的
	//但是使用强转也可以改变const


	//判断方法:从右到左去做出判断 
	//int const  *a; 
	//可以理解 (*a) 是一个整体, const 用来修饰的是(*a);

	//int *const a2;
	//可以理解为 (*const a) 是一个整体 

	
	int * d = (int *)a;
	//我们人为的也可以对a的类型做出修改,但是没有人会这么做
	//


	const int  temp3 = 10;
	int *ptr = (int  *)&temp3;
	*ptr = 30;
	cout << temp3 <<" "<<*ptr << endl;

	//const 在编译阶段起的作用,所以const在编译期间,已经做出了优化,也就是把temp3在编译期间已经当做了10来处理了
	//但是在运行的时候还会运行到这个代码,所以他的指向的内容还是会发生改变
	//但是在C编译器中,编译器并没有当成常数处理,而是视为一个受到读保护的变量而已

	//还有一个要注意的地方：C++编译器只能对内置数据类型（int, float...）做常数替换，而对于像结构体\类这样的非内置数据类型编译器不知道怎么替换，所以就不替换，


	//总结
		/*const关键字让编译器帮助我们发现变量不该被修改却被意外修改的错误。
		const关键字修饰的变量并非真正意义完完全全的只读。
		对于不该被修改的入参，应该用const修饰，这是const使用的常见姿势。
		const修饰的变量只能正常赋值一次。
		不要试图将const数据的地址赋给普通指针。
		不要忽略编译器的警告，除非你很清楚在做什么。
		虽然可以通过某种不正规途径修改const修饰的变量，但是永远不要这么做。
		*/

	return 0;
}
#endif
