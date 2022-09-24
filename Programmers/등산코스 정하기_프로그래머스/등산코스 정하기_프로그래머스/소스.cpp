#include <string>
#include <vector>
#include <queue>
#include <memory.h>
#include <iostream>
#include <algorithm>
using namespace std;
int dis[50001];
bool Ends[50001];


int BFS(int n, int start, const vector<vector<int>>& paths, const vector<int>& summits, int& top)
{

	for (int i = 0; i < n; ++i)
	{
		dis[i] = 990000001;
	}

	dis[start] = 0;
	queue<pair<int, int>> q;
	q.push({ 0, start });
	while (false == q.empty())
	{
		auto node = q.front(); q.pop();
		int parent = node.first;
		int id = node.second;
		if (Ends[id] == true)continue;
		for (int i = 0; i < paths.size(); ++i)
		{

			if (paths[i][0] == id && paths[i][1] != parent) {
				int nextIndex = paths[i][1];
				int weight = paths[i][2];
				int nextValue = max(weight, dis[id]);
				dis[nextIndex] = min(dis[nextIndex], nextValue);
				q.push({ id, nextIndex });
			}
			else if ((paths[i][1] == id && paths[i][0] != parent))
			{
				int nextIndex = paths[i][0];
				int weight = paths[i][2];
				int nextValue = max(weight, dis[id]);
				dis[nextIndex] = min(dis[nextIndex], nextValue);
				q.push({ id, nextIndex });
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


	memset(Ends, false, sizeof(Ends));
	for (int i : summits)
	{
		Ends[i] = true;
	}
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
	auto v = solution(7 ,{ {1, 4, 4}, { 1, 6, 1 }, { 1, 7, 3 }, { 2, 5, 2 }, { 3, 7, 4 }, { 5, 6, 6 }} ,{1}, {2, 3, 4});

	cout << v[0] << ' ' << v[1];
}