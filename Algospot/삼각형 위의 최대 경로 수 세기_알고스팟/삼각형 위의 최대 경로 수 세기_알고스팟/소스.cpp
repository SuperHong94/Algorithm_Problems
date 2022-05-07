#include <iostream>
#include <memory.h>
using namespace std;

int triangle[100][100];
int cache[100][100];
int cntCache[100][100];

int N = 0;

/*
가장 큰 수를 구하는 것은 쉽다.
문제는 가장 큰 수를 만드는 모든 경로를 세는 것?


*/

int solution(int x, int y)
{
	if (y == N || x == N)
		return 0;
	if (cache[y][x] != 0)
		return cache[y][x];


	int& ret = cache[y][x];

	return ret = max(triangle[y][x] + solution(x, y + 1), solution(x + 1, y + 1) + triangle[y][x]);

}

int GetCourseCnt(int x, int y)
{
	if (y == N-1)
		return 1;
	if (cntCache[y][x] != -1)
		return cntCache[y][x];

	int& ret = cntCache[y][x];
	ret = 0;
	if (cache[y + 1][x] < cache[y + 1][x + 1])
		return ret += GetCourseCnt(x + 1, y + 1);
	else if (cache[y + 1][x] > cache[y + 1][x + 1])
		return ret += GetCourseCnt(x, y + 1);
	else
		return ret += GetCourseCnt(x, y + 1) + GetCourseCnt(x + 1, y + 1);
}

int main()
{
	int c = 0; cin >> c;
	while (c--)
	{
		
		memset(cache, 0, sizeof(cache));
		memset(cntCache, -1, sizeof(cntCache));
		cin >> N;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < i + 1; ++j) {
				cin >> triangle[i][j];
			}
		}
		solution(0, 0);
		int cnt=GetCourseCnt(0, 0);
		cout << cnt << endl;



	}


}




