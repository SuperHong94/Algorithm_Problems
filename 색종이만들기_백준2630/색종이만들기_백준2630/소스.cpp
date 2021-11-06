#include <iostream>
using namespace std;

int BOARD[128][128];

int b_cnt = 0;
int w_cnt = 0;

bool isFull(int i, int j, int n)
{
	char c = BOARD[i][j];
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			if (BOARD[i + y][j + x] != c)
				return false;
		}
	}
	c == 0 ? w_cnt += 1 : b_cnt += 1;

	return true;

}
void CUT(int y, int x, int n)
{
	if (isFull(y, x, n))
		return;

	//ÁÂ»ó
	CUT(y, x, n / 2);
	//¿ì»ó
	CUT(y, x + n / 2, n / 2);

	//ÁÂÇÏ
	CUT(y + n / 2, x, n / 2);

	//¿ìÇÏ
	CUT(y + n / 2, x + n / 2, n / 2);
}

int main()
{
	int N = 0; cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			cin >> BOARD[i][j];
	}

	CUT(0, 0, N);

	cout << w_cnt << '\n' << b_cnt;
}