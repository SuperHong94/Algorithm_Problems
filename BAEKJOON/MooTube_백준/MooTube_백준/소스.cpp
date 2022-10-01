//https://www.acmicpc.net/status?user_id=tnswh213&problem_id=15591&from_mine=1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> graph[5001];

constexpr int INF = 2147483647;
int N, Q;
int BFS(int start, int K)
{
	int ret = 0;
	queue<pair<int, int>> q;
	vector<bool> visit(N + 1, false);
	visit[start] = true;

	for (const auto& Node : graph[start])
	{
		visit[Node.first] = true;
		q.push({ Node.first, Node.second });
	}
	while (!q.empty())
	{
		auto node = q.front(); q.pop();
		int cur = node.first;
		int curw = node.second;

		if (curw >= K) {
			ret++;
			for (const auto& nextNode : graph[cur])
			{
				int next = nextNode.first, nextWeight = nextNode.second;
				if (visit[next] == true)continue;
				visit[next] = true;
				q.push({ next,min(curw,nextWeight) });

			}
		}

	}
	return ret;
}


int main()
{
	N = 0, Q = 0; cin >> N >> Q;
	{
		int a = 0, b = 0, r = 0;
		for (int i = 0; i < N - 1; ++i) {
			cin >> a >> b >> r;
			graph[a].emplace_back(b, r);
			graph[b].emplace_back(a, r);
		}
		for (int i = 0; i < Q; ++i)
		{
			cin >> a >> b;
			cout << BFS(b, a) << '\n';
		}
	}
}