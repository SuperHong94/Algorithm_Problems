#include <iostream>
#include <memory.h>
using namespace std;

int triangle[100][100];
int cache[100][100];

int N = 0;
int MAX = 0;
int cnt = 0;
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

void GetCourseCnt(int x, int y, int value)
{
	if (x == N)
		return;
	if (y == N - 1) {
		value -= triangle[y][x];
		if (value == 0)
			cnt += 1;

		return;
	}
	GetCourseCnt(x, y + 1, value - triangle[y][x]);
	GetCourseCnt(x + 1, y + 1, value - triangle[y][x]);
}

int main()
{
	int c = 0; cin >> c;
	while (c--)
	{
		cnt = 0;
		memset(cache, 0, sizeof(cache));
		cin >> N;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < i + 1; ++j) {
				cin >> triangle[i][j];
			}
		}
		MAX = solution(0, 0);
		GetCourseCnt(0, 0,MAX);
		cout << cnt << endl;



	}


}


//동적계획+DFS로는 시간초과 뜨네 ..