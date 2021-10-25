//쿼드 트리 뒤집기
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class QUADTREE
{
public:
	char c;
	QUADTREE* tree;

	QUADTREE()
	{
		c = -1;
		tree = nullptr;
	}
	QUADTREE(char ch)
	{
		c = ch;
		tree = new QUADTREE[4];
	}
	bool Insert(char c)
	{
		QUADTREE newTree = QUADTREE(c);
		for (int i = 0; i < 4; ++i) {
			if (tree[i].c == -1) {
				tree[i] = newTree;
				return true;
			}
			else if (tree[i].c == 'x') {
				if (tree[i].Insert(c))
					return true;
			}

		}
		return false;
	}

	void init()
	{
		for (int i = 0; i == 4; ++i) {
			tree[i].init();
		}
		if (tree != nullptr)
			delete[] tree;
	}
	void SWAP()
	{
		if (c == -1)
			return;
		for (int i = 0; i < 4; ++i)
		{
			if (tree[i].c == 'x')
				tree[i].SWAP();
		}
		//tree[0].SWAP();
		QUADTREE tmp = tree[0];
		tree[0] = tree[2];
		tree[2] = tmp;
		tmp = tree[1];
		tree[1] = tree[3];
		tree[3] = tmp;



	}
	bool show()
	{
		if (c == -1)
			return false;
		cout << c << ' ';
		for (int i = 0; i < 4; ++i) {
			if (tree[i].show() == false)
				break;
		}
		return  true;
	}
	bool show(string& s)
	{
		if (c == -1)
			return false;
		s += c;
		for (int i = 0; i < 4; ++i) {
			if (tree[i].show(s) == false)
				break;
		}
		return  true;
	}
};


void SWAP(char& a, char& b)
{
	char tmp = a;
	a = b;
	b = tmp;
}
string solution(string s)
{
	string reslut;
	if (s.size() == 1)
		return s;

	QUADTREE root(s[0]);

	for (int i = 1; i < s.size(); ++i)//쪼개기
	{
		root.Insert(s[i]);
	}
	//root.show();
	root.SWAP();
	//cout << endl;
	root.show(reslut);

	root.init();
	//cout << endl;
	//while (true);
	return reslut;
}
int main()
{
	int C = 0; cin >> C;
	for (int i = 0; i < C; ++i)
	{
		string s;
		cin >> s;
		cout << solution(s) << endl;
		//cout << s << endl;
	}
}