#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;


int Board[101][101];
int cache[101][101];
const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };
int Y = 0, X = 0;
int cheaseCnt = 0;
void BFS()
{
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	cache[1][1] = 0;
	while (!q.empty()) {

		pair<int, int> yx = q.front();
		int y = yx.first;
		int x = yx.second;
		q.pop();
		//cache[yx.first][yx.second] = 0;
		

		for (int i = 0; i < 4; ++i) {
			if (Board[dy[i] + y][dx[i] + x] == -1 || cache[dy[i] + y][dx[i] + x] != -1)
				continue;
			if (Board[dy[i] + y][dx[i] + x] == 1 || Board[dy[i] + y][dx[i] + x] == 2) {
				Board[dy[i] + y][dx[i] + x] = 2;
				continue;
			}
			cache[dy[i] + y][dx[i] + x] = 0;
			q.push({ dy[i] + y,dx[i] + x });

		}

	}

}

int GetCheaseCnt()
{
	int ret = 0;
	for (int i = 1; i <= Y; ++i)
		for (int j = 1; j <= X; ++j) {
			if (Board[i][j] == 1) {
				ret++;
			}
			else if (Board[i][j] == 2)
				Board[i][j] = 0;
		}
	return ret;
}
int solution()
{


	int cnt = 0;
	cheaseCnt = GetCheaseCnt();
	while (true)
	{
		memset(cache, -1, sizeof(cache));
		BFS();
		cnt += 1;
		int temp = GetCheaseCnt();
		if (temp == 0)
			break;
		else
			cheaseCnt = temp;
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
	int time = solution();
	cout << time << '\n' << cheaseCnt;

	return 0;

}