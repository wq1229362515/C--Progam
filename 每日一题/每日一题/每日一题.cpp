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

//---------------------------------------
//插入字符串回文判断
/*
#include<iostream>
#include<string>
using namespace std;

bool ReverseString(string C, int len) {
	for (int i = 0; i<=(len/2); i++) {
		if (C[i] == C[len - i - 1]){
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
		else if (count == A.size()) {
			C = A + B;
		}
		//非特殊情况
		else {
			C = A.substr(0,count);
			auto ptr = A[count];
			C += B;
			C += A.substr(count, A.size());
			
		}
		if (ReverseString(C,C.size())){
			ret++;
		}
		count++;
	}
	cout << ret << endl;
	return 0;
}
*/

/*
#include<iostream>
#include<vector>
using namespace std;

int main() {

	long int n;
	long int ret = 0;        //结果
	cin >> n;
	vector<int> arr(n);//定义数组
	for (long int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (long int i = 0; i < n; i++) {
		long int temp = 0;                       //存储的是暂存最大的数字
		for (long int j = i; j<n; j++) {
			temp += arr[j];
			if (temp > ret){
				ret = temp;
			}
		}
	}
	cout << ret << endl;
	return 0;
}
*/
/*
#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
	int StrToInt(string str) {
		if (str.size() == 0 ){
			return 0;
		}
		int  ret = 0;
		int temp;
		int buf;
		int len = 1;
		if (str[0] == '+' || str[0] == '-'){
			while (len != str.size()){
				if (str[len] >= '0' && str[len] <= '9'){
					temp = str[len] - '0';
					buf = 1;
					for (int i = len, j = 1; i < str.size(); j *= 10, i++){
						if (i == str.size() - 1){
							buf = j;
						}
					}
					temp = temp*buf;
					ret += temp;
				}
				else {
					return 0;
				}
				len++;
			}
		}
		else{
			return 0;
		}
		if (str[0] == '+'){
			return ret;
		}
		if (str[0] == '-'){
			return -ret;
		}
		return 0;
	}
};

int main() {



	Solution A;
	cout << A.StrToInt("") << endl;;
	
	Solution B;
	cout << B.StrToInt("   -214747") << endl;

	return 0;
}

*/

//括号匹配
/*
#include<stack>
#include<iostream>
using namespace std;
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		if (n == 0){
			return false;
		}
		stack<char> str;
		int i = 0;
		while (i <= A.size()) {
			//先判断走进来的是不是右括号，并是不是空
			if (A[i] == '}' || A[i] ==  ')' || A[i] ==  ']'){
				if (str.empty()){
					return false;
				}
				if (A[i] == '}' && str.top() == '{' ||
					A[i] == ']' && str.top() == '[' ||
					A[i] == ')' && str.top() == '('){
					str.pop();
					i++;
					continue;
				}
				else return false;
			}
			if (A[i] == '{' || A[i] == '[' || A[i] == '('){
				str.push(A[i]);
			}
			i++;
		}
		if (str.empty()){
			return true;
		}
		else 
		return false;
	}
};
int main(){
	int b = 1;
	int i = (b++ == 2);
	
	string A("(())");
	Parenthesis B;
	int ret = B.chkParenthesis(A, 4);
	cout << ret << endl;
	
	return 0;
}
*/

//斐波那锲最短距离
/*
#include<iostream>
using namespace std;
int Fac(int i) {
	if (i == 0) {
		return 0;
	}
	if (i == 1) {
		return 1;
	}
	if (i >= 2) {
		return Fac(i - 1) + Fac(i - 2);
	}
}

int main() {

	int  N;
	int ret1 = 0;
	int temp = 0;
	int ret2 = 0;
	cin >> N;
	//首先逼近那个最接近的数字,就在其左右
	for (int i = 0;; i++) {
		temp = ret1;
		ret1 = Fac(i);
		if (ret1 < N){
			continue;
		}
		else {
			ret2 = ret1;
			ret1 = temp;
			break;
		}
	}
	if ((ret2 - N )> (-(ret1 - N))){
		cout << N - ret1 << endl;
	}
	else {
		cout << ret2 - N << endl;
	}
	return 0;
}
*/
/*公倍数*/
/*
#include<iostream>
using namespace std;
class Problems{
public:
	int Fuc(int A, int B) {
		for (int i = 1;; i++) {
			if ((i%A == 0) && (i%B == 0)){
				return i;
			}
		}
		return 0;
	}
};
int main(){
	int A, B;
	Problems C;
	cin >> A;
	cin >> B;
	int ret = C.Fuc(A, B);
	cout << ret << endl;
	return 0;
}
*/
/*
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
class problems {
public:
	int length(string str[], int  n){
		for (int i = 0;i<n-1; i++) {
			if (str[i].size() < str[i + 1].size()) {
				continue;
			}
			else {
				return 0;
			}
		}
		return 1;
	}
	int  dirctory(string str[], int n){
		for (int i = 0;i<n-1; i++) {
			//大于的话返回的是正数
			if (strcmp(str[i].c_str(),str[i+1].c_str()) < 0){
				continue;
			}
			else {
				return 0;
			}
		}
		return 1;
	}
};

int main() {

	int n;
	cin >> n;
	string str[100];
	int i = 0;
	while (1){
		if (i >= n){
			break;
		}
		cin>>str[i++];
	}
	problems Test;
	int ret1 = Test.length(str,n);
	int ret2 = Test.dirctory(str,n);
	if ((ret1 == 1) && (ret2 == 1)){
		cout << "both" << endl;
	}
	if ((ret1 == 1) && (ret2 == 0)){
		cout << "lengths" << endl;
	}
	if ((ret1 == 0) && (ret2 == 1)) {
		cout << "lexicographically" << endl;
	}
	if ((ret1 == 0) &&(ret2 == 0)){
		cout << "none" << endl;
	}
	return 0;
}
*/

/*
#include<iostream>
using namespace std;

class UnusualAdd {
public:
	int addAB(int A, int B) {
		return    A + B;
	}
};
int main(){
	UnusualAdd Test;
	cout << Test.addAB(2147483647, 21474836475) << endl;;
}
*/

/*
#include<iostream>
using namespace  std;


int main(){

	int count = 0;
	int num1;
	int temp = 0;
	cin >> num1;
	while (1){
		if (num1 == 0){
			break;
		}
		if ((num1 & 1) == 1){
			count++;
			if (temp < count){
				temp = count;
			}
		}
		//不是一的时候说明断了
		if ((num1 & 1) == 0){
			count = 0;
		}
		num1 = num1 >> 1;
	}
	if (temp > count){
		cout << temp << endl;
	}
	else 
	cout << count << endl;
	
	return 0;
}

/*
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> arr;
		while (n)
		{
			if (n & 1)
				arr.push_back(1);
			else
				arr.push_back(0);
			n = n >> 1;
		}
		int count = 0;
		int x = 0;
		int max = 0;
		for (int i = 0; i < arr.size(); ++i)
		{
			while (arr[i] == 1)
			{
				count++;
				i++;
				if (i == arr.size())
					break;
			}
			if (count >= max)
			{
				max = count;
				count = 0;
			}

		}
		cout << max << endl;
	}
	return 0;
}
*/

/*

#include<iostream>

using namespace std;

int main(){


	int A, B;
	int fatherA, fatherB;
	cin >> A >> B;
	if (A % 2 == 0){
		fatherA = A / 2;
	}
	else fatherA = (A - 1) / 2;
	if (B % 2 == 0){
		fatherB = B / 2;
	}
	else fatherB = (B - 1) / 2;





	return 0;
}



*/

#include<iostream>
using namespace  std;
class Soultion{
public:
	int findNumberof1(int num) {
		int count = 0;
		while (1){
			if (num == 0){
				break;
			}
			if ((num & 1) == 1) {
				count++;
			}
			num = num >> 1;
		}
		cout << count << endl;
		return 0;
	}
};


int  main(){
	Soultion Test;
	int temp;
	cin >> temp;
	Test.findNumberof1(temp);
	return 0;
}
