bool _GetPaths(Node* root, Node*node, stack<Node*>&s)
	{
		if (root == NULL)
			return false;
		s.push(root);
		if (node == root)
			return true;
		if (_GetPaths(root->_left, node, s))
			return true;
		if (_GetPaths(root->_right, node, s))
			return true;
		s.pop();
		return false;
	}
  Node* GetLastestAncetor(Node* x1, Node* x2)
	{
		if (_root == NULL)
			return NULL;
		stack<Node*> s1, s2;
		if (!_GetPaths(_root, x1, s1) || !_GetPaths(_root, x2, s2))
		{
			return NULL;
		}
		//找到了
		while (s1.size() != s2.size())
		{
			if (s1.size() > s2.size())
				s1.pop();
			else
				s2.pop();
		}
		while (!s1.empty()&&!s2.empty()&&s1.top() != s2.top())
		{
			s1.pop();
			s2.pop();
		}
		return s1.top();
	}
