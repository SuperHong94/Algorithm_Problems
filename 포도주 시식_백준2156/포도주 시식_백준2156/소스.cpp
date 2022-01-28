#include <iostream>
#include <memory.h>
using namespace std;


int wine[10002];
int cache[10002];
int N;


int solv(int start)
{
	if (start >= N)
		return 0;

	if (cache[start] != -1)
		return cache[start];


	int v1 = wine[start] + wine[start+1]+solv(start+3);
	int v3 = wine[start + 1] + wine[start + 2] + solv(start + 4);
	int v2 = wine[start] + solv(start + 2);
	

	
	return cache[start]=max(max(v1,v2),v3);

}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> wine[i];

	

	cout << solv(0);

}