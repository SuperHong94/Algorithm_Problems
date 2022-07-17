#include <vector>
#include <memory.h>
using namespace std;

int MOD = 20170805;

int cache[2][501][501];

int M, N;

int dfs(int y, int x, int isY, vector<vector<int>>& Map)
{
	if (y == M - 1 && x == N - 1)
	{
		return 1;
	}
	if (y == M || x == N)
		return 0;

	int& ret = cache[isY][y][x];
	if (ret != -1)
		return ret;
	ret = 0;
	


	if (Map[y][x] == 1)
		return ret;
	if (Map[y][x] == 2) //��ȸ�� ����
	{
		if (isY == 1)
			return ret = dfs(y + 1, x, 1, Map)%MOD;
		else
			return ret = dfs(y, x + 1, 0, Map)%MOD;

	}
	else {
		
			int r1= dfs(y + 1, x, 1, Map)%MOD;
	
			int r2 = dfs(y, x + 1, 0, Map)%MOD;
			ret = (r1 + r2) % MOD;
	}
	return ret;
}

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int m, int n, vector<vector<int>> city_map) {
	M = m; N = n;
	memset(cache, -1, sizeof(cache));
	int answer = dfs(0, 0, 0, city_map);
	return answer;
}


int main()
{
	int a = solution(3, 6, { {0, 2, 0, 0, 0, 2},{0, 0, 2, 0, 1, 0},{1, 0, 0, 2, 2, 0} });

	a;
}