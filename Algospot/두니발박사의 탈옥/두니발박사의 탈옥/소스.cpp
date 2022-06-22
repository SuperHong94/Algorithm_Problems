/*
https://algospot.com/judge/problem/read/NUMB3RS
*/

#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;



int village_cnt = 0;
int day;
int start;
double result[100][50];//d에 n마을에 있을 확률 저장

bool isVisit[100][50];

void BFS(const vector<vector<int>>& village, int d, int p, double percent)
{
	if (d > day)
		return;

	if (isVisit[d][p] == false)
		for (int i : village[p]) {
			result[d][i] += (1.0f / village[p].size()) * percent;


			BFS(village, d + 1, i, result[d][i]);
			isVisit[d][p] = true;
		}


}




int main()
{
	int c = 0; cin >> c;
	while (c--) {
		memset(result, 0, sizeof(result));
		memset(isVisit, 0, sizeof(isVisit));
		cin >> village_cnt >> day >> start;
		vector<vector<int>> village(village_cnt);
		for (int i = 0; i < village_cnt; ++i)
			for (int j = 0; j < village_cnt; ++j) {
				int a = 0; cin >> a;
				if (a == 0)continue;
				village[i].push_back(j);
			}
		int t = 0; cin >> t;
		vector<int> q;
		for (int i = 0; i < t; ++i) {
			int a = 0; cin >> a;
			q.push_back(a);
		}
		BFS(village, 1, start, 1.0f);

		for (int item : q)
			cout << result[day][item] << ' ';
		cout << endl;


	}
}
