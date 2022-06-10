/*
https://algospot.com/judge/problem/read/POLY
*/

#include <iostream>

using namespace std;

constexpr int MOD = 10000000;
int cache[101][101];//n개의 사각형일 때의 세로 단조 폴리오미노의 개수


int sol(int n, int first)
{
	if (n == first)return 1;
	if (cache[n][first] != 0)
		return cache[n][first];
	for (int i = 1; i <= n-first; ++i)
	{
		int ret = i + first - 1;
		ret *= sol(n - first, i);
		ret %= MOD;
		cache[n][first] += ret;
		cache[n][first] %= MOD;	

	}
	return cache[n][first];
}

int main()
{
	int C = 0; cin >> C;

	while (C--)
	{
		//memset(cache, 0, sizeof(cache));
		int n = 0; cin >> n;

		int ret = 0;
		for(int i=1;i<=n;++i){
			ret += sol(n, i);
			ret %= MOD;
		}
		cout << ret << endl;

	}
}