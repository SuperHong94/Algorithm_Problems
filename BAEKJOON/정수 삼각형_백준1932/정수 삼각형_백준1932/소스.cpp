#include <iostream>

using namespace std;

int triangle[501][501];
int cache[501][501];

int N = 0;

int solv(int x, int y)
{
	if (y == N)
		return 0;
	if (cache[y][x] != 0)
		return cache[y][x];
	return  cache[y][x]=max(triangle[y][x]+solv(x, y + 1), triangle[y][x]+solv(x + 1, y + 1));
}
int main()
{

	cin >> N;
	for (int i = 0; i <N; ++i) {
		for (int j = 0; j <=i; ++j)
			cin >> triangle[i][j];
	}

	cout << solv(0, 0);

}