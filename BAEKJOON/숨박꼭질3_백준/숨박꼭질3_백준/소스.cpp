//https://www.acmicpc.net/problem/13549

#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
const int INF = 100001;
int N, K;
int cache[100001];
int sol(int x, int depth)
{
	queue<int> q;
	q.push(x);
	cache[x] = 0;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		if (cur == K)
			continue;

		for (int next : {cur - 1, cur + 1, cur * 2})
		{
			if (next < 0 || next>100000||cache[next]<=cache[cur]+1)
				continue;
			q.push(next);
			if(next== cur *2)
				cache[next] = cache[cur];
			else
				cache[next] = cache[cur] + 1;
		}
	}


	return cache[K];

}


int main()
{
	cin >> N >> K;
	fill(cache, cache + 100001, 100001);
	cout << sol(N, 0);



}