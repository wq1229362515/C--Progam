#include"Test.h"
void menu(){
	cout << "--------------------" << endl;
	cout << "---成绩管理系统-----" << endl;
	cout << "---加载文件成功!-------" << endl;
	cout << "---2.学号查找-------" << endl;
	cout << "---3.宿舍号查找-----" << endl;
	cout << "---4.成绩查询-------" << endl;
	cout << "---5.删除学号-------" << endl;
	cout << "---6.排序-----------" << endl;
	cout << "---7.计算成绩-------" << endl;
	cout << "---8.打印文件-------" << endl;
	cout << "---0.退出系统-------" << endl;
	cout << "请输入你的选择:" << endl;

	return;
}
void writeAtxt(){
	ofstream outfile("A.txt", ios::binary);
	if (!outfile){
		cerr << "open error!" << endl;
		abort();
	}
	for (int i = 0; i < Size; i++){
		outfile.write((char*)&stud[i], sizeof(stud[i]));
	}
	outfile.close();
	return;
}
void inputdata1(){

	stud[0] = { 01, "张成成", 1, 501, 1334123 };
	stud[1] = { 02, "李成华", 2, 101, 1334123 };
	stud[2] = {03,"王成凤",2,101,1334123};
	stud[3] = {04,"张明明",1,502,1334123};
	stud[4] = {05,"陈东",2,101,1334123};
	stud[5] = {06,"李果",1,502,1334123};
	stud[6] = {07,"张园园",2,102,1334123};
	void writeAtxt();
	return;
	
}
/*
	输出文件1的信息
*/
void printstudentdata1(struct student stud){
		cout << "id :" << stud.id << endl;
		cout << "name :" << stud.name << endl;
		cout << "sex :" << stud.sex << endl;
		cout << "dumnum :" << stud.donumber << endl;
		cout << "phonenumber :" << stud.phonenumber << endl;
		cout << endl;
	return;
}
void outputdata1(){
	ifstream infile("A.txt", ios::binary);
	if (!infile){
		cerr << "open error!" << endl;
		abort();
	}
	for (int i = 0; i < Size; i++){
		infile.read((char *)&stud[i],sizeof( stud[i]));
	}
	infile.close();
	for (int i = 0; i < Size; i++){
		printstudentdata1(stud[i]);
	}
}

/*
	根据文件信息1查找学生
*/
void findstudent(){

	int id;
	cout << "输入要查找学生的学号:" << endl;
	cin >>id;
	while (1){
		for (int i = 0; i < Size; i++){
			if (id == stud[i].id){
				printstudentdata1(stud[i]);
				cout << "查找成功!" << endl;
				return;
			}
		}
		cout << "查无此人" << endl;
		return;
	}

}
void findstudent_dor(){
	int dor_id;
	cout << "输入要查找的宿舍号:" << endl;
	cin >> dor_id;
	for (int i = 0; i < Size; i++){
		if (stud[i].donumber == dor_id){
			printstudentdata1(stud[i]);
		}
	}
}

//--------------------------------------
void writeBtxt(struct studentinfo info[]){
	ofstream outfile("B.txt", ios::binary);
	if (!outfile){
		cerr << "open error!" << endl;
		abort();
	}
	for (int i = 0; i < Itemnum; i++){
		outfile.write((char*)&info[i], sizeof(info[i]));
	}
	outfile.close();
	return;
}
/*添加(录入)文件信息2*/
void inputdata2(){
	info[0] = {01,"A01","大学物理",3,66,78,82};
	info[1] = {02,"B03","高等数学",4,78,-1,90};
	info[2] = {01,"B03","高等数学",4,45,-1,88};
	info[3] = {02,"C01","VF      ",3,65,76,66};
	info[4] = {01,"C01","VF      ",4,68,-1,82};
	info[5] = {02,"A01","大学物理",4,66,-1,82};
	writeBtxt(info);
	return;
}
/*显示录入信息*/
void outputdata2(){
	ifstream infile("B.txt", ios::binary);
	if (!infile){
		cerr << "open error!" << endl;
		abort();
	}
	for (int i = 0; i < Itemnum; i++){
		infile.read((char *)&info[i], sizeof(info[i]));
	}
	infile.close();
	calculateScore();
	cout << "Id" << "     " << "coueseID" << "      "
		<< "coursename" << "      " << "op" << "     "
		<< "n_score" <<"      "<<"e_score"<<"     "<<"j_score"
		<< "    " << "argv_score" << "  " << "e_op"<<endl;
	for (int i = 0; i < Itemnum; i++){
		cout << info[i].id << "      " << info[i].courseID << "           "
			<< info[i].coursename << "        " << info[i].op << "        "
			<<info[i].n_score<<"          "<<info[i].e_score<<"          "
			<<info[i].j_score<<"         "<<info[i].argv_score<<"          "<<info[i].e_op<<endl;
		cout << endl;
	}
}

/*
	计算学生成绩
*/
void calculateScore(){
	for (int i = 0; i < Itemnum; i++){
		/* 挨个遍历分项成绩并计算综合成绩*/
		if (info[i].e_score == -1) {
			info[i].argv_score = info[i].n_score *0.3 + info[i].j_score*0.7;
		}
		else {
			info[i].argv_score = info[i].n_score*0.15 + info[i].e_score*0.15 + info[i].j_score*0.7;
		}
		switch(info[i].argv_score/10){
			case 10:
			case 9:info[i].e_op = info[i].op; break;
			case 8:info[i].e_op = info[i].op*0.8; break;
			case 7:info[i].e_op = info[i].op*0.75; break;
			case 6:info[i].e_op = info[i].op*0.60; break;
			default:info[i].e_op = info[i].op * 0; break;
		}
	}
	return;
}
void Scoreinquire(){
	cout << "请输入查询学生的学号" << endl;
	int id;
	cin >> id;
	int i;
	for (i = 0; i < Size; i++){
		if (id == stud[i].id) {
			cout << "学号:" << stud[i].id <<"     "<<"学生姓名:  "<<stud[i].name<< endl;
			break;
		}
	}
	if (i == Size){
		cout << "查无此人!" << endl;
		return;
	}
	//能走下来说明有这个人
	//计算成绩
	calculateScore();
	int count_op = 0;	//累计修的学科
	double sumop = 0;	//累计的学分
	for (int i = 0; i < Itemnum; i++){
		if (id == info[i].id){
			count_op++;
			sumop +=info[i].e_op;
			cout << "课程编号:" << info[i].courseID
				<<"		" << "课程名称:" << info[i].coursename
				<<"		" << "综合成绩:" << info[i].argv_score
				<<"		" << "实际学分:" << info[i].e_op << endl;
		}
	}
	cout << "共修:" << count_op << "科,实际总学分为:" << sumop << endl;
	return;
}
void DeleteStudent(){
	cout << "请输入要删除学生的Id" << endl;
	int id;
	cin >> id;
	if (id > Size || id <= 0) {
		cout << "您的输入有误!回到主菜单!" << endl;
		return;
	}

	for (int i = id; i < Size; i++){
		stud[i - 1] = stud[i];
	}
	writeAtxt();
	//创建一个新的info对象,将新的文档转移
	struct studentinfo Newinfo[Itemnum];
	int count = 0;			//记录删了多少条数据
	for (int i = 0; i < Itemnum; i++){
		if (id == info[i].id) {
			count++;
			continue;
		}
		else {
			int j = 0;
			Newinfo[j++] = info[i];
		}
	}
	Size--;
	writeBtxt(Newinfo); 
	return;
}
//通过冒泡法排序
void Sortscore(){
	calculateScore();
	cout << "排序方法: 1.综合成绩 2.学分:" << endl;
	int flag;
	cin >> flag;
	if (flag == 1){
		for (int i = 0; i < Itemnum; i++){
			for (int j = 0; j < Itemnum - 1 - i; j++){
				if (info[j].argv_score > info[j + 1].argv_score){
					studentinfo temp = info[j];
					info[j] = info[j + 1];
					info[j + 1] = temp;
				}
			}
		}
		cout << "排序成功!" << endl;
		cout << "Id" << "     " << "coueseID" << "      "
			<< "coursename" << "      " << "op" << "     "
			<< "n_score" << "      " << "e_score" << "     " << "j_score"
			<< "    " << "argv_score" << "  " << "e_op" << endl;
		for (int i = 0; i < Itemnum; i++){
			cout << info[i].id << "      " << info[i].courseID << "           "
				<< info[i].coursename << "        " << info[i].op << "        "
				<< info[i].n_score << "          " << info[i].e_score << "          "
				<< info[i].j_score << "         " << info[i].argv_score << "          " << info[i].e_op << endl;
			cout << endl;
		}

	}
	return;
}
void Func(int choose){
	if (choose == 2) {
		findstudent();
	}
	if (choose == 3){
		findstudent_dor();
	}
	if (choose == 4){
		Scoreinquire();
	}
	if (choose == 5){
		DeleteStudent();
	}
	if (choose == 6){
		Sortscore();
	}
	if (choose == 7){
		calculateScore();
	}
	if (choose == 8){
		cout << "打印文件一" << endl;
		outputdata1();
		cout << "打印文件二" << endl;
		outputdata2();
		system("pause");
	}
	if (choose == 0){
		exit(1);
	}
}


int main(){
	inputdata1();
	inputdata2();
	while (1) {
		menu();
		int choose;
		cin >> choose;
		Func(choose);
	}
	return 0;
}