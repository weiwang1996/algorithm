#include<iostream>
#include<vector>
using namespace std;
struct ListNode
{
	ListNode* _next;
	int _data;
	ListNode(int x = 0)
		:_next(NULL)
		, _data(x)
	{}
};
typedef ListNode Node;
void Print(Node *pHead)
{
	if (pHead == NULL)
	{
		return;
	}
	Node* cur = pHead;
	while (cur)
	{
		cout << cur->_data << "->";
		cur = cur->_next;
		if (!cur)
			cout << "NULL";
	}
	cout << endl;
}

void PushBack(Node*& pHead, int x)
{
	if (pHead == NULL)
	{
		pHead = new Node(x);
	}
	else
	{
		Node*cur = pHead;
		while (cur->_next)
		{
			cur = cur->_next;
		}
		cur->_next = new Node(x);
	}
}
void distory(Node*& pHead)
{
	Node* cur = pHead;
	Node* del = cur;
	while (cur)
	{
		cur = cur->_next;
		delete del;
		del = cur;
	}
	pHead = NULL;
}
Node* Find(Node* pHead, int x)
{
	if (pHead == NULL)
		return NULL;
	Node* cur = pHead;
	while (cur)
	{
		if (cur->_data == x)
			return cur;
		cur = cur->_next;
	}
	return NULL;
}
void DeleteNodeNonTail(Node*pHead,Node*pos)
{
	if (pHead == NULL || pos == NULL||pos->_next==NULL)
		return;
	Node* del = pos->_next;
	pos->_data = del->_data;
	pos->_next = del->_next;
	delete del;
}
Node* Merge(Node* pHead1,Node* pHead2)
{
	if (pHead1 == NULL)
		return pHead2;
	if (pHead2 == NULL)
		return pHead1;
	Node*Newhead = NULL;
	if (pHead1->_data < pHead2->_data)
	{
		Newhead = pHead1;
		Newhead->_next = Merge(pHead1->_next, pHead2);
	}
	else
	{
		Newhead = pHead2;
		Newhead->_next = Merge(pHead1, pHead2->_next);
	}
	return Newhead;
}
bool IsCircle(Node* pHead)
{
	bool result = false;
	if (pHead == NULL)
		return result;
	Node* pFast = pHead;
	Node* pSlow = pHead;
	while (pFast&&pFast->_next)
	{
		pSlow = pSlow->_next;
		pFast = pFast->_next->_next;
		if (pFast == pSlow)
		{
			result = true; break;
		}
	}
	return result;
}
size_t CircleLen(Node* pHead)
{
	if (pHead == NULL)
		return 0;
	Node* pFast = pHead;
	Node* pSlow = pHead;
	Node* pMeet = NULL;
	size_t count=0;
	while (pFast&&pFast->_next)
	{
		pSlow = pSlow->_next;
		pFast = pFast->_next->_next;
		if (pFast == pSlow)
		{
			pMeet=pFast; break;
		}
	}//此时pMeet=相遇地址
	pFast = pHead;
	while (pFast != pMeet)
	{
		pFast = pFast->_next;
		pMeet = pMeet->_next;
	}
	pFast = pFast->_next;
	count++;//先走一步使得pFast!=pMeet
	while (pFast != pMeet)//环的交点
	{
		pFast=pFast->_next;
		count++;
	}
	return count;
}
struct ComplexNode
{
	int _data; // 数据 
	struct ComplexNode * _next; // 指向下一个节点的指针 
	struct ComplexNode * _random; // 指向随机节点（可以是链表中的任意节点 or 空） 
	ComplexNode(int x)
		:_data(x)
		, _next(NULL)
		, _random(NULL)
	{}
};

ComplexNode* CopyComplexList(ComplexNode*pHead)
{
	if (pHead==NULL)
	return NULL;
	//先复制链接
	ComplexNode* cur = pHead;
	ComplexNode *next = NULL;
	ComplexNode *temp = NULL;
	while (cur)
	{
		next = cur->_next;
		temp = new ComplexNode(cur->_data);
		cur->_next = temp;
		temp->_next = next;
		cur=next;
	}
	//_random处理
	cur = pHead;
	while (cur)
	{
		next = cur->_next;
		if (cur->_random != NULL)
			next->_random = cur->_random->_next;
		else
			next->_random = NULL;
		cur = next->_next;
	}
//断开链接
	cur = pHead;
	ComplexNode* Newhead = cur->_next;
	
	while (cur)
	{
		next = cur->_next;
		cur->_next = next->_next;
		cur = cur->_next;
		if (cur)
			next->_next = cur->_next;
		else
			break;
	}
	return Newhead;
}
Node* IsIntersecion(Node*pHead1, Node *pHead2)//相遇点
{
	if (pHead1 == NULL || pHead2 == NULL)
		return NULL;
	Node* pcur1 = pHead1;
	Node* pcur2 = pHead2;
	Node *Tail = NULL;
	int step1 = 0, step2 = 0;
	while (pcur1->_next || pcur2->_next)
	{
		if (pcur1->_next)
		{
			pcur1 = pcur1->_next;
			step1++;
		}
		if (pcur2->_next)
		{
			pcur2 = pcur2->_next;
			step2++;
		}
	}
	if (pcur1 == pcur2)
		Tail = pcur1;
	pcur2=pHead2;
	pcur1 = pHead1;
	int step = step1 - step2;
	if (step < 0)
	{
		step = -step;
		while (step--)
		{
			pcur2= pcur2->_next;
		}	
	}
	else
	{
		while (step--)
		{
			pcur1 = pcur1->_next;
		}
	}
	while (pcur1&&pcur2&&pcur1 != pcur2)
	{
		pcur1 = pcur1->_next;
		pcur2 = pcur2->_next;
	}
	return pcur1;
}
Node* Reverse(Node* pHead)
{
	if (pHead == NULL || pHead->_next==NULL)
		return pHead;
	Node* cur = pHead;
	Node* temp = NULL;
	Node* newhead = NULL;
	while (cur)
	{
		temp = cur;
		cur = cur->_next;
		temp->_next=newhead;
		newhead = temp;
	}
	return newhead;
}
void PrintOfReverse(Node*pHead)
{
	if (pHead == NULL)
		return;
	PrintOfReverse(pHead->_next);
	cout << pHead->_data<<"  ";
}
Node* IsInsersect(Node* pHead1, Node* pHead2)
{
	if (pHead1 == NULL || pHead2 == NULL)
		return NULL;
	int loop1 = 0;
	int loop2 = 0;
	Node* pNode1 = pHead1;
	Node* pNode2 = pHead2;
	while (pNode1->_next)
	{
		++loop1;
		pNode1 = pNode1->_next;
	}
	while (pNode2->_next)
	{
		++loop2;
		pNode2 = pNode2->_next;
	}
	if (pNode1 != pNode2)
		return NULL;
	int res = loop1 - loop2;
	pNode1 = pHead1;
	pNode2 = pHead2;
	if (res > 0)
	{
		while (res--)
			pNode1 = pNode2->_next;
	}
	else if (res < 0)
	{
		res = -res;
		while (res--)
			pNode2 = pNode2->_next;
	}
	while (pNode1 != pNode2)
	{
		pNode1 = pNode1->_next;
		pNode2 = pNode2->_next;
	}
	return pNode1;
}
Node* TailTopK(Node* pHead, int k)
{
	if (pHead == NULL || k <= 0)
		return NULL;
	Node* pFast = pHead;
	Node* pSlow = pHead;
	while (pFast&&--k)
	{
		pFast = pFast->_next;
	}
	if (pFast == NULL)
		return NULL;
	while (pFast->_next)
	{
		pFast = pFast->_next;
		pSlow = pSlow->_next;
	}
	return pSlow;
}
void BubbleSort(Node* pHead)
{
	if (pHead == NULL || pHead->_next == NULL)
		return ;
	Node* cur = pHead;
	Node* end = NULL;
	while (cur)
	{
		cur = cur->_next;
	}
	end = cur;
	cur = pHead;
	while (end != pHead)
	{
		bool flag = false;
		cur = pHead;
		Node* next = cur->_next;
		while (next!= end)
		{
			
			if (cur->_data > next->_data)
			{
				swap(cur->_data, next->_data);
				flag = true;
			}
			cur = cur->_next;
			next = next->_next;
		}
		if (flag == false)
			return;
		end = cur;
	}
}
Node*  Different(Node*& pHead1, Node*&pHead2)
{
	vector<int> v;
	if (pHead1 == NULL || pHead2 == NULL)
		return NULL;
	//先给两个链表排序
	BubbleSort(pHead1);
	BubbleSort(pHead2);
	Node* cur1 = pHead1;
	Node* cur2 = pHead2;
	while (cur1&&cur2)
	{
		if (cur1->_data < cur2->_data)
		{
			v.push_back(cur1->_data);
			cur1 = cur1->_next;
		}
		else if (cur1->_data>cur2->_data)
		{
			v.push_back(cur2->_data);
			cur2 = cur2->_next;
		}
		else
		{
			cur1 = cur1->_next;
			cur2 = cur2->_next;
		}
	}
	if (cur1)
	{
		while (cur1)
		{
			v.push_back(cur1->_data);
			cur1 = cur1->_next;
		}
	}
	else
	{
		while (cur2)
		{
			v.push_back(cur2->_data);
			cur2 = cur2->_next;
		}
	}
	distory(pHead1);
	for (int i = 0; i < v.size(); ++i)
	{
		PushBack(pHead1, v[i]);
	}
	return pHead1;
}
void Test1()
{
	Node* pHead1 = NULL;
	Node*pHead2 = NULL;
	PushBack(pHead1, 1);
	PushBack(pHead2, 2);
	PushBack(pHead2, 3);
	PushBack(pHead1, 4);
	PushBack(pHead1, 5);
	PushBack(pHead2, 6);
//	DeleteNodeNonTail(pHead, Find(pHead, 5));
	Node* ret = Merge(pHead1, pHead2);
	Print(ret);
	//distory(pHead1);
}
void Test4()
{
	ComplexNode* pHead = new ComplexNode(1);
	ComplexNode* node1 = new ComplexNode(2);
	ComplexNode* node2 = new ComplexNode(3);
	ComplexNode* node3 = new ComplexNode(4);
	pHead->_next = node1;
	pHead->_random = node2;
	node1->_next = node2;
	node1->_random = pHead;
	node2->_next = node3;
	node2->_random = node3;
	node3->_random = node1;
	ComplexNode* ret = CopyComplexList(pHead);
}
void Test2()
{
	Node* pHead1 = NULL;
	Node*pHead2 = NULL;
	PushBack(pHead1, 1);
	PushBack(pHead1, 2);
	PushBack(pHead1, 3);
	PushBack(pHead2, 4);
	PushBack(pHead2, 5);
	PushBack(pHead2, 6);
	PushBack(pHead2, 7);
//	pHead1 = Find(pHead2, 7);
	Find(pHead1, 3)->_next = Find(pHead2, 6);
	//Find(pHead1, 7)->_next = Find(pHead1, 4);
	//cout<<CircleLen(pHead1)<<endl;
	//cout << IsCircle(pHead1)<<endl;
	//Print(pHead1);
//	distory(pHead1);
	cout << IsInsersect(pHead1, pHead2)->_data<<endl;
	//cout << IsIntersecion(pHead1, pHead2)->_data;
}
void Test3()
{
	Node* pHead1 = NULL;
	Node* pHead2 = NULL;
	PushBack(pHead2, 2);
	PushBack(pHead2, 8);
	PushBack(pHead2, 1);
	PushBack(pHead2, 7);
	PushBack(pHead2, 3);
	PushBack(pHead1, 5);
	PushBack(pHead1, 2);
	PushBack(pHead1, 1);
	PushBack(pHead1, 3);
	PushBack(pHead1, 0);
	//Node* ret = Reverse(pHead);
	//cout << TailTopK(pHead, 1)->_data << endl;
	//cout<< TailTopK(pHead, 5)->_data << endl;
	//cout << TailTopK(pHead, 3)->_data;
	Print(pHead1);
	//BubbleSort(pHead1);
	Print(pHead2);
	Print(Different(pHead1, pHead2));
	//PrintOfReverse(pHead);
}
int Add(int x, int y)
{
	int sum,carry;
	do
	{
		sum = x^y;
		carry = (x&y)<<1;
		y = carry;
		x = sum;
	} while (y != 0);	
	return x;
}
int main()
{
	//cout<<Add(3,5);
	//Test1();
//	Test2();
	//Test4();
Test3();
	return 0;
}