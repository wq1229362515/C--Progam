

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
#endif

class Solution {
public:
#if 0
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



#endif

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
};

int main() {


	Solution test;
	vector<int> arr = { 1, 2, 3, 4, 5 ,6,7};
	test.reOrderArray(arr);

	return 0;
}







