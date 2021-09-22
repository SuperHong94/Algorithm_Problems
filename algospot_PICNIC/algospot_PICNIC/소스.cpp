#include <iostream>	
#include <vector>
#include <memory.h>
using namespace std;

bool person[10];
int serach(const vector < vector<int>>& v,int y,int cnt, int n)
{
	if (cnt == n)
		return 1;
	for (int i = y; i < n; ++i) {
		for(int j=0;j<v[i].size();++j)
		if (person[i] == false&&person[j]==false) {
			person[i] = true;
			person[j] = true;
			return serach(v, i, cnt + 2, n);
		}
	}
	return 0;
}
int solution(vector < vector<int>>& v,const int n)
{
	int result = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < v[i].size(); ++j) {
			memset(person, false, sizeof(person));
			person[i] = true;
			person[v[i][j]] = true;
			v[i][j] = -1;
			v[v[i][j]].erase(v[v[i][j]].begin() + i);
			result += serach(v, i, 2, n);
		}
	}
	return result;
}
int main()
{
	int C = 0;
	cin >> C;
	for (int i = 0; i < C; ++i) {
		int n = 0; //학생 수
		cin >> n;
		int m = 0;  //친구 쌍의 수
		cin >> m;
		vector<vector<int>> v;
		v.resize(n);
		for (int j = 0; j < m; ++j) {
			int a = 0, b = 0;
			cin >> a >> b;
			v[a].push_back(b); //a의 친구 b 추가
			v[b].push_back(a); //b의 친구 a 추가

		}
		cout << solution(v, n) << endl;

	}
}