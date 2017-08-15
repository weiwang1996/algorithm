#include<iostream>
using namespace std;
struct Node
{
	int _data;
	Node* _next;
	Node(int x)
		:_data(x)
		, _next(NULL)
	{}
};
void Print(Node* head)
{
	if (head == NULL)
		return;
	Node* cur = head;
	while (cur)
	{
		cout << cur->_data<<"->";
		cur = cur->_next;
	}
	cout << endl;
}
Node* GreatReverse(Node* head, int k)
{
	if (head == NULL || head->_next == NULL || k <= 1)
		return head;
	Node* cur = head;
	Node* flag = head;
	Node* Newhead = NULL;
	int count = 0;
	while (cur)
	{
		cur = cur->_next;
		count++;
	}
	for (int i = 0; i < (count / k); ++i)
	{
		Node* cur = flag;
		Node* prev = NULL;
		Node*newhead = NULL;
		Node* temp = flag;
		int num = k;
		while (num--)
		{
			prev = cur;
			cur = cur->_next;
			prev->_next = newhead;
			newhead = prev;
			if (num - 1 == 0)
				temp = cur;
		}
		if (i == 0)
			Newhead = newhead;
		flag->_next = cur;
		flag = flag->_next;
	}
	return Newhead;
}
void Test()
{
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	Node* n5 = new Node(5);
	Node* n6 = new Node(6);
	Node* n7 = new Node(7);
	n1->_next = n2;
	n2->_next = n3;
	n3->_next = n4;
	n4->_next = n5;
	n5->_next = n6;
	n6->_next = n7;
	Print(n1);
	Node* ret = GreatReverse(n1, 3);
	Print(ret);
}
int main()
{
	Test();
	return 0;
}
