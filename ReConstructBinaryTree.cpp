Node* ReConstructBinaryTree(vector<int>& prev, vector<int>& in)
{
	//assert(prev.size() == in.size());
	if (prev.empty() || in.empty())
		return NULL;
	Node* Head = new Node(prev.front());
	vector<int>::iterator It;
	for (It = in.begin(); It != in.end(); ++It)
	{
		if (*It == prev.front())
			break;
	}
	int lsize = It - in.begin();//左数节点个数
	int rsize = in.size() - 1 - lsize;//右数节点个数
	vector<int> lprev(prev.begin() + 1, prev.begin() + 1 + lsize);
	vector<int> rprev(prev.begin() + 1 + lsize, prev.end());
	vector<int> lin(in.begin(), in.begin() + lsize);
	vector<int> rin(in.begin() + lsize+1, in.end());
	Head->_left = ReConstructBinaryTree(lprev, lin);
	Head->_right = ReConstructBinaryTree(rprev, rin);
	return Head;
}
int main()
{
	vector<int> v1 = { 5, 1, 3, 4, 2, 6 };
	vector<int> v2 = { 3, 1, 4, 5, 6, 2 };
	Node* ret=ReConstructBinaryTree(v1, v2);
	return 0;
}
