#include <iostream>
using namespace std;


int wine[10002];
int cache[10002];
int N;


int solv(int start)
{
	if (start >= N)
		return 0;

	if (cache[start] != 0)
		return cache[start];


	int v1 = wine[start] + wine[start+1]+solv(start+3);
	int v3 = wine[start + 1] + wine[start + 2] + solv(start + 4);
	int v2 = wine[start] + solv(start + 2);
	

	
	return cache[start]=max(max(v1,v2),v3);

}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> wine[i];

	cache[1] = wine[1];
	cache[2] = wine[1] + wine[2];

	for (int i = 3; i <= N; ++i)
	{
		cache[i] = max(cache[i - 1], max(cache[i - 2] + wine[i], cache[i - 3] + wine[i - 1] + wine[i]));
	}

	cout << cache[N];

}