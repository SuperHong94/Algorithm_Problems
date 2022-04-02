#include <iostream>

using namespace std;

int cache[1'000'001];

int F(int n)
{
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else if (n == 2) return 2;
	else if (n == 3) return 3;

	if (cache[n] != 0) return cache[n];
	else
		return cache[n] = (F(n - 2) + F(n - 1)) % 15746;
}
int main()
{
	int n = 0; cin >> n;

	cout << F(n) ;
}