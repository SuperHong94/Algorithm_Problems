#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int N;

int triangle[101][101];
int cache[101][101];
int dfs(int y, int x)
{
	if (cache[y][x] != 0)
		return cache[y][x];
	if (triangle[y][x]==0)
		return 0;

	int value = triangle[y][x];
	int MAX = 0;
	MAX = max(dfs(y + 1, x), dfs(y + 1, x + 1));
	return cache[y][x]=(MAX + value);

}
int main()
{
	int C = 0; cin >> C;
	while (C--)
	{
		memset(triangle, 0, sizeof(triangle));
		memset(cache, 0, sizeof(cache));
		cin >> N;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j <= i; ++j)
			{
				cin >> triangle[i][j];
			}
		}
		cout << dfs(0, 0)<<endl;
	}
}