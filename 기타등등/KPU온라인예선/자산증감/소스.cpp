#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
char BOARD[100][100];


int N = 0;
int main()
{
	memset(BOARD, '.', sizeof(BOARD));

	cin >> N;
	int Sx = 0, Sy = 0, Ex = 0, Ey = 0;
	queue<char> q;
	char preChar = '.';
	for (int i = 0; i < N; ++i)
	{
		char tmp;
		cin >> tmp;
		switch (preChar)
		{
		case '+':
		{
			switch (tmp)
			{
			case '+':
				Sy++;
				break;
			case '-': 
				break;
			case '=':
				Sy++;
				break;
			default:
				break;
			}
		}
			break;
		case '-':
		{
			switch (tmp)
			{
			case '+':
				break;
			case '-': //이전에 /였는데  현재까너는
				break;
			case '=':
				break;
			default:
				break;
			}
		}
			break;
		case '=':
		{
			switch (tmp)
			{
			case '+':
				Sy++;
				break;
			case '-': //이전에 /였는데  현재까너는
				break;
			case '=':
				break;
			default:
				break;
			}
		}
			break;
		default:
			break;
		}
		preChar = tmp;
		q.push(tmp);

	}

	char old = q.front();
	switch (old)
	{
	case '+':
		BOARD[Sy][Sx] = '/';
		break;
	case '-': 
		BOARD[Sy][Sx] = '\\';
		break;
	case '=':
		BOARD[Sy][Sx] = '_';
		break;
	default:
		break;
	}

	Ex = Sx; Ey = Sy;
	int topY = Ey;
	q.pop();

	while (!q.empty())
	{
		char c = q.front();
		q.pop();
		switch (c)
		{
		case '+':
			if (old == '-'||old=='=') {
				Ex++;
				BOARD[Ey][Ex] = '/';
				break;
			}
			Ey--; Ex++;
			BOARD[Ey][Ex] = '/';
			break;
		case '-':
			if (old == '+') {
				Ex++;
				BOARD[Ey][Ex] = '\\';
				break;
			}
			Ey++; Ex++;
			BOARD[Ey][Ex] = '\\';
			break;
		case '=':
			if (old == '+') {
				Ey--; Ex++;
				BOARD[Ey][Ex] = '_';
				break;
			}
			else if (old == '-') {
				Ey++; Ex++;
				BOARD[Ey][Ex] = '_';
				break;
			}
			Ex++;
			BOARD[Ey][Ex] = '_';
			break;
		default:
			break;
		}
		if (topY >= Ey)
			topY = Ey;
		old = c;
	}

	int lastY = Sy - Ey;
	int StartY = 0;
	if (lastY > 0) {
		
		lastY = Sy;
		//StartY = Ey;
	}
	else {
		lastY = Ey;
		//StartY = Sy;
	}

	for (int i = topY; i <= lastY; ++i)
	{
		for (int j = 0; j <N ; ++j)
			cout << BOARD[i][j];
		cout << endl;
	}

}