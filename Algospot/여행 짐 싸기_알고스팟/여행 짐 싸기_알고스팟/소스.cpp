//백준 평범한 배낭부터 다시 도전해본다.
//https://www.acmicpc.net/problem/12865

#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int N = 0, K = 0;

vector<pair<int, int>> objects;
bool visit[100];
int cache[101][100001];
int sol(int index,int weight)
{
	if (weight > K)
		return 0;
	int& ret = cache[index][weight];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int i = 0; i < objects.size(); ++i)
	{
		if (visit[i] == true)continue;
		int w = objects[i].first+weight;
		if (w > K)
			continue;
		int v = objects[i].second;
		visit[i] = true;
		ret = max(ret, sol(i,w)+v);
		visit[i] = false;
	}

	return ret;


}
int main()
{
	cin >> N >> K;
	int n = N;
	memset(cache, -1, sizeof(cache));
	while (n--)
	{
		int w = 0, v = 0; cin >> w >> v;
		objects.emplace_back( w,v );

	}
	cout << sol(0,0) << endl;
}