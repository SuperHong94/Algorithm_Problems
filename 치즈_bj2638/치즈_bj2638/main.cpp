#include <iostream>

using namespace std;


int Board[101][101];
int cache[101][101];
int y = 0, x = 0;
int deleteCnt, lastCnt;
int DFS(int y, int x)
{
	//if (cache[y][x] != -1)
	//	return cache[y][x];
	if (Board[y][x] == -1) //외부라는 뜻
		return 1;
	if (Board[y][x] == 2)
		return 0;
	int dirX[] = { 0,0,-1,1 };
	int dirY[] = { -1,1,0,0 };

	for (int i = 0; i < 4; ++i)
	{
		
		if (DFS(y + dirY[i], x + dirX[i]) == 1){
			return cache[y][x] = 1;
			
		}
		
	}
	return cache[y][x] = 0;
}


int countChease()
{
	int cnt = 0;
	for (int i = 1; i <= y; ++i) {
		for (int j = 1; j <= x; ++j)
		{
			if (Board[i][j] == 1)
			{
				cnt += 1;
			}
		}
	}
	return cnt;
}


void solution()
{

	lastCnt = countChease();
	int remainCnt = countChease();
	while (remainCnt != 0) {
		memset(cache, -1, sizeof(cache));
		lastCnt = remainCnt;
		for (int i = 1; i <= y; ++i) {
			for (int j = 1; j <= x; ++j)
			{
				if (Board[i][j] == 1) {
					//DFS(i - 1, j) + DFS(i + 1, j) + DFS(i, j - 1) + DFS(i, j + 1);
					int ret = DFS(i , j) ;
					if (ret == 1)// 외곽이면
					{
						Board[i][j] = 2;// 지운 갯수
					}
				}
			}
		}
		for (int i = 1; i <= y; ++i) {
			for (int j = 1; j <= x; ++j)
			{
				if (Board[i][j] == 2) {
					Board[i][j] = 0;// 지운 갯수
				}
			}
		}
		remainCnt = countChease();
		deleteCnt += 1;
	}
}
int main()
{
	memset(Board, -1, sizeof(Board)); //맨 가생이는 -1로 할꺼임
	cin >> y >> x;

	for (int i = 1; i <= y; ++i)
		for (int j = 1; j <= x; ++j)
			cin >> Board[i][j];

	solution();

	cout << deleteCnt << '\n' << lastCnt << '\n';

}