#include <iostream>
#include <unordered_set>

using namespace std;


int main()
{
	unordered_set<int> ms;
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 0; cin >> N;
	for(int i=0;i<N;++i){
		int a = 0; cin >> a;
		ms.insert(a);
	}
	int M = 0; cin >> M;
	for (int i = 0; i < M; ++i) {
		int b = 0; cin >> b;
		if (ms.count(b) == 0)
			cout << 0 << '\n';
		else
			cout << 1 << '\n';
	}
}