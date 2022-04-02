#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>

constexpr int MAX = 20001;
constexpr int INF = 9999999;
using namespace std;

vector <pair<int, int>> graph[MAX];
int d[MAX];
int V, E, K;

void dijkstra(int start)
{
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int dis = -pq.top().first;
		pq.pop();
		if (d[cur] < dis)continue;
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int nextDistance = dis + graph[cur][i].second;
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push({ -nextDistance,next });
			}
		}
	}
}
int main()
{
	cin >> V >> E;
	cin >> K;
	int u = 0, v = 0, w = 0;
	for (int i = 0; i < MAX; ++i)
		d[i] = INF;
	for (int i = 0; i < E; ++i)
	{
		cin >> u >> v >> w;
		graph[u].emplace_back(v, w);
	}

	dijkstra(K);
	for (int i = 1; i <= V; i++)
		if (d[i] == INF)
			cout << "INF\n";
		else
			cout << d[i] << '\n';
}

