/*
https://www.acmicpc.net/problem/3197
*/
#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;


constexpr char ICE = 'X';
constexpr char WATER = '.';
constexpr char L = 'L';



char Map[1500][1500];
bool visit[1500][1500]; //어느방향에서 방문했는지 확인
int R, C;


int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int tx[2], ty[2];



queue<pair<short, short>> q;  //백조 큐
queue<pair<short, short>> water; //물큐
queue<pair<short, short>> nq;
queue<pair<short, short>> nwater;


bool BFS()
{


	while (q.empty() == false)
	{
		auto pos = q.front();
		q.pop();

		visit[pos.second][pos.first] = true;





		for (int i = 0; i < 4; ++i)
		{
			int nX = pos.first + dx[i], nY = pos.second + dy[i];
			if (nX < 0 || nX >= C || nY < 0 || nY >= R || visit[nY][nX] == true)
				continue;

			visit[nY][nX] = true;
			if (Map[nY][nX] == ICE)
			{
				nq.push({ nX,nY });
				continue;
			}
			if (nX == tx[1] && nY== ty[1])
				return true;
		
			q.push({ nX,nY });
		}
	}

	return false;

}


bool BFS2()
{


	while (water.empty() == false)
	{
		auto pos = water.front();
		water.pop();


		for (int i = 0; i < 4; ++i)
		{
			int nX = pos.first + dx[i], nY = pos.second + dy[i];
			if (nX < 0 || nX >= C || nY < 0 || nY >= R)
				continue;

			if (Map[nY][nX] == ICE)
			{
				Map[nY][nX] = WATER;
				nwater.push({ nX,nY });
				continue;
			}
		}
	}

	return false;

}
int sol()
{
	//백조 찾기
	int cnt = 0;

	q.push({ tx[0],ty[0] });
	visit[ty[0]][tx[0]] = true;

	while (true) {

		if (true == BFS())
			return cnt;
		cnt++;
		
		BFS2();

		q = nq;
		water = nwater;
		while (!nq.empty())nq.pop();
		while (!nwater.empty())nwater.pop();


	}
	return cnt;


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
			if (WATER == Map[i][j])
				water.push({ j,i });

		}


	cout << sol();
}

