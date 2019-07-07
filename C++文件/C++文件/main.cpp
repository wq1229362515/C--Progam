#include"Test.h"
void menu(){
	cout << "--------------------" << endl;
	cout << "---�ɼ�����ϵͳ-----" << endl;
	cout << "---�����ļ��ɹ�!-------" << endl;
	cout << "---2.ѧ�Ų���-------" << endl;
	cout << "---3.����Ų���-----" << endl;
	cout << "---4.�ɼ���ѯ-------" << endl;
	cout << "---5.ɾ��ѧ��-------" << endl;
	cout << "---6.����-----------" << endl;
	cout << "---7.����ɼ�-------" << endl;
	cout << "---8.��ӡ�ļ�-------" << endl;
	cout << "---0.�˳�ϵͳ-------" << endl;
	cout << "���������ѡ��:" << endl;

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

	stud[0] = { 01, "�ųɳ�", 1, 501, 1334123 };
	stud[1] = { 02, "��ɻ�", 2, 101, 1334123 };
	stud[2] = {03,"���ɷ�",2,101,1334123};
	stud[3] = {04,"������",1,502,1334123};
	stud[4] = {05,"�¶�",2,101,1334123};
	stud[5] = {06,"���",1,502,1334123};
	stud[6] = {07,"��԰԰",2,102,1334123};
	void writeAtxt();
	return;
	
}
/*
	����ļ�1����Ϣ
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
	�����ļ���Ϣ1����ѧ��
*/
void findstudent(){

	int id;
	cout << "����Ҫ����ѧ����ѧ��:" << endl;
	cin >>id;
	while (1){
		for (int i = 0; i < Size; i++){
			if (id == stud[i].id){
				printstudentdata1(stud[i]);
				cout << "���ҳɹ�!" << endl;
				return;
			}
		}
		cout << "���޴���" << endl;
		return;
	}

}
void findstudent_dor(){
	int dor_id;
	cout << "����Ҫ���ҵ������:" << endl;
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
/*���(¼��)�ļ���Ϣ2*/
void inputdata2(){
	info[0] = {01,"A01","��ѧ����",3,66,78,82};
	info[1] = {02,"B03","�ߵ���ѧ",4,78,-1,90};
	info[2] = {01,"B03","�ߵ���ѧ",4,45,-1,88};
	info[3] = {02,"C01","VF      ",3,65,76,66};
	info[4] = {01,"C01","VF      ",4,68,-1,82};
	info[5] = {02,"A01","��ѧ����",4,66,-1,82};
	writeBtxt(info);
	return;
}
/*��ʾ¼����Ϣ*/
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
	����ѧ���ɼ�
*/
void calculateScore(){
	for (int i = 0; i < Itemnum; i++){
		/* ������������ɼ��������ۺϳɼ�*/
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
	cout << "�������ѯѧ����ѧ��" << endl;
	int id;
	cin >> id;
	int i;
	for (i = 0; i < Size; i++){
		if (id == stud[i].id) {
			cout << "ѧ��:" << stud[i].id <<"     "<<"ѧ������:  "<<stud[i].name<< endl;
			break;
		}
	}
	if (i == Size){
		cout << "���޴���!" << endl;
		return;
	}
	//��������˵���������
	//����ɼ�
	calculateScore();
	int count_op = 0;	//�ۼ��޵�ѧ��
	double sumop = 0;	//�ۼƵ�ѧ��
	for (int i = 0; i < Itemnum; i++){
		if (id == info[i].id){
			count_op++;
			sumop +=info[i].e_op;
			cout << "�γ̱��:" << info[i].courseID
				<<"		" << "�γ�����:" << info[i].coursename
				<<"		" << "�ۺϳɼ�:" << info[i].argv_score
				<<"		" << "ʵ��ѧ��:" << info[i].e_op << endl;
		}
	}
	cout << "����:" << count_op << "��,ʵ����ѧ��Ϊ:" << sumop << endl;
	return;
}
void DeleteStudent(){
	cout << "������Ҫɾ��ѧ����Id" << endl;
	int id;
	cin >> id;
	if (id > Size || id <= 0) {
		cout << "������������!�ص����˵�!" << endl;
		return;
	}

	for (int i = id; i < Size; i++){
		stud[i - 1] = stud[i];
	}
	writeAtxt();
	//����һ���µ�info����,���µ��ĵ�ת��
	struct studentinfo Newinfo[Itemnum];
	int count = 0;			//��¼ɾ�˶���������
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
//ͨ��ð�ݷ�����
void Sortscore(){
	calculateScore();
	cout << "���򷽷�: 1.�ۺϳɼ� 2.ѧ��:" << endl;
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
		cout << "����ɹ�!" << endl;
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
		cout << "��ӡ�ļ�һ" << endl;
		outputdata1();
		cout << "��ӡ�ļ���" << endl;
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