/*
https://algospot.com/judge/problem/read/NUMB3RS
*/

#include <iostream>
#include <queue>
using namespace std;
char village[50][50];
int village_cnt = 0;
int day;
int start;
float result[100][50];//d에 n마을에 있을 확률 저장

void BFS(int d, int p)
{
	queue<int> q;
	q.push(p);

	while (!q.empty())
	{
		int DENOMINATOR = 0;
		for (int i = 0; i < village_cnt; ++i)
		{
			if (village[p][i] == 0) continue;
			q.push(i);
			DENOMINATOR++;
		}

		for (int i = 0; i < village_cnt; ++i)
		{
			if (village[p][i] == 0) continue;
			result[d][i] *= 1.0f / DENOMINATOR;
		}


	}


}
int main()
{
	int c = 0; cin >> c;
	while (c--) {
		cin >> village_cnt >> day >> start;

		for (int i = 0; i < village_cnt; ++i)
			for (int j = 0; j < village_cnt; ++j)
				cin >> village[i][j];
	}
}
