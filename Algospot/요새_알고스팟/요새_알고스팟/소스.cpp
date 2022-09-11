#include <iostream>

using namespace std;

/*
21 15 20
15 15 10
13 12 5
12 12 3
19 19 2
30 24 5
32 10 7
32 09 4
*/


//반지름 작은 순으로 정렬
//작은것 부터 자신의 부모 찾기
//

bool isContain(int x1, int y1, int x2, int y2, int r)
{
	int X = (x1 - x2); X = X * X;
	int Y = (y1 - y2); Y = Y * Y;
	
	return (X + Y) < (r* r);
}

int main()
{
	int T = 0; cin >> T;
	while (T--)
	{

	}
}