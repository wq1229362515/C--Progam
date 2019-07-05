#if 0
/*倒叙字符串*/
#include<string>
#include<iostream>
using namespace std;
int main() {


	string s1;
	size_t pos = 0;
	size_t pos2;
	getline(cin, s1);
	pos2 = s1.size();
	//范围一律是左闭 右开的 [   )  !!

	string s2; //用来存放倒叙找到的字符
	while (1) {
		
		pos = s1.find_last_of(' ',pos2 - 1);
		if (pos > 100 ){
			s2 += " ";
			s2 += s1.substr(0, pos2);
			break;
		}
		//如果是第一次遇见空格的话,
		if (pos2 == s1.size()){
			s2 += s1.substr(pos+1, s1.size() - pos);
			pos2 = pos;
			continue;
		}
			
		//substr 的意思是在pos位置之后,截取n个字符
		s2 += s1.substr(pos, pos2-pos);
		pos2 = pos;
	}

	cout << s2 << endl;


	return 0;
}


#endif
/*划分子序列问题*/
#if 0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	int ret = 0;
	cin >> n;

	vector<int>arr(n);
	for (auto e: arr){
		cout << e;
	}
	sort(arr.begin(), arr.end());
	if (arr.size() % 2 == 0 ){
		cout << ret << endl;
	}
}
#endif 

#include <stdio.h>
#if 0
int main(int argc, const char *argv[])
{


	for (int i = 1; i < 6; i++){
		switch (i){
		case 1:
			printf("i == 1\n");
			break;
		case 2:
			printf("i == 2\n");
			break;
		case 3:
			printf("i == 3\n");
			break;
		default:
			printf(" not 1 2 3\n");
			break;
		}
	}
	return 0;
}
#endif

/*7.3截取最长数字*/
#if 0
#include<iostream>
#include<string>
using namespace std;
int main() {

	string s1, s2;
	getline(cin, s1);
	auto ptr = s1.begin();
	auto s2begin = s2.begin();
	int count1 = 0;
	int count2 = 0;
	int len= s1.size();
	while (len != 0) {
		s2begin = ptr;
		while(len > 0 && (*ptr >= '0' && *ptr <= '9')) {	
			ptr++;
			len--;
			count1++;
		}
		if (count1 != 0 &&count1 > count2){
			s2.clear();
			//截取字符串
			count2 = count1;
			while (count1--){
				s2.push_back(*s2begin);
				s2begin++;
			}	
		}
		count1 = 0;
		len--;
		if (len < 0){
			break;
		}
		ptr++; 
		
	}
	cout << s2;
	return 0;
}
#endif

/*一组数据中最多次出现次数的数
运用排序算法,排出来肯定会在中间出现.利用这个性质去做
也可以利用派兵打仗的思想去做


*/
/*
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int len = numbers.size();
		if (numbers.empty()){
			return 0;
		}

		int num = numbers[0], count = 1;
		for (int i = 0; i < len; i++){
			if (numbers[i] == num){
				count++;
			}
			else {
				count--;
			}
			if (count == 0){
				num = numbers[i];
				count = 1;
			}
		}
		count = 0;
		for (int i = 0; i < len; i++) {
			if (numbers[i] == num) count++;
		}
		return (count * 2> len) ? num : 0;
};


int main(){


	Solution s1;
	vector<int> array;
	array.push_back(1);
	array.push_back(5);
	array.push_back(5);
	array.push_back(5);
	array.push_back(5);
	array.push_back(5);
	array.push_back(5);
	array.push_back(4);
	array.push_back(2);
	array.push_back(2);
	int ret = s1.MoreThanHalfNum_Solution(array);
	cout << ret << endl;

	return 0;
}

*/

//4号分糖果问题
/*
#include<iostream>
using namespace std;
void Ifsugar(int* array){
	int  A, B, C;
	A = (array[0] + array[2]) / 2;
	B = (array[1] + array[3]) / 2;
	C = array[3] - B;
	if ((A - B == array[0]) && (B - C == array[1]) && (A + B == array[2]) && (B + C == array[3])) {
		cout << A << " " << B << " " << C << endl;
	}
	else {
		cout << "No" << endl;
	}
	return;
}
int main() {
	int array[4];
	for (int i = 0; i < 4; i++){
		cin >> array[i];
		if ((array[i] < -30) && (array[i] > 30)){
			cout << "NO" << endl;
			return 0;
		}
	}
	Ifsugar(array);
	return 0;
}

*/


#include<iostream>
#include<string>
using namespace std;

bool ReverseString(string C, int len) {
	for (int i = 0; i<=(len/2); i++) {
		if (C[i] == C[len - i]){
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

int  main() {
	string A, B, C;
	getline(cin, A);
	getline(cin, B);
	int ret = 0;                //回文串的个数
	int count = 0;        //循环的次数
	while (count != A.size() + 1) {
		C.clear();
		auto ptr = A.begin();
		//生成新的C串,用C串来判断这个整合的字符串是否是回文
		//处理特殊情况
		if (count == 0) {
			C = B + A;
		}
		else if (count == A.size() + 1) {
			C = A + B;
		}
		//非特殊情况
		else {
			C = (A.begin(), A[count]);
			auto ptr = A[count];
			C += B;
			C += ptr;
		}
		if (ReverseString(C,C.size())){
			ret++;
		}
		count++;
	}
	cout << ret << endl;
	return 0;
}