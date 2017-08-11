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
