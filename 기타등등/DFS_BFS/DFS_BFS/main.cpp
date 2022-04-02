//น้มุ 1260
#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

bool vertex[1001][1001];

int N = 0;

int M = 0;
int V = 0;
bool flag[1001];
void BFS(int start)
{
	int s = start;
	flag[s] = true;
	queue<int> search;
	search.push(s);
	while (!search.empty()) {
		s = search.front();
		cout << s << ' ';
		search.pop();
		for (int i = 1; i <= N; ++i) {
			if (vertex[s][i] == true) {
				if (flag[i] == false) {
					search.push(i);
					flag[i] = true;
				}
			}
		}
	}
}
void DFS(int start)
{

	int s = start;
	cout << start << ' ';
	flag[s] = true;
	for (int i = 1; i <= N; ++i) {
		if (vertex[s][i] == true && flag[i] == false) {
			DFS(i);
		}
	}

}
int main()
{

	cin >> N;

	cin >> M;
	cin >> V;
	for (int i = 0; i < M; ++i) {
		int a = 0, b = 0;
		cin >> a >> b;
		vertex[a][b] = true;
		vertex[b][a] = true;
	}
	DFS(V);
	cout << endl;
	memset(flag, false, sizeof(flag));
	BFS(V);
}