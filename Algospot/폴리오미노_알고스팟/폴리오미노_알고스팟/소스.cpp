/*
https://algospot.com/judge/problem/read/POLY
*/

#include <iostream>
using namespace std;
int N;
const int dx[] = { 0,1 };
const int dy[] = { 1,0 };

int cache[101];//n개의 사각형일 때의 세로 단조 폴리오미노의 개수
char board[101][101];

int sol(int n)
{
	if (n == N)
		return N;

	if (cache[n] != 0)
		return cache[n];
	
	bool isTrue = true;
	for(int i=1;i<=n;++i){
		int oldX = 1;
		if (isTrue == false)
			break;
		for (int j = 1; j <= n; ++j)
		{
			if (board[i][j] == 1)
			{
				if (oldX == 1)
					oldX = j;
				else if (j - oldX > 1) {
					isTrue = false;
					break;
				}
			}
		}
	} //세로 단조인지 확인

	return cache[n] = sol(n - 1) + sol(n - 1);
}

int main()
{
	int C = 0; cin >> C;

	cache[1] = 1;
	cache[2] = 2;
	while (C--)
	{
		cin >> N;



	}
}