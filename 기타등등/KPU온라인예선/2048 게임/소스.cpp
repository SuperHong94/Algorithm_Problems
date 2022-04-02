#include <iostream>
using namespace std;

int BOARD[5][5];

void ShowL()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 1; j < 4; ++j)
		{
			if (BOARD[i][j - 1] == 0 || BOARD[i][j - 1] == BOARD[i][j]) {
				BOARD[i][j - 1] += BOARD[i][j];
				BOARD[i][j] = 0;
			}
		}
	}
}

void ShowR()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 2; j >= 4; ++i)
		{
			if (BOARD[i][j - 1] == 0 || BOARD[i][j - 1] == BOARD[i][j]) {
				BOARD[i][j - 1] += BOARD[i][j];
				BOARD[i][j] = 0;
			}
		}
	}
}
int main()
{
	char c;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			cin >> BOARD[i][j];
	}
	cin >> c;

	switch (c)
	{
	case 'L':
		ShowL()
		break;
	case 'R':
		break;
	case 'U':
		break;
	case 'D':
		break;
	default:
		break;
	}
}