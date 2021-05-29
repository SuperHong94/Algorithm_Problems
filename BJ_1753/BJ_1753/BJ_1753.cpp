#include <iostream>
#include <queue>
using namespace std;

constexpr int INF = 9999999;
constexpr int MAX = 20001;
int V, E, K;

struct LINE
{
	int target;
	int weight;
};
struct cmp
{
	bool operator()(LINE& a, LINE& b)
	{
		return a.weight > b.weight;
	}
};

vector<LINE> graph[MAX];
int d[MAX];

void Find(int start);
int main()
{
	for (int i = 0; i < MAX; ++i)
		d[i] = INF;
	int u = 0, v = 0, w = 0;
	cin >> V >> E >> K;

	for (int i = 0; i < E; ++i) {
		cin >> u >> v >> w;
		LINE tmp = { v,w };
		graph[u].emplace_back(tmp);
	}
	int value = 0;


	Find(K);
	for (int i = 1; i <= V; ++i) {
	
		if (MAX == d[i])
			cout << "INF\n";
		else
			cout << d[i]<< '\n';
	
	}

}
void Find(int start)
{
	d[start] = 0;
	priority_queue<LINE, vector<LINE>, cmp> pq;
	pq.push({ start, 0 });

	while (!pq.empty())
	{
		int cur = pq.top().target;
		int dis = pq.top().weight;
		pq.pop();
		if (d[cur] < dis) continue;

		for (int i = 0; i < graph[cur].size(); ++i)
		{
			int next = graph[cur][i].target;
			int nextdis= dis+graph[cur][i].weight;
			if (d[next] > nextdis) {
				d[next] = nextdis;
				pq.push({ next,nextdis });
			}
		}
	}

}