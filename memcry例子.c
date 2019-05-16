#include <stdio.h>
#include<string.h>
void Test(){
	char string[10] = "\0";
	char *str = string;
	memcpy(string,"hello",5);
	printf("%s\n",str);
}
int main(){
	Test();
	return 0;
}