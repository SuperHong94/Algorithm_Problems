#include <iostream>
#include <vector>
using namespace std;

int N = 0;
int M = 0;


vector<int> trees;

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		int a = 0;
		cin >> a;
		trees.push_back(a);
	}
	int res = 0;
	for (int i =1;; ++i) {
		int remain = M;
		for (auto d : trees)
		{
			if (d > i) {
				remain = remain - (d - i);
			}
			if (remain <= 0)
				break;
		}
		if (remain >0) {
			res = i-1;
			break;
		}
	}
	cout << res;
}