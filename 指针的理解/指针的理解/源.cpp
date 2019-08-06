/*在main.c文件中*/
#include "Head.h"

void print(){
	func_static();
}
int main()
{
	int temp2 = func_int();
	//int temp3 = func_static();
	printf("temp2 = %d\n", temp2);
	//printf("temp3 = %d\n", temp3);
	print();

	return 0;
}
