#include <iostream>	
#include <memory.h>
using namespace std;

/*
* https://algospot.com/judge/problem/read/SNAIL
* 깊이가 n인 우물 맨밑에 달팽이가 있다.
* 비가내리면 달팽이는 하루에 2m 올라간다.
* 날이 맑으면 1m 올라간다.
* 
* m일간 각 일마다 비올확률은 75% m일안에 달팽이가 우물끝까지 올라갈 확률을 계산하는 프록램
* 13분 12초
* 0.75 0.75 0.75 
*/

constexpr float SUCESS = 0.75f;
constexpr float FAIL = 0.35f;
int N = 0, M = 0;
double cache[1001][1001 * 2];

double  solution(int d,int dis)
{
	if (d == M)
		return dis >=N? 1.0f : 0.0f;
	if (cache[d][dis] != -1.0f)
		return cache[d][dis];
	return cache[d][dis]=(0.75f * solution(d +1, dis + 2) + 0.25f * solution(d + 1, dis + 1));
}
int main()
{
	int C = 0; cin >> C;
	while (C--)
	{
		cin >> N >> M;
		for (int i = 0; i < 1001; ++i)
			for (int j = 0; j < 1001*2; ++j)
				cache[i][j] = -1.0f;

		printf("%.10lf\n", solution(0, 0));
	}

}