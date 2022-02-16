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
		return cache[y][x];
	if (-1 == Board[y][x])
		return 0;//삭제예정
	if (1 == Board[y][x]||2 == Board[y][x])
		return 1;

	for (int i = 0; i < 4; ++i) {
		if (DFS(dy[i] + y, dx[i] + x) == 0)
			return cache[y][x] = 0;
	}
	return cache[y][x] = 1;

}

void solution()
{
	memset(cache, -1, sizeof(cache));

	if (DFS(1,1) == 0) {
						Board[i][j] = 2;
						break;
					}


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