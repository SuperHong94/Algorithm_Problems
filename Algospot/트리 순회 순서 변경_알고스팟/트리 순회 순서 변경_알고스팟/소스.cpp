//https://algospot.com/judge/problem/read/TRAVERSAL
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Node
{
	int val;
	Node* left;
	Node* right;
public:
	Node(int n) :val(n) { left = nullptr; right = nullptr; }

	void insert(int n)
	{
		if (n < val)
		{
			if (left == nullptr)
				left = new Node(n);
			else
				left->insert(n);
		}
		else {
			if (right == nullptr)
				right = new Node(n);
			else
				right->insert(n);
		}
	}

	void postOrder()
	{
		if (left != nullptr)
			left->postOrder();
		if (right != nullptr)
			right->postOrder();
		cout << val << ' ';
	}

};


vector<int> Slice(const vector<int>& v, int a, int b)
{
	return vector<int>(v.begin() + a, v.begin() + b);
}
void postOrder(const vector<int>& pre, const vector<int>& mid)
{
	int n = pre.size();
	if (n == 0)
		return;
	int root = pre[0];
	int m = find(mid.begin(), mid.end(), root)-mid.begin();
	postOrder(Slice(pre, 1, m+1),Slice(mid,0,m));
	postOrder(Slice(pre, m + 1, n), Slice(mid, m + 1, n));
	cout << root << ' ';

}
int main()
{
	int T = 0; cin >> T;
	while (T--)
	{
		int n = 0; cin >> n;
		vector<int> preOrder;
		vector<int> midOrder;
		int a = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> a;
			preOrder.push_back(a);
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> a;
			midOrder.push_back(a);
		}
		postOrder(preOrder, midOrder);
		cout << '\n';

	}
}