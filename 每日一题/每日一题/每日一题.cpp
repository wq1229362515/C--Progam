#include<string>
#include<iostream>
using namespace std;
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
#if 0
//水平值求和,贪心算法,每次取第二大的数字
//3*n-2 3*n-4 ....一直到n
#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

int main() {

	int n;
	while (cin >> n) {
		long long sum = 0;
		vector<int> arr;
		arr.resize(3 * n);
		for (int i = 0; i < (3 * n); ++i) {
			cin >> arr[i];
		}
		//排序算法,排出来之后,才可以进行操作,
		sort(arr.begin(), arr.end());
		for (int i = n; i <= 3 * n - 2; i += 2){
			sum += arr[i];
		}
		cout << sum << endl;
	}
	return 0;
}


#include<string>
#include<iostream>
using namespace std;
//建立一个映射表这样可以方便的对照,相比较暴力的循环搜索O(N^2)这个算法为O(1)
int main(){

	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	int hastable[256] = { 0 };
	//先要统计str2 中的字符
	for (int i = 0; i < str2.size(); ++i){
		hastable[str2[i]]++;
	}
	string ret;
	for (int i = 0; i < str1.size(); ++i){
		if (hastable[str1[i]] == 0) {
			//如果等于0了说明了str1中没有这个字符
			ret += str1[i];
		}
	}
	cout << ret << endl;


	return 0;
}


////先进行整个句子翻转
//整个句子翻转之后, 对单个单词进行翻转
//i like beijing.
//gnijieb ekil i.
//beijing like i.
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


int main(){

	string str1;
	getline(cin, str1);
	auto begin = str1.begin();
	//fan zhuan juzi 
	reverse(str1.begin(), str1.end());
	while (begin != str1.end()){
		//fanzhuan danci 
		auto end = begin;
		while (end != str1.end() && *end != ' ')
			end++;
		reverse(begin, end);
		if (end != str1.end())
			begin = end + 1;
		else
			begin = end;
	}
	cout << str1 << endl;


	return 0;
}


#endif
#if 0
#include <iostream>       
#include <vector> 
using namespace std;
int main(void) {
	vector<int>array;
	array.push_back(100);
	//array.push_back(300);
	array.push_back(300);
	//array.push_back(300);
	array.push_back(300);
	array.push_back(500);
	vector<int>::iterator itor;
	for (itor = array.begin(); itor != array.end(); itor++)
	{
		if (*itor == 300)
		{
			itor = array.erase(itor);
			//erase 会返回下一个元素的指针,再加上itor++
		}
	}
	for (itor = array.begin(); itor != array.end(); itor++)
	{
		cout << *itor << "";
	}
	return 0;
}




#include<string>
#include<iostream>
using namespace std;
int main(){

	
	string str1, num1, ret;
	cin >> str1;
	
	for (int i = 0; i < str1.length(); ++i){
		if (str1[i] >= '0' && str1[i] <= '9'){
			num1 += str1[i];
		}
		if (num1.size() > ret.size())
			ret = num1;
		else
			num1.clear();
	}


	return 0;
}


/*

需要找出出现次数超过一半的那个数字

1.快速排序 那个中间的数必定是那个要找的数字
2.如果有符合条件的数字，则它出现的次数比其他所有数字出现的次数和还要多。
在遍历数组时保存两个值： 一是数组中一个数字，一是次数。
遍历下一个数字时，若它与之前保存的数字相同，则次数加1，否则次数减 1；
若次数为0，则保存下一个数字，并将次数置为1。遍历结束后，所保存的数字即为所求。
然后再判断它 是否符合条件即可
*/
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int count = 1;
		int num = numbers[0];

		for (int i = 0; i <= numbers.size(); ++i){
			if (count == 0){
				num = numbers[i];
				count = 1;
			}
			else {
				if (numbers[i] == num)
					count += 1;
				else
					count -= 1;
			}
		}

		count = 0;
		for (int i = 0; i <= numbers.size(); ++i){
			if (numbers[i] == num) count++;
		}
		return (count > numbers.size() / 2) ? num : 0;
	}
};

#endif

#if 0
int main(){
	int a[5] = { 1, 3, 5, 7, 9 };
	//&a+1 也就是取到了指向a的下一个地址p-1就是上一个元素
	int *p = (int *)(&a + 1);
	printf("%d, %d", *(a + 1),*(p - 1));
}


//对于进制转换来说需要一个符号表,转换下来的进制需要倒叙输出,那么reverse即可
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

int main(){


	string ret, table = "0123456789ABCDEF";
	int m, n;
	int flag = 0;
	cin >> m >> n;
	if (m < 0){
		flag = -1;
		m = 0 - m;
	}
	while (m){
		ret += table[m%n];
		m /= n;
	}

	if (flag == -1)
		ret += '-';
	reverse(ret.begin(), ret.end());
	cout << ret << endl;

	return 0;
}
#endif

//死循环
//int main(){
//	int x = 1; do{ printf("%2d\n", x++); } while (x--);
//}
#if 0

#include<iostream>
using namespace std; 
class B0 {
public:
	virtual void display() {
		cout << "B0::display0" << endl;
	}
};
class D1:public B0  {
public:
	void display() {
		cout << "D1::display0" << endl;
	}
};
class B1:public D1  {
public:
	void display() {
		cout << "B1::display0" << endl;
	}
};

/*

	必须通过基类的对象或者引用来调用这个虚函数

*/
void  Func(B0& ptr) {
	ptr.display();
}

int main(){



	return 0;
}


/*插入回文的问题,使用暴力求解法就可以解决*/
#include<iostream>
#include<string>
using namespace std;

bool IFText(const  string & str) {
	if (str.empty() == 1)
		return false;

	size_t begin = 0;
	size_t end = str.size() - 1;
	while (begin < end){

		if (str[begin] != str[end])
			return false;

		begin++;
		end--;
	}
	return true;
}
int main(){

	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	int count = 0;
	//cha ru 
	for (int i = 0; i <= str1.size(); ++i){

		string str = str1;
		str.insert(i, str2);
		if (IFText(str) == true)
			count++;

	}
	cout << count << endl;


	return 0;
}
#endif

/*
	对于转换字符串为整数,需要将正负号给摘出来,利用string就可以摘出来
	然后每次过来加法的是
	123

	1
	1 * 10 +2;
	12* 10 +3
	sum = sum*10 +str[i] - '0';

*/

#if 0
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
	int StrToInt(string str) {
		if (str.empty() == 1)
			return 0;
		int symbal = 1;
		if (str[0] == '+'){
			str[0] = '0';
			symbal = 1;
		}
		if (str[0] == '-'){
			str[0] = '0';
			symbal = -1;
		}

		int  sum = 0;
		for (int i = 0; i < str.size(); ++i) {
			if (str[i] < '0' || str[i] > '9'){
				sum = 0;
				break;
			}
			sum = sum * 10 + str[i] - '0';
		}
		return symbal*sum;
	}
};
#endif



/*

不断的去逼近这个数字

*/
#if 0
#include<iostream>
#include<algorithm>
using namespace std;

int main() {

	int ret, f0 = 0, f1 = 1, left = 0, right = 0;
	int  N;
	cin >> N;

	while (1) {

		//找出那个离他们最近的那个fac数
		ret = f0 + f1;
		f0 = f1;
		f1 = ret;
		

		//每次循环进来都会来判断是否逼近了这个数

		if (ret < N)
			right = N - ret;
		else{
			left = ret - N;
			break;
		}

	}
	cout << min(right, left) << endl;

	return 0;
}
#endif


#if  0
#include<stack>
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		if (A.empty())
			return false;

		stack <char> _stack;
		for (auto chr : A)
			switch (chr) {
			case '(':
				_stack.push(chr);
				break;

			case ')':
			{
						if (_stack.empty() == 1 || _stack.top() != '(')
							return false;
						else
							_stack.pop();
			}
				break;
			default: return false;
		}
		return true;
	}


	bool chkParenthesis2(string A, int n){
		if (n == 0)
			return false;
		stack <char> _stack;
		int i = 0;
		while (i < A.size()){
			if (A[i] == ')'){
				if (_stack.empty() == 1 || _stack.top() != '(')
					return false;
				else
					_stack.pop();
				i++;
				continue;
			}
			if (A[i] == '('){
				_stack.push(A[i]);
				i++;
				continue;
			}
			if (A[i] != '(' || A[i] != ')')
				return false;
		}
		if (_stack.empty())
			return true;
		return false;
	}
};

int main(){



	Parenthesis test;
	cout << test.chkParenthesis2("()d()(((())))", 12) << endl;

}


/*
	分开判断
	巧妙之处在于将vector 里面是string合为了
	构成了一个字符串数组
	直接比较就可以,不用用strcmp来比较

*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {


	int n;
	cin >> n;
	vector<string> str;
	str.resize(n);
	for (auto& _str : str)
		cin >> _str;

	//size panduan
	bool size = true;  bool directory = true;
	for (int i = 1; i< str.size(); ++i){
		if (str[i - 1].size() > str[i].size()){
			size = false;
			break;
		}
	}
	for (int i = 1; i< str.size(); ++i) {
		if (str[i - 1] > str[i]){
			directory = false;
			break;
		}
	}
	if (size && directory)
		cout << "both" << endl;
	if (!size && directory)
		cout << "lexicographically" << endl;
	if (size && !directory)
		cout << "lengths" << endl;
	if (!size && !directory)
		cout << "none" << endl;
	return 0;
}
#endif


#if 0
int main(){

	const string table = "0123456789ABCDEF";
	string ret;
	size_t  n;
	while (cin >> n)
		if (n < table.size())
			ret += table[n];
	cout <<"Your hex number is :"<< ret << endl;
	return 0;
	
}
#endif

#if 0 
class Test{ public:    int a;    int b;    virtual void fun() {}    Test(int temp1 = 0, int temp2 = 0)    { a = temp1;        b = temp2; }    int getA()     { return a; }    int getB()     { return b; } };

int main(){

	Test a;

	//a 的首地址里面并不是a里面的变量成员.
}

#endif


#if 0
/*
	密码安全强度问题


*/
#include<string>
#include<iostream>
#include<assert.h>
using namespace std;



class Solutions {

public:

	int legngths(const string str){
		if (str.empty())
			assert(1);

		if (str.size() <= 4)
			return 5;
		if (str.size() >= 8)
			return 25;
		if (5 <= str.size() && str.size() >= 7)
			return 10;
	}

	int word(const string str) {
		if (str.empty())
			assert(1);

		int big = 0, small = 0;
		for (int i = 0; i < str.size(); ++i){
			if (isupper(str[i]))
				++big;
			if (islower(str[i]))
				++small;
		}
		if ((big + small) == 0)
			return 0;
		else if (big + small == str.size())
			return 10;
		else return 20;
	}

	int num(const string str) {
		if (str.empty())
			assert(1);
		int num = 0;
		for (int i = 0; i < str.size(); ++i){
			if (isdigit(str[i]))
				++num;
		}
		if (num == 0)
			return 0;
		else if (num == 1)
			return 10;
		else return 20;
	}
	int symbal(const string str){
		int num = 0;
		for (int i = 0; i < str.size(); i++){
			if (!(str[i] >= 65 && str[i] <= 90)
				&& !(str[i] >= 97 && str[i] <= 122)
				&& !(str[i] - '0' >= 0 && str[i] - '0' <= 9))
				num++;
		}
		if (num == 0)
			return 0;
		else if (num == 1)
			return 10;
		else
			return 25;
	}

	int other(int word, int num, int symbal){
		if (word == 25 && num && symbal)
			return 5;
		else if (word == 10 && num && symbal)
			return 3;
		else if (word == 10 && num)
			return 2;

		else return 0;
	}
	int Sum(int word, int length, int other, int symbal, int num){
		return symbal + word + length + other + num;
	}

};


int main() {

	Solutions test;
	string str;
	getline(cin, str);
	int word = 0, length = 0, others = 0, symbal = 0, num = 0;
	length = test.legngths(str);
	word = test.word(str);
	symbal = test.symbal(str);
	num = test.num(str);
	others = test.other(word, num, symbal);

	int ret = test.Sum(word, length, others, symbal, num);

	if (ret >= 90)
		cout << "VERY_SECURE" << endl;
	else if (ret >= 80 && ret < 90)
		cout << "SECURE" << endl;
	else if (ret >= 70 && ret < 80)
		cout << "VERY_STRONG" << endl;
	else if (ret >= 60 && ret < 70)
		cout << "STRONG" << endl;
	else if (ret >= 50 && ret < 60)
		cout << "AVERAGE" << endl;
	else if (ret >= 25 && ret < 50)
		cout << "WEAK" << endl;
	else
		cout << "VERY_WEAK" << endl;


	return 0;
}
#endif


#if 0

/*/
virtual 函数是动态绑定，而缺省参数值却是静态绑定。 意思是你可能会 在“调用一个定义于派生类内的virtual函数”的同时，
却使用基类为它所指定的缺省参数值。
结论：绝不重新定义继承而来的缺省参数值！（可参考《Effective C++》条款37）
对于本例：
B*p = newB;

p->test();
p->test()执行过程理解：
(1) 由于B类中没有覆盖（重写）基类中的虚函数test()，因此会调用基类A中的test()；
(2) A中test()函数中继续调用虚函数 fun()，因为虚函数执行动态绑定，
p此时的动态类型（即目前所指对象的类型）为B*，因此此时调用虚函数fun()时，执行的是B类中的fun()；所以先输出“B->”；
(3) 缺省参数值是静态绑定，即此时val的值使用的是基类A中的缺省参数值，其值在编译阶段已经绑定，值为1，所以输出“1”；
最终输出“B->1”。所以大家还是记住上述结论：绝不重新定义继承而来的缺省参数值！
*/
class A {
public:
	virtual void func(int val = 1)    {
		std::cout << "A->" << val << std::endl;
	}
	virtual void test(){
		func();
	}
};
class B : public A {
public:
	void func(int val = 0)
	{
		std::cout << "B->" << val << std::endl;
	}
};
int main(int argc, char* argv[]) {
	B*p = new B;
	p->test();
	return 0;
}


/*
	求两个节点共同最近的父节点
	特性 :root = child / 2;

	两个不断相除,相等了那么就是最后的结果,如果一个比另外一个大就先进行除法运算,
	再两数字进行比较

*/
class LCA {
public:
	int getLCA(int a, int b) {
		// write code here

		while (a != b){
			if (a > b)
				a /= 2;
			if (a < b)
				b /= 2;
		}
		return a;

	}
};

#endif


#if 0
void func(const int& v1, const int& v2) { std::cout << v1 << ' ';    std::cout << v2 << ' '; }

#include<algorithm>
int main() {
	/*
	int n;
	cin >> n;
	int count = 0, tempcount = 0;

		while (n){
			if (n & 1){
				++tempcount;
				count = max(count, tempcount);
			}
			else
				tempcount = 0;
			n = n >> 1;
		
	}
	cout << count << endl;
	*/

	int i = 0;
	func(++i, i++);


	return 0;
}

#endif


#if 0
#include<iostream>
using namespace std;


int  main() {

	/*
	int array[12] = { 0,31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

	int year = 0, month = 0, day = 0;
	int sum = 0;
	cin >> year;
	cin >> month;
	cin >> day;

		sum += array[month - 1];
		sum += day;

		if ((year % 4 == 0 && year % 100 != 0)
			|| year % 400 == 0)
			sum += 1;
		cout << sum << endl;
		*/


	char str1[] = "ABCD";
	char str2[] = {' A',' B',' C', 'D' };


	return 0;
}


#endif


#if 0
void print(char *s)
{
	static int i = 0;
	if (*s)
	{
		print(++s);
		//++s 已经改变了s的值所以s的值已经是指向下一个元素了

		printf("%c %d ", *s);
	}
}

int Func(char x[14]){

	return 0;
}
int main(){ 
	//char str[] = "Geneius";  


	const int a = 10;
	int *ptr = (int *)&a;
	*ptr = 20;
	cout << a << *ptr << endl;

	char str[10];
	Func(str);


	char *p = "abc"; 
	char *q = "abc123"; 
	//字符串的常量没办法赋值的
	while (*p = *q) 
		printf("%c %c",*p, *q);

	//print(str); 
}  

#endif


#if 0
int f(int n)
{
	static int i = 1;
	if (n >= 5)
		return n;
	n = n + i;
	i++;
	return f(n);
}

int main(){

	cout<<f(1);
}
#endif
#if 0
int main() {
	char a[] = "programming", b[] = "language";
	char *p1, *p2;
	int i;
	p1 = a, p2 = b;
	for (i = 0; i < 7; i++)
	if (*(p1 + i) == *(p2 + i))
		printf("%c", *(p1 + i));
}

#endif

#if 0
#include<iostream>
using namespace std;


int main(){

	int mouth;
	int first = 1, second = 1, sum = 0;
	cin >> mouth;

		for (int i = 3; i <= mouth; ++i)
		{
			sum = first + second;
			first = second;
			second = sum;
			
		}
		cout << sum << endl;

	



	return 0;
}
#endif

#include<assert.h>
void Swap(int* right,int* left){

	int temp = *left;
	*left = *right;
	*right = temp;

}
void Func(int** temp){

	*temp = (int *)malloc(sizeof(int));
	if (*temp == NULL){
		assert(1);
		return;
	}
	**temp = 20;
	return;


}

int main(){

	int *ptr = NULL;
	//int *ptr1 = 1;

	/*Func(&ptr);
	printf("%d\n", *ptr);*/

	int left = 10, right = 20;
	//交换函数
	Swap(&left, &right);


	//char *str[4] = { "hello", "world", "ni", "hao" };

	//*str[1] = "nihao";
	return 0;
}
