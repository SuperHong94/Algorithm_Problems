#include <iostream>
#include <string>
using namespace std;

char BOARD[64][64];
int N = 0;

bool IsFill(int y, int x,int n)
{
	char c = BOARD[y][x];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			if (BOARD[i+y][j+x] != c)
				return false;
	}
	return true;
}
string solution(int y,int x,int n)
{
	if (IsFill(y,x,n))
	{

		return string{ BOARD[y][x] };
	}
	string UL = solution(y, x, n / 2);
	string UR = solution(y, x+n/2, n / 2);
	string DL = solution(y + n / 2, x, n / 2);
	string DR = solution(y + n / 2, x+n / 2, n / 2);
	return ("(" + UL + UR + DL + DR + ")");
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cin >> BOARD[i][j];
	}

	cout << solution(0,0,N);
}