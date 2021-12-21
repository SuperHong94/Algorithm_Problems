#include <iostream>
using namespace std;


int wine[10000];
int cache[10000];
int N;


int solv(int start)
{
	if (start >= N)
		return 0;

	if (cache[start] != 0)
		return cache[start];

	return cache[start] =max(wine[start] + solv(start + 2), wine[start] + solv(start + 1));

}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> wine[i];


	cout << solv(0);

}