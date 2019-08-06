#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>
//定义一个指针指向字符串
//定义一个字符指针数组 char *str[]  
//str先和[]结合然后里面的内容都是指针,一个一个指向了数据
int main2(){
	 char temp[1024];
	 char * ptr = temp;
	 char *argv[32] = {'\0'};
	 int argc = 0;
	 gets(temp);
	 while (*ptr){
		 //如果不是空白字符的话就进入
		 if (!isspace(*ptr)){
			 //进入之后将地址传给argv数组
			 argv[argc++] = ptr;
				//然后指针向前走遇见空格停下来跳出,就说明一个单词结束了
				 while (!isspace(*ptr) && *ptr != '\0'){
					  ptr++;
				 }
				//先来判断一下是空格还是结束符
				//空格的ASCII码和'\0'不是一回事
				 //当有'\0'的时候说明字符串结束了
			 if (*ptr == '\0'){
				break;
			 }
			 //当是空格走下来,置为'\0'然后就可以截断字符串了
			 //截断字符串这时候avgr这个数组的元素就记录到这里截止了
			 *ptr = '\0';
			 ptr++;
			 continue;
		}
		 ptr++;
	}
	 for (int i = 0; i < argc; i++){
		printf("argv[%d] = %s\n", i, argv[i]);
	}
	return 0;
}

