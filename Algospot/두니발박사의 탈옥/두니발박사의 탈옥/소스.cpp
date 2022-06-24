/*
https://algospot.com/judge/problem/read/NUMB3RS

생각을 바꿔서 애초에 d일 에 해당마을에서 시작마을로 가는 확률을 구해볼까?
*/

#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;



int village_cnt = 0;
int day;
int start;
double result[101][51];//d에 n마을에 있을 확률 저장


//void BFS(const vector<vector<int>>& village, int d, int p, double percent)
//{
//	if (d > day)
//		return;
//
//	if (isVisit[d][p] == false)
//		for (int i : village[p]) {
//			result[d][i] += (1.0f / village[p].size()) * percent;
//
//
//			BFS(village, d + 1, i, result[d][i]);
//			isVisit[d][p] = true;
//		}
//
//
//}

double BFS2(const vector<vector<int>>& village, int d, int pos)
{
	if (d == 0) {
		if (pos == start)
			return 1.0;
		else
			return 0.0;
	}

		if (result[d][pos] != -1.0)
			return result[d][pos];
		
		result[d][pos] = 0.0;
		for (int i : village[pos])
		{
			result[d][pos] += BFS2(village, d - 1, i) / village[i].size();
		}

		return result[d][pos];
	



}




int main()
{
	int c = 0; cin >> c;
	while (c--) {

		cin >> village_cnt >> day >> start;
		vector<vector<int>> village(village_cnt);
		for (int i = 0; i < village_cnt; ++i)
			for (int j = 0; j < village_cnt; ++j) {
				int a = 0; cin >> a;
				if (a == 0)continue;
				village[i].push_back(j);
			}
		for (int i = 0; i <= day; ++i)
		{
			for (int j = 0; j <= village_cnt; ++j)
				result[i][j] = -1.0;
		}
		int t = 0; cin >> t;

		for (int i = 0; i < t; ++i) {
			int a = 0; cin >> a;
			cout.precision(8);
			cout << BFS2(village, day, a) << ' ';
		}



	
		cout << endl;


	}
}
