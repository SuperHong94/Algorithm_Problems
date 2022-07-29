//https://www.acmicpc.net/problem/9471

#include <iostream>
using namespace std;


int main()
{
	int T = 0; cin >> T;
	while (T--)
	{
		long long N = 0, M; cin >> N >> M;

		long long p = 1, pp = 0, cur = 0;

		long long ret = 0;
		for (long long j = 2;; ++j) {
			cur = (p % M + pp % M) % M;
			if (cur == 0 && p == 1) {
				ret = j;
				break;
			}
			pp = p;
			p = cur;


		}
		cout << N << ' ' << ret << '\n';
	}
}