#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
int dis[50001];
int BFS(int n, int start, const vector<vector<int>>& paths, const vector<int>& summits, int& top)
{

	for (int i = 0; i < n; ++i)
	{
		dis[i] = 990000001;
	}
	dis[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	while (false == pq.empty())
	{
		auto node = pq.top(); pq.pop();
		int distance = node.first;
		int id = node.second;
		for (int i = 0; i < paths.size(); ++i)
		{

			if (paths[i][0] == id) {
				int nextIndex = paths[i][1];
				int weight = paths[i][2];
				if (distance + weight < dis[nextIndex]) {
					dis[nextIndex] = distance + weight;
					pq.push({ distance + weight, nextIndex });
				}
			}

		}
	}
	int minValue = dis[summits[0]];
	top = summits[0];
	for (int d : summits)
	{
		if (minValue > dis[d])
		{
			minValue = dis[d];
			top = d;
		}
	}
	return minValue;

}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
	vector<int> answer;
	answer.resize(2);
	int minValue = 999999999;
	int index = 0;
	sort(summits.begin(), summits.end());
	for (int start : gates)
	{

		int ret = BFS(n, start, paths, summits, index);
		if (minValue > ret)
		{
			answer[0] = index;
			answer[1] = ret;
		}
		else if (minValue == ret && index < answer[0])
		{
			answer[0] = index;
		}
	}
	return answer;
}


int main()
{
	auto v = solution(6, { {1, 2, 3}, {2, 3, 5}, {2, 4, 2}, {2, 5, 4}, {3, 4, 4}, {4, 5, 3}, {4, 6, 1}, {5, 6, 1} }, { 1, 3 }, { 5 });

	cout << v[0] << ' ' << v[1];
}