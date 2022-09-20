//https://algospot.com/judge/problem/read/RUNNINGMEDIAN

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int T = 0; cin >> T;
	while (T--) {
		priority_queue<int> max_q;
		priority_queue<int,vector<int>,greater<int>> min_q;
		int N = 0; cin >> N;

		vector<int>A;
		A.resize(N);
		A[0]=(1983);
		long long a = 0, b = 0; cin >> a >> b;
		for (int i = 1; i < N; ++i)
		{
			long long temp = (A[i - 1] * a + b) % 20090711;;
			A[i] = temp;
		}

		int sum = 0;
		for (int i = 0; i < A.size(); ++i)
		{
			if (max_q.size() == min_q.size())
				max_q.push(A[i]);
			else
				min_q.push(A[i]);
			if (!max_q.empty() && !min_q.empty() && max_q.top() > min_q.top())
			{
				int max = max_q.top(); max_q.pop();
				int min = min_q.top(); min_q.pop();
				min_q.push(max);
				max_q.push(min);
			}
			sum = (sum+max_q.top())% 20090711;

		}
		cout << sum << '\n';

	}
}