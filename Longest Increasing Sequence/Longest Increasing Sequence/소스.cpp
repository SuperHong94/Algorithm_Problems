#include<iostream>
#include <memory.h>
using namespace std;

int N = 0;
int subseq[500];
int cache[500];

int solv(int index)
{
	if (cache[index] != 0)
		return cache[index];
	if (index == N)
		return 0;

	cache[index] = 1;
	for (int i = index + 1; i < N; ++i)
	{
		if (subseq[i] > subseq[index]) {
			cache[index] = max(cache[index], solv(i) + 1);
		}
	}
	return cache[index];
}
int main()
{
	int C = 0; cin >> C;

	while (C--)
	{
		memset(cache, 0, sizeof(cache));
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> subseq[i];


		int MAX = 0;
		for (int i = 0; i < N; ++i) {
			MAX = max(MAX, solv(i));
		}
		cout << MAX << '\n';

	}



}