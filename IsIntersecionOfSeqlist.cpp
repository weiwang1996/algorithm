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
