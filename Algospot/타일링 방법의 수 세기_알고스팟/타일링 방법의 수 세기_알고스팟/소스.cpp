//https://algospot.com/judge/problem/read/TILING2
#include <iostream>
#include <memory.h>
using namespace std;

const long long MOD = 1000000007;
int cache[2][100];
int N = 0;


// ㅁ			ㅁㅁ
// ㅁ  이거거나  ㅁㅁ  이렇게내 
int solution(int y, int x)
{
	if (cache[y][x] != 0) {
		return cache[y][x]%MOD;
	}


	if (x + 1 < N)
		cache[y][x] += solution(y, x + 1);
	else
		return cache[y][x] += 1;



	if (x + 2 < N)
		cache[y][x] += solution(y, x + 2);
	else
		return cache[y][x] += 1;


	return cache[y][x]%MOD;
}
int main()
{
	int C = 0; cin >> C;

	while (C--)
	{
		cin >> N;
		memset(cache, 0, sizeof(cache));
		cout << solution(0, 0) << endl;
	}
}


//색칠하고 다음스텝으로 넘어가는 거 잘못되었음
//안칠해지는 경우는 없다.


//책의 정답
int memo[101];
int tiling(int width)
{
	if (width <= 1) return 1;
	int& ret = memo[width];
	if (ret != -1)return ret;
	return ret = (tiling(width - 2) + tiling(width - 1)) % MOD;
}