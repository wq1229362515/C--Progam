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

class Date {
public:
	Date(int _year = 1990, int _month = 1, int _day = 1)
		:year(_year)
		, month(_month)
		, day(_day)
		{}
	bool operator==(const Date &d2){
		//Data temp(d2);
		return this->day == d2.day
		&& this->month == d2.month
		&& this->year == d2.year;
	
	}
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
	Date& operator<<(const Date& d3){
		cout << this->year << "," << this->month << ","
			<< this->day;
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
/*bool operator==(const Data& d1, const Data &d2){
	return d1.day == d2.day
		&& d1.month == d2.month
		&& d1.year == d2.year;
				
}*/

int  main(){

	int  a = 10;
	int  b = 10;
	bool ret = (a == b);
	//����ͨ�ı����ж����Խ��������ĸ�ֵ,���������о��ǲ����Ե�
	Date d1(2002,2,2);
	Date d2(d1);	// ��ɵ���һ����������
	//d1 == d2;   �����н��������Ĳ�����ô���ǲ��е�,�������������������
	//�ڱ�������Ҳ��һ������ĺ���,��Ϊִ����һ�δ���,�����ж��������Ƿ�����ȵ�
	//��Ȼ����Ҳ�����ڿ���ֱ�Ӷ���һ������,�����������������ж�
	cout << (d1 == d2) << endl;
	Date d3(2019, 6, 30);
	d1 = d3;
	d3++;
	++d1;
	d3 += 30;

	return 0;

}