#include <string>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
bool Ends[50001];
int dis[50001];
vector<pair<int,int>> newPaths[50001];
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
	vector<int> answer;
	for (int i = 1; i <= n; ++i) {
		dis[i] = 90000001;
	}
	for (int i : summits) {
		Ends[i] = true;
	}
	queue<int>q;
	for (int i : gates) {
		q.push(i);
		dis[i] = 0;
	}
	for (int i = 0; i < paths.size(); ++i)
	{
		int t0 = paths[i][0], t1 = paths[i][1], w = paths[i][2];
		newPaths[t0].emplace_back(t1, w);
		newPaths[t1].emplace_back(t0, w);
	}


	while (!q.empty())
	{
		int place = q.front(); q.pop();
		if (Ends[place] == true)
			continue;
	
		for (int i = 0; i < newPaths[place].size(); ++i)
		{
			int  w = newPaths[place][i].second;
			int other = newPaths[place][i].first;
			if (dis[other] > max(dis[place],w)) {
				dis[other] = max(dis[place], w);
				q.push(other);
			}
		}
	}

	sort(summits.begin(), summits.end());
	int minindex = -1, minValue = 90000001;

	for (int i : summits)
	{
		if (minValue > dis[i]) {
			minindex = i;
			minValue = dis[i];
		}
	}


	return { minindex,minValue };
}

int main()
{
	auto v = solution(7, { {1, 4, 4}, { 1, 6, 1 }, { 1, 7, 3 }, { 2, 5, 2 }, { 3, 7, 4 }, { 5, 6, 6 } }, { 1 }, { 2, 3, 4 });

	cout << v[0] << ' ' << v[1];
}