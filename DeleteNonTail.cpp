void DeleteNonTail(Node* pos)
	{
		assert(pos && pos->_next);
		Node* next = pos->_next;
		Node* nextNext = next->_next;

		pos->_data = next->_data;
		pos->_next = nextNext;
		delete next;
	}
