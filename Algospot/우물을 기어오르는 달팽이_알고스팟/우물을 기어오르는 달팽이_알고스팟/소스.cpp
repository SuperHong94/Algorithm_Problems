#include <iostream>	

using namespace std;

/*
* https://algospot.com/judge/problem/read/SNAIL
* 깊이가 n인 우물 맨밑에 달팽이가 있다.
* 비가내리면 달팽이는 하루에 2m 올라간다.
* 날이 맑으면 1m 올라간다.
* 
* m일간 각 일마다 비올확률은 75% m일안에 달팽이가 우물끝까지 올라갈 확률을 계산하는 프록램
*/

constexpr float SUCESS = 0.75f;
constexpr float FAIL = 0.35f;
int N = 0, M = 0;
float  solution(int n,int m)
{
	if (n == 0)
		return 1.0f;
	if (m == 0)
		return 1.0f;
}
int main()
{
	int C = 0; cin >> C;
	while (C--)
	{
		cin >> N >> M;
	}

}