#include <iostream>
#include <math.h>
using namespace std;

int cache[2][12];
int main()
{
	int N = 0; cin >> N;
	int answer = 9;
	int mod = 1000'000'000;
	for (int i = 2; i < 11; ++i)
		cache[1][i] = 1;
	for (int i = 2; i <= N; ++i)
	{
		answer = 0;

        for(int j = 1; j < 11; j++) {
			cache[i%2][j] = (cache[(i-1)%2][j-1] + cache[(i-1)%2][j+1]) % mod;
			answer = (answer + cache[i%2][j]) % mod;
        }

	}

	cout << answer << '\n';
}