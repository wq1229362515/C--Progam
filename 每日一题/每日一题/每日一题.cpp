#include<string>
#include<iostream>
using namespace std;
#if 0
/*�����ַ���*/
#include<string>
#include<iostream>
using namespace std;
int main() {


	string s1;
	size_t pos = 0;
	size_t pos2;
	getline(cin, s1);
	pos2 = s1.size();
	//��Χһ������� �ҿ��� [   )  !!

	string s2; //������ŵ����ҵ����ַ�
	while (1) {
		
		pos = s1.find_last_of(' ',pos2 - 1);
		if (pos > 100 ){
			s2 += " ";
			s2 += s1.substr(0, pos2);
			break;
		}
		//����ǵ�һ�������ո�Ļ�,
		if (pos2 == s1.size()){
			s2 += s1.substr(pos+1, s1.size() - pos);
			pos2 = pos;
			continue;
		}
			
		//substr ����˼����posλ��֮��,��ȡn���ַ�
		s2 += s1.substr(pos, pos2-pos);
		pos2 = pos;
	}

	cout << s2 << endl;


	return 0;
}


#endif
/*��������������*/
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

/*7.3��ȡ�����*/
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
			//��ȡ�ַ���
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

/*һ�����������γ��ִ�������
���������㷨,�ų����϶������м����.�����������ȥ��
Ҳ���������ɱ����̵�˼��ȥ��


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

//4�ŷ��ǹ�����
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
//�����ַ��������ж�
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
	int ret = 0;                //���Ĵ��ĸ���
	int count = 0;        //ѭ���Ĵ���
	while (count != A.size() + 1) {
		C.clear();
		auto ptr = A.begin();
		//�����µ�C��,��C�����ж�������ϵ��ַ����Ƿ��ǻ���
		//�����������
		if (count == 0) {
			C = B + A;
		}
		else if (count == A.size()) {
			C = A + B;
		}
		//���������
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
	long int ret = 0;        //���
	cin >> n;
	vector<int> arr(n);//��������
	for (long int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (long int i = 0; i < n; i++) {
		long int temp = 0;                       //�洢�����ݴ���������
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

//����ƥ��
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
			//���ж��߽������ǲ��������ţ����ǲ��ǿ�
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

//쳲�������̾���
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
	//���ȱƽ��Ǹ���ӽ�������,����������
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
/*������*/
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
			//���ڵĻ����ص�������
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
		//����һ��ʱ��˵������
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
//ˮƽֵ���,̰���㷨,ÿ��ȡ�ڶ��������
//3*n-2 3*n-4 ....һֱ��n
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
		//�����㷨,�ų���֮��,�ſ��Խ��в���,
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
//����һ��ӳ����������Է���Ķ���,��Ƚϱ�����ѭ������O(N^2)����㷨ΪO(1)
int main(){

	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	int hastable[256] = { 0 };
	//��Ҫͳ��str2 �е��ַ�
	for (int i = 0; i < str2.size(); ++i){
		hastable[str2[i]]++;
	}
	string ret;
	for (int i = 0; i < str1.size(); ++i){
		if (hastable[str1[i]] == 0) {
			//�������0��˵����str1��û������ַ�
			ret += str1[i];
		}
	}
	cout << ret << endl;


	return 0;
}


////�Ƚ����������ӷ�ת
//�������ӷ�ת֮��, �Ե������ʽ��з�ת
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
			//erase �᷵����һ��Ԫ�ص�ָ��,�ټ���itor++
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

��Ҫ�ҳ����ִ�������һ����Ǹ�����

1.�������� �Ǹ��м�����ض����Ǹ�Ҫ�ҵ�����
2.����з������������֣��������ֵĴ����������������ֳ��ֵĴ����ͻ�Ҫ�ࡣ
�ڱ�������ʱ��������ֵ�� һ��������һ�����֣�һ�Ǵ�����
������һ������ʱ��������֮ǰ�����������ͬ���������1����������� 1��
������Ϊ0���򱣴���һ�����֣�����������Ϊ1����������������������ּ�Ϊ����
Ȼ�����ж��� �Ƿ������������
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
	//&a+1 Ҳ����ȡ����ָ��a����һ����ַp-1������һ��Ԫ��
	int *p = (int *)(&a + 1);
	printf("%d, %d", *(a + 1),*(p - 1));
}


//���ڽ���ת����˵��Ҫһ�����ű�,ת�������Ľ�����Ҫ�������,��ôreverse����
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

//��ѭ��
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

	����ͨ������Ķ��������������������麯��

*/
void  Func(B0& ptr) {
	ptr.display();
}

int main(){



	return 0;
}


/*������ĵ�����,ʹ�ñ�����ⷨ�Ϳ��Խ��*/
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
	����ת���ַ���Ϊ����,��Ҫ�������Ÿ�ժ����,����string�Ϳ���ժ����
	Ȼ��ÿ�ι����ӷ�����
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

���ϵ�ȥ�ƽ��������

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

		//�ҳ��Ǹ�������������Ǹ�fac��
		ret = f0 + f1;
		f0 = f1;
		f1 = ret;
		

		//ÿ��ѭ�������������ж��Ƿ�ƽ��������

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
	�ֿ��ж�
	����֮�����ڽ�vector ������string��Ϊ��
	������һ���ַ�������
	ֱ�ӱȽϾͿ���,������strcmp���Ƚ�

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

	//a ���׵�ַ���沢����a����ı�����Ա.
}

#endif


#if 0
/*
	���밲ȫǿ������


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
virtual �����Ƕ�̬�󶨣���ȱʡ����ֵȴ�Ǿ�̬�󶨡� ��˼������ܻ� �ڡ�����һ���������������ڵ�virtual��������ͬʱ��
ȴʹ�û���Ϊ����ָ����ȱʡ����ֵ��
���ۣ��������¶���̳ж�����ȱʡ����ֵ�����ɲο���Effective C++������37��
���ڱ�����
B*p = newB;

p->test();
p->test()ִ�й�����⣺
(1) ����B����û�и��ǣ���д�������е��麯��test()����˻���û���A�е�test()��
(2) A��test()�����м��������麯�� fun()����Ϊ�麯��ִ�ж�̬�󶨣�
p��ʱ�Ķ�̬���ͣ���Ŀǰ��ָ��������ͣ�ΪB*����˴�ʱ�����麯��fun()ʱ��ִ�е���B���е�fun()�������������B->����
(3) ȱʡ����ֵ�Ǿ�̬�󶨣�����ʱval��ֵʹ�õ��ǻ���A�е�ȱʡ����ֵ����ֵ�ڱ���׶��Ѿ��󶨣�ֵΪ1�����������1����
���������B->1�������Դ�һ��Ǽ�ס�������ۣ��������¶���̳ж�����ȱʡ����ֵ��
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
	�������ڵ㹲ͬ����ĸ��ڵ�
	���� :root = child / 2;

	�����������,�������ô�������Ľ��,���һ��������һ������Ƚ��г�������,
	�������ֽ��бȽ�

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
		//++s �Ѿ��ı���s��ֵ����s��ֵ�Ѿ���ָ����һ��Ԫ����

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
	//�ַ����ĳ���û�취��ֵ��
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
	//��������
	Swap(&left, &right);


	//char *str[4] = { "hello", "world", "ni", "hao" };

	//*str[1] = "nihao";
	return 0;
}
