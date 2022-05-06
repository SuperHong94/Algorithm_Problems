#include <iostream>
using namespace std;

int triangle[100][100];
int cache[100][100];
int N = 0;

/*
���� ū ���� ���ϴ� ���� ����. 
������ ���� ū ���� ����� ��� ��θ� ���� ��?


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

int main()
{
	int c = 0; cin >> c;
	while (c--)
	{
		cin >> N;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < i + 1; ++j) {
				cin >> triangle[i][j];
			}
		}
		int ret = solution(0, 0);

		cout << ret << endl;
	}


}