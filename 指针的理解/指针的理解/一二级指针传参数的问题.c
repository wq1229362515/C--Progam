#if 0
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


//�����Ǵ�һ��ָ��Ļ���ʵ�����ԭ�����ַ�������κ�Ӱ��
//��Ϊһ��ָ�봫�����Ļ��൱�ڶ����ֵ�Ŀ�����һ��,������ִ���꺯������֮��,�ǲ����
//�ַ�������κ�Ӱ���
//��Ҫ�μǵ��������Ҫ��ָ����в����Ļ�,��ôһ��ָ�봫��ȥ�ǲ��ܶ������Ӱ���
//������Ҫ�����Ƕ���ָ��
char temp[] = "1234";
int find_char1(char *strs, char val){
	assert(strs != NULL);
	//strs = temp;
	//��������������ı���strs��ָ��,���Ǵ�����ȥ,��Ϊ���˺�������ջ����ռ�ͱ��ͷ���
	//�����return���صĻ�Ҳ��ͽ�͵�,��Ϊ�Ѿ����ͷŵ��˿ռ�,���Խ��յ�Ҳ��һ�����õĿռ�'
	//�ò���������Ҫ�Ľ��
	// str��ջ������ռ䣬�����ֳ��������ַ������ݸ��ƽ���������"xxxxx"��ɾֲ�������
	//�ڽ��и�ֵ��ʱ��,����ַ��������ַ�������,�ַ��������Ǵ����ֻ����������
	//Ҳ����"i am  a boy"�ĵ�ַ��׼ȷ��˵����ʼ��ַ----�����ַ�ָ�� strs
	//����str ��ŵ���һ��ֻ���������ĵ�ַ����ֻ���������ݽ���д�����ǽ�ֹ����������Ӧ�Ĳ���ϵͳ�����ж��Լ�����
	

	//str[]��һ���ַ����飬������������ջ�з���һ���������ռ����ڴ�š�hello���е��ַ��Լ���β����Ȼ����ַ������������ݣ�Ҳ����
	//"hello world"�еĸ����ַ��ͽ�β�����Ƶ����ջ�е������ռ��С�str����������������ʾ�������ջ�ռ����ʼ��ַ������str�д�ŵ���ջ��ַ�������ַ�������ǿ�д�ġ�
	//һ����˵��32λ�����ϣ���Linux�У�ջ��ַ�ռ��3G��0xbfffffff����ʼ����������
	//Ҳ����˵��һ��ֵ�Ŀ�������,��ָ�븳��ַ�ǲ�ͬ��,
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
			//������++����Ļ�,��ı�����ָ��
			//��ͨ����ӷ��ʲ���,���ָ��ĸı�
			if (*(*strs)++ == val){
				return 1;
			}
		}
	}
	return 0;
}
int find_char3(char **strs, char val){
	assert(strs != NULL);
	//������һ����ʱ������strs�ĵ�ַ�����˿���һ��
	//����ͨ��temp���һ��ָ�����жϲ����strs���Ӱ��
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
	//p2 �ʹ�����ǵ�ַ�Ƕ���ָ��ĵ�ַ
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
