#include <iostream>

using namespace std;


int Board[101][101];
int cache[101][101];
const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };
int Y = 0, X = 0;

int DFS(int y, int x)
{
	if (cache[y][x] != -1)
		return 0;
	cache[y][x] = 0; //갔던곳 못감 ㅎㅎ
	if (Board[y][x] == -1)
		return 0;
	if (Board[y][x] == 1 || Board[y][x] == 2) {
		Board[y][x] = 2;
		return 1;
	}

	for (int i = 0; i < 4; ++i)
	{
		DFS(dy[i] + y, dx[i] + x);

	}

}

int GetCheaseCnt()
{
	int ret = 0;
	for (int i = 1; i <= Y; ++i)
		for (int j = 1; j <= X; ++j) {
			if (Board[i][j] == 1)
				ret++;
		}
	return ret;
}
int solution()
{
	memset(cache, -1, sizeof(cache));

	int cnt = 0;
	int cheaseCnt = GetCheaseCnt();
	while (0 != cheaseCnt)
	{
		DFS(1, 1);
		cnt += 1;
	}

	return cnt;

}
int main()
{
	memset(Board, -1, sizeof(Board)); //맨 가생이는 -1로 할꺼임
	cin >> Y >> X;

	for (int i = 1; i <= Y; ++i)
		for (int j = 1; j <= X; ++j)
			cin >> Board[i][j];

	solution();

}