//몸풀기용 다익스트라 연습
//https://www.acmicpc.net/problem/1238

#include <iostream>
#include <queue>
using namespace std;
constexpr int INF = 100001;
int Map[1001][1001];



int N, M;

int Xdis[10001];
int dijkstra(int start, int target)
{
	int dis[1001] = { 0, };
	for (int i = 1; i <= N; ++i)
		dis[i] = INF;

	priority_queue < pair<int, int>, vector < pair<int, int>>, greater<pair<int, int>>> q;
	dis[start] = 0;
	q.push({ 0,start });

	while (q.empty() == false)
	{
		auto node = q.top(); q.pop();
		int nodeIdx = node.second, nodeValue = node.first;
		if (nodeValue > dis[nodeIdx])continue;
		for (int i = 1; i <= N; ++i) {
			if (i == nodeIdx || Map[nodeIdx][i] == 0)continue;
			int newValue = Map[nodeIdx][i] + nodeValue;
			if (dis[i] > newValue) {
				dis[i] = newValue;
				q.push({ newValue,i });
			}
		}
	}
	return dis[target] + Xdis[start];
}

void Xdijkstra(int start, int target)
{
	

	priority_queue < pair<int, int>, vector < pair<int, int>>, greater<pair<int, int>>> q;
	Xdis[start] = 0;
	q.push({ 0,start });

	while (q.empty() == false)
	{
		auto node = q.top(); q.pop();
		int nodeIdx = node.second, nodeValue = node.first;
		if (nodeValue > Xdis[nodeIdx])continue;
		for (int i = 1; i <= N; ++i) {
			if (i == nodeIdx || Map[nodeIdx][i] == 0)continue;
			int newValue = Map[nodeIdx][i] + nodeValue;
			if (Xdis[i] > newValue) {
				Xdis[i] = newValue;
				q.push({ newValue,i });
			}
		}
	}
}
int main()
{
	int X = 0;
	cin >> N >> M >> X;

	for (int i = 0; i < M; ++i)
	{
		int a = 0, b = 0, c = 0; cin >> a >> b >> c;
		Map[a][b] = c;
	}
	for (int i = 1; i <= N; ++i)
		Xdis[i] = INF;

	Xdijkstra(X, N);
	int MAX = 0;
	for (int i = 1; i <= N; ++i)
	{
		MAX = max(MAX, dijkstra(i, X));
	}
	cout << MAX;
}
