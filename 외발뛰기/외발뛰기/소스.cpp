#include<iostream>
#include <memory.h>
using namespace std;


int board[100][100];
int memo[100][100];
int N;

int solve(int y, int x)
{
	if (y >= N || x >= N)
		return 1;
	if (y == N - 1 && x == N - 1) {
		memo[y][x] = 2;
		return memo[y][x];
	}
	if (memo[y][x] != 0)
		return memo[y][x];
	int value = board[y][x];
	int down = solve(y + value, x);
	int right = solve(y, x + value);
	if (down == 2 || right == 2)
		memo[y][x] = 2;
	else
		memo[y][x] = 1;
	return memo[y][x];
}

int solve2(int y, int x)
{
	if (y >= N || x >= N) return 0;
	if (y == N - 1 && x == N - 1) return 1;

	int& ret = memo[y][x];
	if (ret != -1)return ret; //memo의 초기값은 -1
	int value = board[y][x];

	return ret = (solve2(y + value, x) || solve2(y, x + value));
}

int main()
{
	int C = 0; cin >> C;
	for (int c = 0; c < C; ++c) {
		memset(memo, -1, sizeof(memo));
		cin >> N;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				cin >> board[i][j];
		if (solve2(0, 0) == 1)
			cout << "YES\n";
		else
			cout << "NO\n";

	}
}

