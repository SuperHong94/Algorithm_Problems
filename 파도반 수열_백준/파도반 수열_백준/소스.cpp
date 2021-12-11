#include <iostream>

using namespace std;

long long cache[151];
int main()
{


	cache[1] = 1; cache[2] = 1; cache[3] = 1;

	int T = 0; cin >> T;
	while (T--) {
		int n = 0; cin >> n;

		for (int i = 4; i <= n; ++i) {

			cache[i] = cache[i - 3] + cache[i - 2];
		}

		cout << cache[n] << '\n';
	}
}