#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>
//����һ��ָ��ָ���ַ���
//����һ���ַ�ָ������ char *str[]  
//str�Ⱥ�[]���Ȼ����������ݶ���ָ��,һ��һ��ָ��������
int main2(){
	 char temp[1024];
	 char * ptr = temp;
	 char *argv[32] = {'\0'};
	 int argc = 0;
	 gets(temp);
	 while (*ptr){
		 //������ǿհ��ַ��Ļ��ͽ���
		 if (!isspace(*ptr)){
			 //����֮�󽫵�ַ����argv����
			 argv[argc++] = ptr;
				//Ȼ��ָ����ǰ�������ո�ͣ��������,��˵��һ�����ʽ�����
				 while (!isspace(*ptr) && *ptr != '\0'){
					  ptr++;
				 }
				//�����ж�һ���ǿո��ǽ�����
				//�ո��ASCII���'\0'����һ����
				 //����'\0'��ʱ��˵���ַ���������
			 if (*ptr == '\0'){
				break;
			 }
			 //���ǿո�������,��Ϊ'\0'Ȼ��Ϳ��Խض��ַ�����
			 //�ض��ַ�����ʱ��avgr��������Ԫ�ؾͼ�¼�������ֹ��
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

