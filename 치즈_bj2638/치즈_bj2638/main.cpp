#include <iostream>

using namespace std;


int Board[101][101];
int cache[101][101];
int y = 0, x = 0;

int main()
{
	memset(Board, -1, sizeof(Board)); //�� �����̴� -1�� �Ҳ���
	cin >> y >> x;

	for (int i = 1; i <= y; ++i)
		for (int j = 1; j <= x; ++j)
			cin >> Board[i][j];

}