//https://www.acmicpc.net/problem/2933
#include <iostream>
#include <memory.h>
using namespace std;

//��� ä�� �������� �Ѵ�.

int R, C, N;
char cave[100][100];
bool visit[100][100];

int sticks[100];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };


void DFS(int y, int x)
{
	visit[y][x] = true;
	for (int i = 0; i < 4; ++i)
	{
		if (y < 0 || x < 0 || y == R || x == C)continue;
		int nextY = y + dy[i];
		int nextX = x + dx[i];

		if (cave[nextY][nextX] == 'x'&&visit[nextY][nextX]==false)
			DFS(nextY, nextX);
	}
}

void Update()
{
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < C; ++i)
	{
		if (cave[R - 1][i] == 'x')
			DFS(R - 1, i);
	}
	int topY = R-1, bottomY = 0;

	for (int i = 0; i < C; ++i)
	{
		for (int j = 0; j < R; ++j) {
			if (cave[i][j] == 'x' && visit[i][j] == false)
			{
				topY = min(topY, i);
				bottomY = max(bottomY, i);
			}
		}
	}


}

void Crash(int h, bool isRight)
{
	if (true == isRight)
	{
		for (int i = C - 1; i >= 0; --i)
		{
			if (cave[h][i] == 'x')
			{
				cave[h][i] = '.';
				Update();
				return;
			}
		}
	}
	else {
		for (int i = 0; i < C; ++i)
		{
			if (cave[h][i] == 'x')
			{
				cave[h][i] = '.';
				Update();
				return;
			}
		}
	}

	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			cin >> cave[i][j];
	cin >> N;
	int height = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> height;
		height =R- height;

		Crash(height, i & 1);
	}


	for (int i = 0; i < R; ++i){
		for (int j = 0; j < C; ++j){
			cout << cave[i][j];
		}
		cout << endl;
	}
}