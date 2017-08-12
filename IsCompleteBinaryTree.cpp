bool IsComplete()//判断是否平衡 把所有节点都入栈，出的时候查看左右子树是否存在，
		//若是不存在那么以后的所有节点不应该存在 子树。
	{
		bool flag = false;
		if (_root == NULL)
			return true;
		queue<Node*> q;
		q.push(_root);
		while (!q.empty())
		{
			Node*temp = q.front();
			if (temp->_left)
			{
				if (flag == true)
					return false;
				q.push(temp->_left);
			}
			else
				flag = true;//如果没有左孩子，标志位置为真
			if (temp->_right)
			{
				if (flag == true)
					return false;
				q.push(temp->_right);
			}
			else
				flag = true;
			q.pop();
		}
		return true;
	}
