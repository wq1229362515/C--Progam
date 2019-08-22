

/*
	异常安全性 : 不破坏数据,不任何资源泄露    --内存泄露
												资源泄露   

	一.赋值运算符函数需要注意的问题

		1. 返回值类型的声明
		2. 传入的参数是否是const 引用 ,如果是一个常量传入会调用拷贝构造函数
		3. this指针和当前对象的判断
		4. 释放自己原有的内存空间

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

	//初阶的做法,并没有开辟一个新的内存空间,只是删除了,这样并没有考虑到申请新空间的异常性

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
	//	1.开辟新的空间(深浅拷贝的问题)
	//	2.释放原有的空间
	//	3.拷贝内容到新的地址空间中
	//	4.将新的地址空间传给旧的地址空间
	//	*/
	//	char* newchar = new char[strlen(str.my_data) +1];
	//	strcpy(newchar, str.my_data);
	//	delete[]my_data;
	//	my_data = newchar;

	//	return *this;
	//}

	//进阶的做法利用这个函数栈帧的特性,自行的析构函数
	//新创建的newdata他的地址是新的地址
	//利用连续改变地址的指向
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

//二维数字寻找
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


//空白格替换
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


//尾插链表

/*
	在链表中去遍历的话空间复杂度是一个o(n)
	在数组里面则是一个o(1)

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
	//基于递归的话,如果递归次数太多会引起栈溢出
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
	前序遍历 第一个永远是根节点
	中序遍历    根节点左边是左子树 右边右子树
	后序遍历 最后一个永远是根节点
	利用中序遍历序列才能找到根节点的值

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
		//前序遍历序列    中序遍历序列
		if (pre.empty() || vin.empty())
			return NULL;

		//先划分出来根节点,再划分出来左右子树,这时候左右子树各自又有两个序列,根据
		//中序遍历来划分出各自的序列,然后递归的来进行遍历
		//0.创建出来左右序列
		vector<int> left_pre, left_vin, right_pre, right_vin;
		//构建根节点
		TreeNode*root = new TreeNode(pre[0]);
		int root_vin_index;            //中序遍历中root的下标
		//1.找出根节点
		for (size_t i = 0; i<pre.size(); ++i) {
			if (vin[i] == pre[0]) {
				root_vin_index = i;
				break;
			}
		}
		//2.寻找出左右树各自的序列
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
		//前序遍历序列    中序遍历序列
		if (pre.empty() || vin.empty())
			return NULL;
		//这个是直接划分好两个子序列,在子序列中递归
		//先划分出来根节点,再划分出来左右子树,这时候左右子树各自又有两个序列,根据
		//中序遍历来划分出各自的序列,然后递归的来进行遍历
		//0.创建出来左右序列
		vector<int> left_pre, left_vin, right_pre, right_vin;
		//构建根节点
		TreeNode*root = new TreeNode(pre[0]);
		int root_vin_index;            //中序遍历中root的下标
		//1.找出根节点
		for (size_t i = 0; i<pre.size(); ++i) {
			if (vin[i] == pre[0]) {
				root_vin_index = i;
				break;
			}
		}
		//2.寻找出左右树各自的序列
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
	//和上面的一样只是我们传引用,也不需要每次都复制一份数据,避免浪费
	//将左右子树分开,划分好序列的边界
	//left_pre,right_pre
	//left_vin,right_vin
	TreeNode* ConstructBinaryTree(vector<int>& pre, vector<int>& vin, int left_pre, int left_vin,
		int right_pre, int right_vin) {

		//1.创建根节点
		TreeNode * root = new TreeNode(pre[left_pre]);
		if (left_pre == right_pre)
			return root;
		//2.寻找中序遍历中的那个值,每次都是前序遍历序列的第一个
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
			//						划分区间          左树的前序遍历区间left_pre + 1,left_len + left_pre 
								//					左树的中序遍历区间left_vin ,vin_index - 1,
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
			//二分查找法的一种变种
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
		//整数的次方
		bool g_input = false;        //全局的输正确错误标志位

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

			//每次标志位进来都要给置位
			//1.判断是否有无错误的输出 ,让底数和0 做比较
			//2.如果指数是负数的话我们就要取绝对值,不是就正常运行
			//3.如果指数是负数的话,我们就要取倒数来运行

			g_input = false;
			double result = 0;
			//0 的负数次方是没有意义的,0的n次方为0
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
		//二叉树的遍历的话,他们都需要找出根节点的位置,再去找出左右子树,这时候左右子树又是根节点
		//递归处理这些问题,
		bool VerifySquenceOfBST(vector<int> sequence) {
			if (sequence.empty())
				return false;
			int root = sequence[sequence.size() - 1];        //根的节点
			int length = sequence.size();
			//1.寻找左右子树,标记左右子树结束的位置,就是右子树
			//寻找左子树,左子树小于根节点

			int i = 0;
			for (; i < length - 1; i++) {
				if (sequence[i] > root)
					break;
			}
			//寻找右子树,右子树大于根节点
			int j = i;
			for (; j < length - 1; j++) {
				//如果循环遍历的节点有小于根节点的那么肯定是错误的
				if (sequence[j] < root)
					return false;
			}
			if (i>0) {
				//这时候左边的边界为---(0,i)
				vector<int> arr2;
				for (int k = 0; k < i; k++) {
					arr2.push_back(sequence[k]);
				}
				bool left = VerifySquenceOfBST(arr2);

			}
			if (i < length - 1){
				//这时候右边的边界为---(i + 1 , sequence.size() - 1 - i)
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
			//第一步创建出要复制的对象,第二步再将复制的节点之间断开连接
			if (pHead == NULL) {
				pHead = NULL;
				return pHead;
			}
			//第一步
			while (pnewNode) {

				RandomListNode *ppnewNode = new RandomListNode(pnewNode->label);
				ppnewNode->next = pnewNode->next;
				pnewNode->next = ppnewNode;

				pnewNode = ppnewNode->next;

			}
			pnewNode = pHead;
			//第二步拆开原来的
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
//		return &m_instance;				//通过这个接口来实例化对象
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
//	 static Test m_instance;			//定义了一个对象
//};
////定义的static成员在类中,但是不在
//Test Test::m_instance;
////
////类型 作用域限定符使用这个对象
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
		cout << "懒汉模式" << endl;
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
	链表在初始化的时候将其置空就行了
	在进行尾插的时候其实传递的是那个头节点,
	链表需要遍历节点进行尾插,尾删
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
		
	//建立一个小堆,他们的父节点都比他们的子节点小

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

//创建一个堆,使用向下调整法,从最后一个非叶子节点开始,向下调整的前提是我们已经的子树已经被
//排好了
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
	//关于静态绑定和动态绑定
	//这个语句在编译期间就会去做,属于静态绑定,因为他并不满足多态的条件,
	//所以他会调用自己的实现接口,在编译期间编译器将他当做了father的对象,也就是说为什么你son不能被father赋值的缘故

	//静态绑定,


	
	return 0;
}







