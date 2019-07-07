#include"Test.h"

void inputdata1(){

	stud[0] = { 01, "张成成", 1, 501, 1334123 };
	stud[1] = { 02, "李成华", 2, 101, 1334123 };
	stud[2] = {03,"王成凤",2,101,1334123};
	stud[3] = {04,"张明明",1,502,1334123};
	stud[4] = {05,"陈东",2,101,1334123};
	stud[5] = {06,"李果",1,502,1334123};
	stud[6] = {07,"张园园",2,102,1334123};

	ofstream outfile("A.txt", ios::binary);
	if (!outfile){
		cerr <<  "open error!" << endl;
		abort();
	}
	for (int i = 0; i < Max; i++){
		outfile.write((char*)&stud[i], sizeof(stud[i]));
	}
	outfile.close();
}

void outputdata1(){
	ifstream infile("A.txt", ios::binary);
	if (!infile){
		cerr << "open error!" << endl;
		abort();
	}
	for (int i = 0; i < Max; i++){
		infile.read((char *)&stud[i],sizeof( stud[i]));
	}
	infile.close();
	for (int i = 0; i < Max; i++){
		cout << "id :" << stud[i].id << endl;
		cout << "name :" << stud[i].name<< endl;
		cout << "sex :" << stud[i].sex << endl;
		cout << "dumnum :" << stud[i].donumber << endl;
		cout << "phonenumber :" << stud[i].phonenumber << endl;
		cout << endl;
	}
}

void findstudent(){

	int id;
	cout << "输入要查找学生的学号:" << endl;
	cin >>id;
	while (1){
		for (int i = 0; i < Max; i++){
			if (id == stud[i].id){
				cout << "id :" << stud[i].id << endl;
				cout << "name :" << stud[i].name << endl;
				cout << "sex :" << stud[i].sex << endl;
				cout << "dumnum :" << stud[i].donumber << endl;
				cout << "phonenumber :" << stud[i].phonenumber << endl;
				cout << endl;
				return;
			}
		}
		cout << "查无此人" << endl;
		return;
	}

}
int main(){


	inputdata1();		//输入学生文件信息1
	outputdata1();		//显示学生信息1

	findstudent();
	return 0;
}