//https://algospot.com/judge/problem/read/JOSEPHUS

#include <iostream>
#include <list>
using namespace std;

int main()
{
	int T = 0; cin >> T;

	int N = 0, K = 0;
	while (T--)
	{
		cin >> N >> K;
		list<int> l;
		for (int i = 1; i <=N; ++i)
			l.push_back(i);

		auto start = l.begin();
		while (l.size()>2) {
			start=l.erase(start);
			if (start == l.end()) start = l.begin();
			for (int i = 0; i < K - 1; ++i) {
				++start;
				if (start == l.end())start = l.begin();
			}
			
		}

		cout << l.front() << ' ' << l.back() << '\n';
	}
}