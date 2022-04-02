#include <iostream>
#include <bitset>
using namespace std;


short BOARD[2187][2187];
int zeroCnt = 0;
int plusCnt = 0;
int minusCnt = 0;

bool isFull(int y, int x, int n	)
{

	char c = BOARD[y][x];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
		{
			if (BOARD[y + i][x + j] != c)
				return false;
		}
	}
	switch (c)
	{
	case 0:
		zeroCnt += 1;
		break;
	case 1:
		plusCnt += 1;
		break;
	case -1:
		minusCnt += 1;
		break;

	}
	return true;

}

void solve(int y,int x, int n)
{
	if(isFull(y,x,n))
		return;

	solve(y, x, n / 3); solve(y, x + n / 3, n / 3); solve(y, x + (2 * (n / 3)), n / 3);

	solve(y + n / 3, x, n / 3); solve(y + n / 3, x + n / 3, n / 3); solve(y + n / 3, x + (2 * (n / 3)), n / 3);

	solve(y + (2 * (n / 3)), x, n / 3); solve(y + (2 * (n / 3)), x + n / 3, n / 3); solve(y + (2 * (n / 3)), x + (2 * (n / 3)), n / 3);
	return;

}

int main()
{
	int N = 0; cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			cin >> BOARD[i][j];
	}
	solve(0, 0, N);
	cout << minusCnt << '\n' << zeroCnt << '\n' << plusCnt;

}