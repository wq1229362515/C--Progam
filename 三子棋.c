#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#define m_row 3                                       //棋盘大小控制
#define m_col 3
char  chess[m_row][m_col];                           //定义棋盘数组

//菜单函数
int  menu () {
	int chooise;
	printf("-------------------\n");
	printf("-----1.开始游戏----\n");
	printf("-----2.退出游戏----\n");
	printf("-------------------\n");
	printf("请输入你的选择:");
	scanf("%d",&chooise);
	return chooise;
}
//初始化棋盘,每个数组都输出为空格
void initchess() {
	int row,col;
	for(row = 0;row<m_row;row++) {
		  for(col = 0;col<m_col;col++)
			  chess[row][col] =' ';
		}
	//随机数生成,让电脑随机生成棋子
	srand((unsigned int)time(NULL));
}
//输出棋盘
void outputchess() {
	int row;
	for(row = 0;row<m_row;row++) {
			printf("| %c  | %c  | %c  |\n",
				chess[row][0],chess[row][1],chess[row][2]);
		 if(row!=m_row-1)
			printf("|----|----|----|\n");
	}
}
//玩家落子
void playermove(){
	int row = 0,col = 0;
   while(1) {
	   printf("请输入你的行和列:\n");
	   scanf("%d,%d",&row,&col);
	   //对玩家输入坐标判断
	   if(row<0||row>=m_row||col<0||col>=m_col) {
		   printf("输入的坐标不合法!重新输入!\n");
		   continue;
	   }
	   //如果不是一个空格那表示被占用
	   if(chess[row][col]!=' ') {
		   printf("输入的坐标被占用!重新输入!\n");
	   //如果不是一个空格那表示被占用结束这次循环
		   continue;
	   }
	   //玩家落子用'x'表示
	   chess[row][col] = 'x';
	   break;
   }
	printf("玩家落子完毕!\n");
}
//检查棋盘满的函数
int  isfull(){
     int row,col;
	 for(row = 0;row<m_row;row++) {
		 for(col = 0;col<m_col;col++)
			 //如果棋盘有一个为空格说明未满
			 if(chess[row][col] == ' ')
				 return 0;
	 }
	 //棋盘满了输出1
	 return 1;
}
//返回了一个字符函数 返回棋盘的字符来确定谁是赢家
char  checkwinner() {
	int row,col;
	//检查行是否连为一条线
	for(row = 0;row<m_row;row++){
		if(chess[row][0]==chess[row][1]
		&&chess[row][0]==chess[row][2]) {
	        return  chess[row][0];   
		}
	}
	//检查列是否连为一条线
	for(col = 0;col<m_col;col++){
		if(chess[0][col]==chess[1][col]
		&&chess[0][col]==chess[2][col]){
			return  chess[0][col];
		}
	}
	//检查对角线
	if(chess[0][0]==chess[1][1]
	&&chess[0][0]==chess[2][2]) {
		return chess[0][0];
	}
    //检查另外一条对角线
	if(chess[0][2]==chess[1][1]
	&&chess[0][2]==chess[2][0]) {
		return chess[0][2];
	}
	//除了这些还有棋盘满了,但是没有分出胜负
	//所以设立一个检查棋盘满的函数
	if(isfull()){
		//棋盘满了返回'q'
		return 'q';                            
	}
	//如果都不满足的话说明棋盘未满,且未分出胜负
	return ' ';                                  
}
//电脑落子
void computermove(){
     int row,col;
	  printf("电脑落子!\n");
	  while(1){
	   row = rand()%3;
	   col = rand()%3;
      //如果被占用了重新下
	   if(chess[row][col]!=' ')
		   continue;
	  chess[row][col] = 'o';
	  printf("电脑落子完毕!\n");
	  break;
	  }
}
//'x'代表玩家
//'o'代表电脑
//'q'代表和棋
void game() {
	//定义一个检查数组字符,如果改变说明有胜负产生!
	char winner=' ';   
	initchess();
	while(1) {
		//输出棋盘
		outputchess();
		//玩家落子
		playermove();
		//winner接受一下检查函数返回来的值
		winner = checkwinner();
		//进行判断,如果不是空格跳出判断
		if(winner!= ' ') {
			break;
		}
		//电脑落子
		computermove();
		//winner接受一下检查函数返回来的值
		winner = checkwinner();
		//进行判断,如果不是空格跳出判断
		if(winner!= ' ') {
			break;
		}
	}
	//跳出循环说明胜者或者和棋产生判断
	outputchess();
	if(winner== 'x'){
		printf("玩家获胜!\n");
	}
	else if(winner== 'o'){
		printf("电脑获胜!\n");
	} 
	else if(winner== 'q') {
		printf("和棋!\n");
	}
	else 
		printf("代码出BUG了!\n");
}
//主函数
int main() {
   //定义一个选择函数来接收菜单函数的返回值
   int choose;
   while(1) {
   choose = menu ();
   //选择函数为1 开始游戏
    if(choose == 1) {
		   game();
	}
    else if(choose == 2){
	   break;
   }
   else { 
	   printf("你的输入有误,请重新输入!\n");
       continue;
   }
  }
   return 0;
}