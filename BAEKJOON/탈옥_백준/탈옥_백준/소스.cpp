//https://www.acmicpc.net/problem/9376

#include <iostream>
#include <queue>
using namespace std;

constexpr char BLANK = ',';
constexpr char WALL = '*';
constexpr char PRISONER = '$';

char Prison[101][101];
int h, w;
int main()
{
	int T = 0; cin >> T;
	while (T--)
	{
		cin >> h >> w;

		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				cin >> Prison[i][j];
	}
}