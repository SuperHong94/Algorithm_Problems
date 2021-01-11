#include <iostream>
#include <memory.h>
using namespace std;


char Board[500];
int cnt = 0;
int result = 0;

/// <summary>
/// 'X'의 개수를 세주는 함수
/// </summary>
/// <param name="index"></param>
/// <returns></returns>
int XCount(int index)
{
	if (Board[index] == 'X') {
		cnt += 1;
		XCount(index + 1);
	}
	return cnt;

}
int main()
{

	memset(Board, 0, sizeof(Board));
	cin >> Board;


	int i = 0;
	while (Board[i] != 0)
	{
		switch (Board[i]) {
		case 'X':
			cnt += 1;
			XCount(i + 1);
			if (cnt % 2 != 0)
			{
				cout << -1;
				return 0;
			}
			else {
				int q = i;
				if (cnt / 4 != 0) {
					for (int j = i; j < ((cnt/4)*4) + i; j++) {
						Board[j] = 'A';
						q = j;
					}

					q += 1;
				}
				for (q; q < i + cnt; q++)
					Board[q] = 'B';
			}
			i = i + cnt;
			cnt = 0;
			break;
		case '.':
			Board[i] = '.';
			i++;
			break;
		}


	}

	cout << Board;
}