//https://algospot.com/judge/problem/read/RUNNINGMEDIAN
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int MOD = 20090711;


vector<int> v;

struct RNG
{
	int seed, a, b;
	RNG(int _a,int _b):a(_a),b(_b),seed(1983){}
	int next() {
		int ret = seed;
		seed = ((seed * (long long)a) + b) % MOD;
		return ret;
	}
};

int GetMid(int n, RNG rng)
{
	priority_queue<int, vector<int>, less<int>>maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	int ret = 0;

	for (int cnt = 1; cnt <= n; ++cnt) {
		if (maxHeap.size() == minHeap.size())
			maxHeap.push(rng.next());
		else
			minHeap.push(rng.next());
		if (!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top()) {
			int a = maxHeap.top(), b = minHeap.top();
			maxHeap.pop(); minHeap.pop();
			maxHeap.push(b);
			minHeap.push(a);
		}
		ret = (ret + maxHeap.top()) % MOD;

	}
	return ret;
}
int main()
{
	int C = 0; cin >> C;
	while (C--) {
		int N = 0, a = 0, b = 0; cin >> N >> a >> b;
		RNG rng = RNG(a, b);
		cout << GetMid(N, rng) << '\n';
	}

}
