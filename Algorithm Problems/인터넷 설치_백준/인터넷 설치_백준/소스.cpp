#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
using node = pair<int, int>;
/*
문제의 포인트
N번에 가는길에 비싼 비용이 따르더라도
K번만큼 공짜로 빼주니깐 무시해도된다.

이것을 어떻게 고려할 것인가?

x비용 이하로 n번과 연결할 수 있는지를 체크한다.


*/
int dis[1001];
vector<vector<pair<int, int>>> path(1001);
int N = 0, P = 0, K = 0;
bool sol(int x)
{
	priority_queue < node, vector<node>, greater<node>> pq;
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0;
	pq.push({ 0, 1 });
	while (!pq.empty())
	{
		int cur = pq.top().second;
		int curWeight = pq.top().first;
		pq.pop();
		if (dis[cur] < curWeight)continue;
		for (const auto& next : path[cur])
		{
			int nextIndex = next.first;
			int nextWeight = curWeight+(next.second>x);
			if (nextWeight < dis[nextIndex]) {
				dis[nextIndex] = nextWeight;
				pq.push({nextWeight, nextIndex});
			}

		}
	}

	return dis[N] <= K;
}

int main()
{

	cin >> N >> P >> K;

	vector<int>weights;

	int l = 0, r = 0;
	for (int i = 0; i < P; ++i)
	{
		int a = 0, b = 0, w = 0;
		cin >> a >> b >> w;
		path[a].push_back({ b, w });
		path[b].push_back({ a, w });
		r = max(r, w);
	}
	int ret = -1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (sol(mid) == true)
		{
			ret = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ret << '\n';
}