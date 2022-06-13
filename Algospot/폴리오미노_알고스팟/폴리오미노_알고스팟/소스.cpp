/*
https://algospot.com/judge/problem/read/POLY
풀이

세로 단조이므로 가로줄은 중간에 빈칸 없이 일렬로 있다.
첫줄에 i개에 사각형이 있으면
나머지디 n-i개의 사각형으로 폴리오미노를 만들고 첫줄에 적절히 붙이면 된다. 
ex)
i=2, n=4
ㅁㅁ

ㅁㅁㅁ
ㅁ  

이렇게 있으면
ㅁㅁ
ㅁㅁㅁ
ㅁ

  ㅁㅁ
ㅁㅁㅁ
ㅁ

    ㅁㅁ
ㅁㅁㅁ
ㅁ

ㅁㅁ
  ㅁㅁㅁ
  ㅁ


이렇게 모형이 올 수 있다.
그 경우의 수는 첫줄+두번째줄의 사각형 수 -1 이다.

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