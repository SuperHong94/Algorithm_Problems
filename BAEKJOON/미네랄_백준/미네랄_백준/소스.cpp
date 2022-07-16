//https://www.acmicpc.net/problem/2933
#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

//덩어리 채로 떨어져야 한다.

int R, C, N;
char cave[101][101];
bool visit[101][101];



int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };


void DFS(int y, int x)
{
	visit[y][x] = true;
	for (int i = 0; i < 4; ++i)
	{
		if (y < 0 || x < 0 || y >= R || x>= C)continue;
		int nextY = y + dy[i];
		int nextX = x + dx[i];

		if (cave[nextY][nextX] == 'x' && visit[nextY][nextX] == false)
			DFS(nextY, nextX);
	}
}

void DownBlock(vector<pair<int, int>>& tb)
{
	while (true)
	{
		for (auto& block : tb)
		{
			int y = block.first;
			int x = block.second;
			
			if (y == R - 1) //바닥에 도달
				return;
			if ( visit[y + 1][x]==true) //떨어져서 바닥 클러스터와 만났을때
				return;
			

		}
		for (auto& block : tb)
		{
			int& y = block.first;
			int x = block.second;
			cave[y + 1][x] = 'x';
			cave[y][x] = '.';

			y += 1;
		}

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

	vector<pair<int, int>> targetBlocks;
	for (int i = 0; i < C; ++i)
	{
		for (int j = R - 1; j >= 0; --j) {
			if (cave[j][i] == 'x' && visit[j][i] == false)
			{
				targetBlocks.emplace_back(j, i);
			}
		}
	}
	if (0 != targetBlocks.size())
		DownBlock(targetBlocks);


	

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
	/*ios::sync_with_stdio(false);
	cin.tie(0);*/

	cin >> R >> C;
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			cin >> cave[i][j];
	cin >> N;
	int height = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> height;
		height = R - height;

		Crash(height, i & 1);
	}


	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cout << cave[i][j];
		}
		cout << endl;
	}
}