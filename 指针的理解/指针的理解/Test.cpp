/*在text.c文件中*/
#include "Head.h"
int func_int()
{
	return 2;
}

static int func_static()
{
	return 3;
}

void print(){
	func_static();
}


