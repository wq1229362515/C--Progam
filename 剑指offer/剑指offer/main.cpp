

/*
	�쳣��ȫ�� : ���ƻ�����,���κ���Դй¶    --�ڴ�й¶
												��Դй¶   

	һ.��ֵ�����������Ҫע�������

		1. ����ֵ���͵�����
		2. ����Ĳ����Ƿ���const ���� ,�����һ�������������ÿ������캯��
		3. thisָ��͵�ǰ������ж�
		4. �ͷ��Լ�ԭ�е��ڴ�ռ�

*/

#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

#if 0
class Mystring{
public:
	Mystring(char *str = NULL) :my_data(str){};
	Mystring(const Mystring& str):my_data(new char[strlen(str.my_data) + 1]){
		strcpy(my_data, str.my_data);
	};
	~Mystring(void){};

	//���׵�����,��û�п���һ���µ��ڴ�ռ�,ֻ��ɾ����,������û�п��ǵ������¿ռ���쳣��

	//Mystring& operator=(const Mystring&str) {

	//	if (this == &str) {
	//		return *this;
	//	}
	//	delete[]my_data;
	//	my_data = new char[strlen(str.my_data + 1)];
	//	strcpy(my_data, str.my_data);


	//	return *this;
	//}
	//Mystring& operator=(const Mystring& str) {

	//	if (this == &str) {
	//		return *this;
	//	}
	//	/*
	//	1.�����µĿռ�(��ǳ����������)
	//	2.�ͷ�ԭ�еĿռ�
	//	3.�������ݵ��µĵ�ַ�ռ���
	//	4.���µĵ�ַ�ռ䴫���ɵĵ�ַ�ռ�
	//	*/
	//	char* newchar = new char[strlen(str.my_data) +1];
	//	strcpy(newchar, str.my_data);
	//	delete[]my_data;
	//	my_data = newchar;

	//	return *this;
	//}

	//���׵����������������ջ֡������,���е���������
	//�´�����newdata���ĵ�ַ���µĵ�ַ
	//���������ı��ַ��ָ��
	Mystring& operator=(const Mystring& str) {
		if (this != &str) {
			Mystring tempstr(str);
			
			char *newdata = tempstr.my_data;
			tempstr.my_data = my_data;
			my_data = newdata;
		}
		return *this;
	}

private:
	char* my_data;
};

#if 0

int main() {

	Mystring a("str");
	Mystring b;
	b = a;


	return 0;
}
#endif

//��ά����Ѱ��
bool Find(int target, vector<vector<int> > array) {

	int row = array.size();
	int col = array[0].size() - 1;
	int temprow = 0;
	if (row && col) {
		while (temprow < array[0].size()  && col >=0) {
			if (array[temprow][col] > target) {
				col--;
				continue;
			}
			if (array[temprow][col] < target) {
				temprow++;
				continue;
			}
			if (array[temprow][col] == target)
				return true;
		}
	}
	return false;

}


//�հ׸��滻
void replaceSpace(char *str, int length) {
	if (str == NULL && length <= 0)
		return;

	int balocksum = 0;
	int lengthl = 0;
	int newlegth = 0;
	while (str[lengthl] != '\0'){

		if (str[lengthl] == ' ')
			balocksum++;

		lengthl++;
	}
	lengthl++;
	newlegth = lengthl + balocksum * 2;
	while (lengthl && newlegth > lengthl) {
		if (str[lengthl] == ' ') {
			str[newlegth--] = '0';
			str[newlegth--] = '2';
			str[newlegth--] = '%';
		}
		else
			str[newlegth--] = str[lengthl];
		lengthl--;
	}
}


//β������

/*
	��������ȥ�����Ļ��ռ临�Ӷ���һ��o(n)
	��������������һ��o(1)

*/
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
class Solution1 {
public:
	stack<int> tack;;
	vector<int> value;
	vector<int> printListFromTailToHead(ListNode* head) {

		ListNode* pNode = head;
		while (pNode) {
			tack.push(pNode->val);
			pNode = pNode->next;
		}
		while (!tack.empty()) {
			value.push_back(tack.top());
			tack.pop();
		}

		return value;
	}
	//���ڵݹ�Ļ�,����ݹ����̫�������ջ���
	vector<int> printListFromTailToHead(ListNode* head) {
		if (head) {
			if (head->next)
				printListFromTailToHead(head->next);
			value.push_back(head->val);
		}
		return value;
	}
};


/*
	ǰ����� ��һ����Զ�Ǹ��ڵ�
	�������    ���ڵ������������ �ұ�������
	������� ���һ����Զ�Ǹ��ڵ�
	��������������в����ҵ����ڵ��ֵ

*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution2 {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		//ǰ���������    �����������
		if (pre.empty() || vin.empty())
			return NULL;

		//�Ȼ��ֳ������ڵ�,�ٻ��ֳ�����������,��ʱ��������������������������,����
		//������������ֳ����Ե�����,Ȼ��ݹ�������б���
		//0.����������������
		vector<int> left_pre, left_vin, right_pre, right_vin;
		//�������ڵ�
		TreeNode*root = new TreeNode(pre[0]);
		int root_vin_index;            //���������root���±�
		//1.�ҳ����ڵ�
		for (size_t i = 0; i<pre.size(); ++i) {
			if (vin[i] == pre[0]) {
				root_vin_index = i;
				break;
			}
		}
		//2.Ѱ�ҳ����������Ե�����
		//left_treei
		for (int i = 0; i<root_vin_index; ++i) {
			left_pre.push_back(pre[i + 1]);
			left_vin.push_back(vin[i]);
		}

		//righ_tree;
		for (size_t i = root_vin_index + 1; i<pre.size(); ++i) {
			right_pre.push_back(pre[i]);
			right_vin.push_back(vin[i]);
		}

		root->left = reConstructBinaryTree(left_pre, left_vin);
		root->right = reConstructBinaryTree(right_pre, right_vin);

		return root;
	}
}; 


class Solution {
public:

	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		//ǰ���������    �����������
		if (pre.empty() || vin.empty())
			return NULL;
		//�����ֱ�ӻ��ֺ�����������,���������еݹ�
		//�Ȼ��ֳ������ڵ�,�ٻ��ֳ�����������,��ʱ��������������������������,����
		//������������ֳ����Ե�����,Ȼ��ݹ�������б���
		//0.����������������
		vector<int> left_pre, left_vin, right_pre, right_vin;
		//�������ڵ�
		TreeNode*root = new TreeNode(pre[0]);
		int root_vin_index;            //���������root���±�
		//1.�ҳ����ڵ�
		for (size_t i = 0; i<pre.size(); ++i) {
			if (vin[i] == pre[0]) {
				root_vin_index = i;
				break;
			}
		}
		//2.Ѱ�ҳ����������Ե�����
		//left_treei
		for (int i = 0; i<root_vin_index; ++i) {
			left_pre.push_back(pre[i + 1]);
			left_vin.push_back(vin[i]);
		}

		//righ_tree;
		for (size_t i = root_vin_index + 1; i<pre.size(); ++i) {
			right_pre.push_back(pre[i]);
			right_vin.push_back(vin[i]);
		}

		root->left = reConstructBinaryTree(left_pre, left_vin);
		root->right = reConstructBinaryTree(right_pre, right_vin);

		return root;
	}


	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {

		int n = pre.size();
		if (n == 0)
			return nullptr;
		else return ConstructBinaryTree(pre, vin, 0, 0, n - 1, n - 1);
	}
	//�������һ��ֻ�����Ǵ�����,Ҳ����Ҫÿ�ζ�����һ������,�����˷�
	//�����������ֿ�,���ֺ����еı߽�
	//left_pre,right_pre
	//left_vin,right_vin
	TreeNode* ConstructBinaryTree(vector<int>& pre, vector<int>& vin, int left_pre, int left_vin,
		int right_pre, int right_vin) {

		//1.�������ڵ�
		TreeNode * root = new TreeNode(pre[left_pre]);
		if (left_pre == right_pre)
			return root;
		//2.Ѱ����������е��Ǹ�ֵ,ÿ�ζ���ǰ��������еĵ�һ��
		int vin_index;
		for (int i = left_vin; i <= right_vin; ++i) {
			if (vin[i] == pre[left_pre]) {
				vin_index = i;
				break;
			}
		}
		int left_len = vin_index - left_vin;
		int right_len = right_vin - vin_index;

		if (left_len > 0)
			//						��������          ������ǰ���������left_pre + 1,left_len + left_pre 
								//					�����������������left_vin ,vin_index - 1,
			root->left = ConstructBinaryTree(pre, vin, left_pre + 1, left_vin, left_len + left_pre, vin_index - 1);
		if (right_len > 0)
			root->right = ConstructBinaryTree(pre, vin, left_len + left_pre + 1, vin_index + 1, right_pre, right_vin);
		return root;
	}





public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		int ret;
		if (stack2.empty()){
			while (stack1.size()) {
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		if (stack2.size() == 0)
			throw new std::exception("queue is empty!!");
		ret = stack2.top();
		stack2.pop();
		return ret;
	}
private:
	stack<int> stack1;
	stack<int> stack2;





	public:
		int minNumberInRotateArray(vector<int> rotateArray) {
			//���ֲ��ҷ���һ�ֱ���
			if (rotateArray.empty())
				return 0;

			int length = rotateArray.size();
			int left = 0;
			int right = length -1 ;
			int mid;
			while (rotateArray[left] >= rotateArray[right]) {
				if (right - left == 1) {
					mid = right;
					break;
				}
				mid = left + (right - left) / 2;
				if (rotateArray[mid] >= rotateArray[left]) {
					left = mid;
				}
				else if (rotateArray[mid] <= rotateArray[right]) {
					right = mid;
				}
			}
			return rotateArray[mid];
		}

//------------------------------------------------------------------------
		//�����Ĵη�
		bool g_input = false;        //ȫ�ֵ�����ȷ�����־λ

		bool equal(int num1, int num2) {
			if (num1 - num2 > -0.0000001 && num1 - num2 < 0.0000001)
				return true;
			else
				return false;
		}
		double Func(double base, unsigned int absexponent) {
			double result = 1.0;
			for (int i = 1; i <= absexponent; ++i) {
				result *= base;
			}
			return result;
		}
		double Power(double base, int exponent) {

			//ÿ�α�־λ������Ҫ����λ
			//1.�ж��Ƿ����޴������� ,�õ�����0 ���Ƚ�
			//2.���ָ���Ǹ����Ļ����Ǿ�Ҫȡ����ֵ,���Ǿ���������
			//3.���ָ���Ǹ����Ļ�,���Ǿ�Ҫȡ����������

			g_input = false;
			double result = 0;
			//0 �ĸ����η���û�������,0��n�η�Ϊ0
			if (equal(base, 0.0) && exponent < 0) {
				g_input = true;
				return 0.0;
			}
			unsigned int absexponent = (unsigned int)exponent;
			if (exponent < 0) {
				absexponent = -exponent;
			}
			result = Func(base, absexponent);
			if (exponent < 0) {
				result = 1 / result;
			}

			return result;
		}

//-------------------------------------------------------------------------

		void swap(int& right, int &left) {
			int temp = right;
			right = left;
			left = temp;
		}
		void reOrderArray(vector<int> &array) {
			if (array.empty())
				return;
			int right = array.size()-1;
			int left = 0;
			while (left < right) {
				while (left < right && (array[left] & 0x1) == 1) {
					++left;
				}
				while (left < right && (array[right] & 0x1) == 0) {
					right--;
				}
				if (left < right) {
					swap(array[right], array[left]);
				}
			}
		}

//-----------------------------------------
		//�������ı����Ļ�,���Ƕ���Ҫ�ҳ����ڵ��λ��,��ȥ�ҳ���������,��ʱ�������������Ǹ��ڵ�
		//�ݹ鴦����Щ����,
		bool VerifySquenceOfBST(vector<int> sequence) {
			if (sequence.empty())
				return false;
			int root = sequence[sequence.size() - 1];        //���Ľڵ�
			int length = sequence.size();
			//1.Ѱ����������,�����������������λ��,����������
			//Ѱ��������,������С�ڸ��ڵ�

			int i = 0;
			for (; i < length - 1; i++) {
				if (sequence[i] > root)
					break;
			}
			//Ѱ��������,���������ڸ��ڵ�
			int j = i;
			for (; j < length - 1; j++) {
				//���ѭ�������Ľڵ���С�ڸ��ڵ����ô�϶��Ǵ����
				if (sequence[j] < root)
					return false;
			}
			if (i>0) {
				//��ʱ����ߵı߽�Ϊ---(0,i)
				vector<int> arr2;
				for (int k = 0; k < i; k++) {
					arr2.push_back(sequence[k]);
				}
				bool left = VerifySquenceOfBST(arr2);

			}
			if (i < length - 1){
				//��ʱ���ұߵı߽�Ϊ---(i + 1 , sequence.size() - 1 - i)
				vector<int> arr3;
				for (int k = i; k < length - 1; k++) {
					arr3.push_back(sequence[k]);
				}
				bool right = VerifySquenceOfBST(arr3);
			}


			return (left && right);
		}

		struct RandomListNode {
			int label;
			struct RandomListNode *next, *random;
			RandomListNode(int x) :
				label(x), next(NULL), random(NULL) {
			}
		};


		RandomListNode* Clone(RandomListNode* pHead)
		{
			RandomListNode* pnewNode = pHead;
			//��һ��������Ҫ���ƵĶ���,�ڶ����ٽ����ƵĽڵ�֮��Ͽ�����
			if (pHead == NULL) {
				pHead = NULL;
				return pHead;
			}
			//��һ��
			while (pnewNode) {

				RandomListNode *ppnewNode = new RandomListNode(pnewNode->label);
				ppnewNode->next = pnewNode->next;
				pnewNode->next = ppnewNode;

				pnewNode = ppnewNode->next;

			}
			pnewNode = pHead;
			//�ڶ�����ԭ����
			while (pnewNode) {
				RandomListNode *node = pnewNode->next;
				if (pnewNode->random) {
					node->random = pnewNode->random->next;
				}
				pnewNode = node->next;
			}
			RandomListNode *pCloneHead = pHead->next;
			RandomListNode *tmp;
			pnewNode = pHead;
			while (pnewNode->next) {
				tmp = pnewNode->next;
				pnewNode->next = tmp->next;
				pnewNode = tmp;
			}

			return pCloneHead;
		}
};
//
//#if 0
//class Test{
//public:
//	static Test* GetInstance() {
//		return &m_instance;				//ͨ������ӿ���ʵ��������
//	}
//	void print() {
//		cout << "print()" << endl;
//	}
//
//private:
//	Test(){};
//	Test(Test &test) = delete;
//	Test& operator=(const Test&) = delete;
//
//
//	~Test(){};
//	 static Test m_instance;			//������һ������
//};
////�����static��Ա������,���ǲ���
//Test Test::m_instance;
////
////���� �������޶���ʹ���������
//		Test* test;
//		Test * test2 = test->GetInstance();
////#endif




#include<mutex>
class Test2 {
public:
	static Test2* GetInstance() {
		if (m_instance == nullptr) {
			_mutex.lock();
			if (m_instance == nullptr) {
				m_instance = new Test2();
			}
			_mutex.unlock();
		}
		return m_instance;
	}
	void print() {
		cout << "����ģʽ" << endl;
	}
	class  rabbles{
		~rabbles() {
			if (Test2::m_instance) {
				delete Test2::m_instance;
			}
		}
	};
	static rabbles rabb;

private:
	Test2() {}
	Test2(const Test2& test){}

	static Test2* m_instance;
	static mutex _mutex;

	
};
Test2* Test2::m_instance = nullptr;
mutex Test2::_mutex;
//Test2::rabbles rabb;


void SeqListALL(int *arr, int data,int length) {
	if (arr == NULL) {
		return;
	}
	int k = 0;
	for (int i = 0; i < length; ++i) {
		if (arr[i] != data) {
			arr[k++] = arr[i];
		}
	}
}

#endif
#include<assert.h>
typedef int SLDataType;


typedef struct Slist {
	SLDataType _data;
	struct Slist *next;
};
/*
	�����ڳ�ʼ����ʱ�����ÿվ�����
	�ڽ���β���ʱ����ʵ���ݵ����Ǹ�ͷ�ڵ�,
	������Ҫ�����ڵ����β��,βɾ
*/
void SlistInit(Slist* pHead) {

	pHead = NULL;
}
void SlistPushback(Slist** pHead, int data){
	if (*pHead == NULL) {
		*pHead = (Slist*)malloc(sizeof(Slist));
		if (*pHead == NULL) {
			return;
		}
		(*pHead)->_data = data;
		(*pHead)->next = NULL;
		return;
	}
	Slist* pNode = *pHead;
	Slist* preNode = NULL;
	while (pNode) {
		preNode = pNode;
		pNode = pNode->next;
	}
	Slist* pNewNode = (Slist*)malloc(sizeof(Slist));
	pNewNode->_data = data;
	preNode->next = pNewNode;
	pNewNode->next = NULL;
	return;
}


double add(double right,double left) {
	return right + right;
}
int add(int right, int left) {
	return right + right;
}
void TestFunc(int a) {
	cout << "TestFunc()" << endl;
}
void TestFunc(double a = 10) {
	cout << "TestFunc()" << endl;
}
stack<char> stak;
bool isValid(string s) {
	if (s.empty())
		return NULL;
	size_t length = s.size() - 1;
	size_t i = 0;
	for(i ;i<=length;++i) {
		if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
			if (stak.empty())
				return false;

			if (s[i] == ')' && stak.top() == '(' ||
				s[i] == ']' && stak.top() == '[' ||
				s[i] == '}' && stak.top() == '{') {
				
				stak.pop();
				continue;
			}
			else
				return false;

		}
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			stak.push(s[i]);
		}
	}
	if (stak.empty())
		return true;
	else
		return false;
}
void AdjustDown(int *arr ,int parent,int size) {
		
	//����һ��С��,���ǵĸ��ڵ㶼�����ǵ��ӽڵ�С

	int child = 2 * parent + 1;
	if (arr[parent] < arr[child])
		return;

	while (child <size) {
		if (child+1 <size && arr[child] > arr[child + 1]) {
			child = child + 1;
		}
		if (arr[child] < arr[parent]){
			int temp = arr[child];
			arr[child] = arr[parent];
			arr[parent] = temp;

		}
		parent = child;
		child = 2 * parent + 1;
	}
}

//����һ����,ʹ�����µ�����,�����һ����Ҷ�ӽڵ㿪ʼ,���µ�����ǰ���������Ѿ��������Ѿ���
//�ź���
void makeHeap(int *arr ,int size) {

	for (int root = (size - 2) / 2; root >= 0; --root) {
		AdjustDown(arr,root,size);
	}
	for (int i = 0; i < size; ++i) {
		int temp = arr[0];
		arr[0] = arr[size - i -1];
		arr[size - i -1] = temp;
		AdjustDown(arr, 0, size - i - 1);
	}
}

class father {
public:
	father(int a = 1):_a(a){}
	virtual void print() {
		cout << "father()" << endl;
	}
	void print2() {
		cout << "print" << endl;
	}
	void display() {
		cout << _a << endl;
	}
	int _a;
};

class son: public father {
public:
	son():father(3){}
	virtual void print() {
		cout << "son()" << endl;
	}
	void display() {
		cout << _a << endl;
	}
	void print2() {
		cout << "printf2" << endl;
	}
	//int _a = 4;
}; 


class a
{
public:
	int _a;
};

class b :virtual public a
{
public:
	int _b;
};
class c :virtual public a
{
public:
	int _c;
};
class d :public b, public c
{
public:
	int _d;
};



string str;
int i = 0;
typedef struct TreeNode{
	struct TreeNode* lchild, *rchild;
	char val;
	TreeNode(char c) :lchild(NULL), rchild(NULL), val(c){}
}TreeNode;
TreeNode* CreateNode(TreeNode* root) {
	char c = str[i++];
	if (c == '#')
		return NULL;
	root = new TreeNode(c);
	root->lchild = CreateNode(root->lchild);
	root->rchild = CreateNode(root->lchild);
	return root;
}
void inoderNode(TreeNode* root) {
	if (root == NULL)
		return;
	inoderNode(root->lchild);
	cout << root->val << " ";
	inoderNode(root->rchild);

}


class Solution {
public:
	vector<int>arr;
	vector<int> twoSum(vector<int>& nums, int target) {
		if (nums.empty())
			return arr;
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = i+1; j < nums.size(); ++j) {
				if ( nums[i] +nums[j] == target ) {
					arr.push_back(i);
					arr.push_back(j);
					break;
					return arr;
				}
			}
		}
	}


	int NumberOf1Between1AndN_Solution(int n)
	{
		int count = 0;
		for (int i = 1; i <= n; ++i) {
			int temp = i;
			while (temp) {
				if ((temp % 10) == 1) {
					count++;
				}
				temp = temp / 10;
			}
		}
		return  count;
	}
};


#include <iostream>
using namespace std;

class A{
public:
	int n;
	A(int n) :n(n){}
	void display(){ cout << "Class A: n=" << n << endl; }
};

class B : public A{
public:
	B(int n) :A(n){}
	void display(){ cout << "Class B: n=" << n << endl; }
};

class C : public A{
public:
	C(int n) :A(n){}
	void display(){ cout << "Class C: n=" << n << endl; }
};

int main() {
	
	Solution test;
	test.NumberOf1Between1AndN_Solution(5);
	father* s1 = new son;
	//���ھ�̬�󶨺Ͷ�̬��
	//�������ڱ����ڼ�ͻ�ȥ��,���ھ�̬��,��Ϊ�����������̬������,
	//������������Լ���ʵ�ֽӿ�,�ڱ����ڼ����������������father�Ķ���,Ҳ����˵Ϊʲô��son���ܱ�father��ֵ��Ե��

	//��̬��,


	
	return 0;
}







