//BJ_11725_parentsOfTree
#include <iostream>
#include <vector>

const int MAX = 100000 + 1;
using namespace std;

int N = 0;
vector<int> v[MAX];
bool vist[MAX] = { false, };
int ans[MAX];


void DFS(int start)
{
	vist[start] = true;
	for (int i = 0; i < v[start].size(); i++)
	{
		int node = v[start][i];
		if (!vist[node])
		{
			ans[node] = start;
			DFS(node);
		}
	}
}

int main()
{
	cin >> N;
	int a = 0;
	int b = 0;

	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}



	DFS(1);
	for (int i = 2; i <= N; i++)
		cout << ans[i] << '\n';

}