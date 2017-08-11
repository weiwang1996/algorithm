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
