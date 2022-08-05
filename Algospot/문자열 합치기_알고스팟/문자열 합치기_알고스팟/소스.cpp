//https://algospot.com/judge/problem/read/STRJOIN
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int strLen[1000];
int N = 0;
int main()
{
	int T = 0; cin >> T;

	while (T--)
	{
		priority_queue<int, vector<int>, greater<int>> pq;

		cin >> N;
		for (int i = 0; i < N; ++i) {
			int a = 0;
			cin >> a;
			pq.push(a);
		}
		int result = 0;
		while (pq.empty() == false) {
			while (pq.size() > 1) {
				int a = pq.top(); pq.pop();
				int b = pq.top(); pq.pop();
				pq.push(a + b);
				result += (a + b);
			}
			if (pq.size() == 1)
				break;

		}
		cout << result << '\n';
	}
}