#include<iostream>

using namespace std;
#if 0
//�ڱ����ڼ�,��û����Ӧ�Ĵ����Ӧ����ģ����ô�Ͳ��������Ӧ�ĺ���ģ��
//����в���,�д���������,��ô��Ҫ���в�������,�ڱ����ڽ��к�������
//���õ�ʱ���ǵ��õ����ɵĺ���,
//����ģ��ֻ�Ǳ��������ɴ����ģ��,���������ĺ���,
//���ò�ͬ�Ĳ���ʹ�ú���ģ���ʱ��,��Ϊ����ģ���ʵ����,����ʽʵ����,��ʽʵ����


//����ģ��Ĵ���
//1.����ģ��,class h ,typename ������������ģ������Ĺؼ���
template <class T> 
//template <typename T>
T Add(T left, T right){
	return left + right;
}

int  main(){

	cout << Add(1, 2) <<  endl;
	Add<double>(1.0, 2);

	return 0;
}

#endif



#if 0
#include "Test.h"

int main(){


	//��ģ���ʵ�����ͺ���ģ���ʵ�����ǲ�ͬ��,��Ҫ����ģ�����ֺ������<>,Ȼ��ʵ�������ͷ���<>��
	//��ģ������ֲ�����������,ʵ�����Ľ��������������

	SeqList <int>s1;
	s1.Pushback(1);
	s1.Pushback(2);
	s1.Pushback(3);
	s1.Pushback(4);
	s1[1];
	//������ռ��ʼ��Ϊ10
	//int *ptr = new int(10);
	//��̬����ʮ�������Ŀռ�
	//int *ptr = new int[10];
	return 0;
}

#endif 

#if 0
/*
	this ָ������ecx�Ĵ�������,���������������ʱ��,�����ǵ��ö���ĺ�����ʱ��,����ô���ֲ�ͬ�Ķ����
	�����thisָ����Ҫ���������
	��������ÿһ����Ա�������������ص�ָ�����,�����ָ����Ϊ�β�,���ָ��ָ���˵�ǰ�Ķ���,�ں���������Ա����Ĳ�������
	ͨ�����ָ��ȥ���ʵ�,�����û���˵���������͸����,�ɱ��������Զ����

	thisָ�������:

	1.thisָ������� : ������ *const
	2.ֻ���ڳ�Ա�������ڲ�ʹ��
	3.this������ʵ��һ����Ա�������β�,������ó�Ա������ʱ��,�����ַ��Ϊʵ�δ��ݸ���this�β�,���Զ��󲻴洢ָ��
	4.this�ǳ�Ա�����ĵ�һ���β�,һ���ɱ�һ��ȥͨ��ecx�Ĵ����Զ�����,����Ҫ�û�������,

	thisָ�����Ϊ����?
	thisָ�����Ϊ��,�����ǲ���Ҫthisָ������������ʱ��,Ҳ�������ǶԳ�Ա���������κβ�����ʱ��,����Ϊ��,����Ҫ�Ա������в�����ʱ��
	��ô����ͻᱼ��
	thisָ����������? 
	��������Ķ���Ϳ�ʼ���ù��캯��,���֮��,��������������׵�ַ������ecx�Ĵ���,���������Ա���������ջ��
	this ָ����������ecx�Ĵ�������,��ľ�̬��Ա������Ϊû��thisָ�����������������ľ�̬��Ա����Ҳ���޷�������ķǾ�̬��Ա������
*/
class Date {
public:
	Date(int _year = 1990, int _month = 1, int _day = 1)
		:year(_year)
		, month(_month)
		, day(_day)
	{}
	void printDate(){
		cout << year << " " << month << " "
			<< day << endl;
	}
	void Show(){
		cout << "123" << endl;
	}
private:
	int year;
	int month;
	int day;
};

int main(){

	Date d1;
	d1.printDate();
	d1.Show();

	Date* d2 = nullptr;
	d2->Show();
	d2->printDate();
	return 0;
}

#endif

class Date {
public:
	Date(int _year = 1990, int _month = 1, int _day = 1)
		:year(_year)
		, month(_month)
		, day(_day)
		{}
	/*�������캯��,�����ɵ���ϵͳĬ�ϵĿ������캯��,��ô����ǳ����(ֵ����)
	//��Ե��ǹ�����һ�οռ�Ķ���,����˵string��
	//���ڿռ������,�����������˵�����
	//�������캯��
	1.�ǹ��캯����һ��������ʽ
	2.�������캯������ֻ��һ��,�ұ���ʹ�����ô�����,ʹ�ô�ֵ�ķ�ʽ����������ݹ����	
	*/
	Date(const Date& d)
		:year(d.year)
		, month(d.month)
		, day(d.day)
	{}
	void Display() const{
		cout << year << "-" << month;
		cout << "-" << day << endl;
	}
	/*void Display(const Date *this){
	}*/
	/*const ��ǰ�����޸�this��ָ��
	  const �ں��治���޸� thisָ������� 
	 const ������thisָ��,const����ֻ�ܽ��ж� 
	  */
	bool operator==(const Date &d2){
		//Data temp(d2);
		return this->day == d2.day
		&& this->month == d2.month
		&& this->year == d2.year;
	}
	//������
	bool  operator!=(const Date &d){
		return !(*this == d);
	}
	//��ֵ�����,����������ֵ˳��, a1 = a2 = a3;
	//�Զ������Ͷ���ʽ����,�������÷�ʽ����,Ч�ʸ�,���õ����Ǹ�ָ��
	//�������õķ�ʽ����
	Date& operator=(const Date &d2){
		if (this != &d2){
			this->day = d2.day;
			this->year = d2.year;
			this->month = d2.month;
		}
		return *this;
	}
	//ǰ�üӼ�
	Date& operator++(){

		
		if (this->day == 30 && (this->month == 4 || this->month == 6 ||
			this->month == 9 || this->month == 11)){
			this->month++;
			this->day = 1;
		}
		else if (this->day == 31){
			this->month++;
			this->day = 1;
		}
		else {
			this->day++;
		}
		return *this;
	}

	//���üӼ�
	Date& operator++(int){
		Date temp(*this);
		if (this->day == 30 && (this->month == 4 || this->month == 6 ||
			this->month == 9 || this->month == 11)){
			this->month++;
			this->day = 1;
		}
		else if (this->day == 31){
			this->month++;
			this->day = 1;
		}
		else {
			this->day++;
		}
		return temp;
	}	
	//+ �Ų����޸�,��ô�Ͳ��ܸı�+�ŵ�����
	Date operator+(int days){
		Date temp(*this);
		temp.day += days;
		return temp;
	}
	Date& operator+=(int day){
		this->day += day;
		return *this;
	}
private:
	//���Ҫ�����жϵĻ���ô��Ҫ�ſ�Ȩ����
	int year;
	int month;
	int day;
};
//���������
//����������Ǿ������⺯�����ĺ���
//���������������֧�ֵ������,��������һ�������  .*     ::   sizeof   ?:  .(���Ƴ�Ա���������)
//���������������һ�������ͻ���ö�ٲ�����!
//���ܸı��������ԭ����˼
/*bool operator==(const Data& d1, const Data &d2){
	return d1.day == d2.day
		&& d1.month == d2.month
		&& d1.year == d2.year;
				
}*/
void TestDate(){
	Date d1(2019, 6, 28);
	Date d2(d1);
	//���ַ�ʽ�ǵȼ۵�,�������ͺ�����
	d1 = d2;
	d1.operator=(d2);   // Date::operator = (&d1,d2);
	system("pause");
}

int  main(){

	TestDate();

	return 0;

}