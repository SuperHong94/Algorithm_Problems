#include <iostream>

using namespace std;


unsigned long long combie(int M, int N)
{
	unsigned long long ret = 1;
	for (int i = 1; i <= N; ++i) {
		ret *= M--;
		ret /= i;

	}


	return ret;
}
int main()
{
	int T = 0; cin >> T;

	while (T--) {
		int N = 0; cin >> N;
		int M = 0; cin >> M;
		unsigned long long ret = 1;
		int cnt = N;

		ret *= combie(M, N);

		cout << ret << '\n';
	}
}