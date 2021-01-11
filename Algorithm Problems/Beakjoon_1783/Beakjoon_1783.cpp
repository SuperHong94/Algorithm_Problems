#include <iostream>
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}



int main()
{
	int N = 0, M = 0;
	cin >> N >> M;
	if (N == 1)
		cout << 1 << endl;
	else if (N == 2)
		cout << min(4, (M + 1) / 2) << endl;
	else if (M < 7)
		cout << min(4, M) << endl;
	else
		cout << M - 7 + 5 << endl;
}