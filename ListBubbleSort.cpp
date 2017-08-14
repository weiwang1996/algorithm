void BubbleSortList(Node* head)
	{
		if (head == NULL || head->_next == NULL)
			return;
		Node* tail = NULL;
		
		while (tail != head)
		{
			bool exchange = false;
			Node* cur = head;
			Node* next = cur->_next;
			while (next != tail)
			{
				if (cur->_data > next->_data)
				{
					swap(cur->_data, next->_data);
					exchange = true;
				}

				cur = cur->_next;
				next = next->_next;
			}

			if (exchange == false)
			{
				break;
			}

			tail = cur;
		}
	}
