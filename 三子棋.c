#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#define m_row 3                                       //���̴�С����
#define m_col 3
char  chess[m_row][m_col];                           //������������

//�˵�����
int  menu () {
	int chooise;
	printf("-------------------\n");
	printf("-----1.��ʼ��Ϸ----\n");
	printf("-----2.�˳���Ϸ----\n");
	printf("-------------------\n");
	printf("���������ѡ��:");
	scanf("%d",&chooise);
	return chooise;
}
//��ʼ������,ÿ�����鶼���Ϊ�ո�
void initchess() {
	int row,col;
	for(row = 0;row<m_row;row++) {
		  for(col = 0;col<m_col;col++)
			  chess[row][col] =' ';
		}
	//���������,�õ��������������
	srand((unsigned int)time(NULL));
}
//�������
void outputchess() {
	int row;
	for(row = 0;row<m_row;row++) {
			printf("| %c  | %c  | %c  |\n",
				chess[row][0],chess[row][1],chess[row][2]);
		 if(row!=m_row-1)
			printf("|----|----|----|\n");
	}
}
//�������
void playermove(){
	int row = 0,col = 0;
   while(1) {
	   printf("����������к���:\n");
	   scanf("%d,%d",&row,&col);
	   //��������������ж�
	   if(row<0||row>=m_row||col<0||col>=m_col) {
		   printf("��������겻�Ϸ�!��������!\n");
		   continue;
	   }
	   //�������һ���ո��Ǳ�ʾ��ռ��
	   if(chess[row][col]!=' ') {
		   printf("��������걻ռ��!��������!\n");
	   //�������һ���ո��Ǳ�ʾ��ռ�ý������ѭ��
		   continue;
	   }
	   //���������'x'��ʾ
	   chess[row][col] = 'x';
	   break;
   }
	printf("����������!\n");
}
//����������ĺ���
int  isfull(){
     int row,col;
	 for(row = 0;row<m_row;row++) {
		 for(col = 0;col<m_col;col++)
			 //���������һ��Ϊ�ո�˵��δ��
			 if(chess[row][col] == ' ')
				 return 0;
	 }
	 //�����������1
	 return 1;
}
//������һ���ַ����� �������̵��ַ���ȷ��˭��Ӯ��
char  checkwinner() {
	int row,col;
	//������Ƿ���Ϊһ����
	for(row = 0;row<m_row;row++){
		if(chess[row][0]==chess[row][1]
		&&chess[row][0]==chess[row][2]) {
	        return  chess[row][0];   
		}
	}
	//������Ƿ���Ϊһ����
	for(col = 0;col<m_col;col++){
		if(chess[0][col]==chess[1][col]
		&&chess[0][col]==chess[2][col]){
			return  chess[0][col];
		}
	}
	//���Խ���
	if(chess[0][0]==chess[1][1]
	&&chess[0][0]==chess[2][2]) {
		return chess[0][0];
	}
    //�������һ���Խ���
	if(chess[0][2]==chess[1][1]
	&&chess[0][2]==chess[2][0]) {
		return chess[0][2];
	}
	//������Щ������������,����û�зֳ�ʤ��
	//��������һ������������ĺ���
	if(isfull()){
		//�������˷���'q'
		return 'q';                            
	}
	//�����������Ļ�˵������δ��,��δ�ֳ�ʤ��
	return ' ';                                  
}
//��������
void computermove(){
     int row,col;
	  printf("��������!\n");
	  while(1){
	   row = rand()%3;
	   col = rand()%3;
      //�����ռ����������
	   if(chess[row][col]!=' ')
		   continue;
	  chess[row][col] = 'o';
	  printf("�����������!\n");
	  break;
	  }
}
//'x'�������
//'o'�������
//'q'�������
void game() {
	//����һ����������ַ�,����ı�˵����ʤ������!
	char winner=' ';   
	initchess();
	while(1) {
		//�������
		outputchess();
		//�������
		playermove();
		//winner����һ�¼�麯����������ֵ
		winner = checkwinner();
		//�����ж�,������ǿո������ж�
		if(winner!= ' ') {
			break;
		}
		//��������
		computermove();
		//winner����һ�¼�麯����������ֵ
		winner = checkwinner();
		//�����ж�,������ǿո������ж�
		if(winner!= ' ') {
			break;
		}
	}
	//����ѭ��˵��ʤ�߻��ߺ�������ж�
	outputchess();
	if(winner== 'x'){
		printf("��һ�ʤ!\n");
	}
	else if(winner== 'o'){
		printf("���Ի�ʤ!\n");
	} 
	else if(winner== 'q') {
		printf("����!\n");
	}
	else 
		printf("�����BUG��!\n");
}
//������
int main() {
   //����һ��ѡ���������ղ˵������ķ���ֵ
   int choose;
   while(1) {
   choose = menu ();
   //ѡ����Ϊ1 ��ʼ��Ϸ
    if(choose == 1) {
		   game();
	}
    else if(choose == 2){
	   break;
   }
   else { 
	   printf("�����������,����������!\n");
       continue;
   }
  }
   return 0;
}