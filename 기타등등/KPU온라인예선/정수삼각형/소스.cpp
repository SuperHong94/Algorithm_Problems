#include <iostream>
using namespace std;


int Value[501][501];
int N = 0;
int memo[501][501];

int solution(int y,int x)
{
	if (Value[y][x] == 0)
		return 0;
	if (memo[y][x] == 0)
	{
		memo[y][x] = Value[y][x] + max(solution(y + 1, x), solution(y + 1, x + 1));
		return memo[y][x];
	}
	return memo[y][x];
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			cin >> Value[i][j];
		}
	}

	cout << solution(0, 0);


}