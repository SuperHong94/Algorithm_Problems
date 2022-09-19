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
		priority_queue<int> min_q;
		int N = 0; cin >> N;

		vector<int>A;
		A.reserve(N);
		A.push_back(1983);
		int a = 0, b = 0; cin >> a >> b;
		for (int i = 1; i < N; ++i)
		{

			A[i] = (A[i - 1] * a + b) % 20090711;
		}

		int sum = 0;
		for (int i = 0; i < A.size(); ++i)
		{
			if (max_q.empty())max_q.push(A[i]);
			else if (max_q.top() < A[i])
			{
				if (min_q.empty())min_q.push(A[i]);
				else if()
			}

			sum += max_q.top();

		}

	}
}