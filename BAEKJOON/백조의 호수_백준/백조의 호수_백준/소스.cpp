/*
https://www.acmicpc.net/problem/3197
*/
#include <iostream>
#include <memory.h>
using namespace std;


constexpr char ICE = 'X';
constexpr char WATER = '.';
constexpr char L = 'L';



char Map[1500][1500];
bool vist[1500][1500];
int R, C;


int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int tx[2], ty[2];
int  DFS(int x, int y)
{
	if (x < 0 || x >= C || y < 0 || y >= R)
		return 0;
	if (vist[y][x] == true)
		return 0;
	vist[y][x] = true;

	if (ICE == Map[y][x])
		return 0;

	//if (find == true)
		if (x == tx[1] && y == ty[1])
			return 1;

	int ret = 0;
	for (int i = 0; i < 4; ++i)
	{
		int nX = x + dx[i], nY = y + dy[i];
		ret += DFS(nX, nY);
	}
	return ret;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C;
	int X = 0, Y = 0;
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j) {
			cin >> Map[i][j];
			if (L == Map[i][j]) {
				tx[X++] = j;
				ty[Y++] = i;
				Map[i][j] = WATER;
			}

		}


	int day = 0;
	while (0 == DFS(tx[0], ty[0])) {
		day++;

		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j)
				if (WATER == Map[i][j])
					DFS(j, i);

		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j)
				if (true == vist[i][j])
					Map[i][j] = WATER;
		memset(vist, 0, sizeof(vist));
	}

	cout << day;
}


//DFS 시간초과 뜨네
