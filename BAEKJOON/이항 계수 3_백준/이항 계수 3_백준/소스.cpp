#include <iostream>
using namespace std;

constexpr long long MOD = 1000000007;



long long mul(long long a, long long n)
{
	long long ret = 1;
	while (n)
	{
		if (n & 1) {
			ret *= a;
			ret = ret % MOD;

		}
		a *= a;
		a %= MOD;
		n /= 2;;
	}


	return ret;
}

int main()
{
	int N = 0, K = 0; cin >> N >> K;

	long long n_f = 1;
	long long child = 1;
	for (long long i = 1; i <= N; ++i) {
		n_f *= i;
		n_f %= MOD;
	}

	for (long long i = 1; i <= K; ++i) {
		child *= i;
		child %= MOD;
	}
	for (long long i = 1; i <= N - K; ++i) {
		child *= i;
		child %= MOD;
	}

	long long child2 = mul(child, MOD - 2);
	child2 %= MOD;
	long long ret = n_f * child2;
	ret %= MOD;
	cout << ret << endl;


}