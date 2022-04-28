#include <iostream>

using namespace std;

const long long MOD = 1000000007;
int board[2][100];
int cache[2][100];
int N = 0;

const int dy[] = { 1,0 };
const int dx[] = { 0,1 };
int solution(int y, int x)
{
	if (cache[y][x] != 0) {
		return cache[y][x];
	}

	bool flag = true;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < N; ++j) {
			if (board[i][j] == 0) {
				flag = false;
				break;
			}
		}

	if (flag == true)
		return cache[y][x] = 1;

	for (int i = 0; i < 2; ++i) {
		if (y + dy[i] > 1 || x + dx[i] >= N)continue;
		board[y][x] = 1;  //지나간 곳 표시
		board[y + dy[i]][x + dx[i]] = 1;
		cache[y][x] += solution(y + dy[i], x + dx[i]);
		board[y][x] = 0;
		board[y + dy[i]][x + dx[i]] = 0;
	}
	return cache[y][x];
}
int main()
{
	int C = 0; cin >> C;

	while (C--)
	{
		cin >> N;
		memset(cache, 0, sizeof(cache));
		memset(board, 0, sizeof(board));
		cout << solution(0, 0) << endl;
	}
}


//색칠하고 다음스텝으로 넘어가는 거 잘못되었음
//안칠해지는 경우는 없다.