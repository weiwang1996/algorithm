void QuickSortList(Node* head, Node* tail)
	{
		if (head == NULL || head == tail || head->_next == tail)
			return;

		Node* prev = head;
		Node* cur = head->_next;
		int key = head->_data;
		while (cur != tail)
		{
			if (cur->_data < key)
			{
				prev = prev->_next;
				if (prev != cur)
				{
					swap(prev->_data, cur->_data);
				}
			}

			cur = cur->_next;
		}

		swap(prev->_data, head->_data);

		QuickSortList(head, prev);
		QuickSortList(prev->_next, tail);
	}
