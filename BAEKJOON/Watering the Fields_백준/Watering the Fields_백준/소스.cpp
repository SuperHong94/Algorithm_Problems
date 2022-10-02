//https://www.acmicpc.net/problem/10021
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
constexpr int inf = 99'999'999;
int dis(const pair<int, int>& p1, const pair<int, int>& p2)
{
	int X = p1.first - p2.first;
	X = X * X;
	int Y = p1.second - p2.second;
	Y = Y * Y;
	return X + Y;
}
int main()
{

	int N = 0, C = 0; cin >> N >> C;
	vector<vector<pair<int, int>>> graph(N);
	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i].first >> v[i].second;
	}

	int ret = 0;

	for (int i = 0; i < v.size(); ++i) {
		for (int j = i+1; j < v.size(); ++j) {
			int d = dis(v[i], v[j]);
			if (d < C)continue;
			graph[i].push_back({ j,d });
			graph[j].push_back({ i,d });
		}
	}

	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	vector<int> parents(N, -1);
	int start = 0;
	pq.push({ 0,start });
	while (!pq.empty())
	{
		auto Node = pq.top(); pq.pop();
		int weight = Node.first, cur = Node.second;
		if (parents[cur] == start)continue; //이미 최소값있음
		parents[cur] = start;
		ret += weight;
		for (const auto& nextNode : graph[cur]) {
			int nextIndex = nextNode.first, nextWeight = nextNode.second;
			if (parents[nextIndex] == parents[cur]) continue; //싸이클임
		
			pq.push({ nextWeight,nextIndex });

		}

	}

	for (int p : parents) {
		if (p == -1) {
			cout << -1;
			return 0;
		}
	}

	cout << ret;

}