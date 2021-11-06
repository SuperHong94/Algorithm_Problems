#include <iostream>
#include <vector>
using namespace std;

int N = 0;
vector<int> h;

int solve(int left, int right)
{
	if (left == right)
		return h[left];

	int mid = (left + right) / 2;

	int ret = max(solve(left, mid), solve(mid + 1, right));//분할하여 각자 뭐가더큰지 확인한다.

	//두부분에 모두 걸치는 사각형중 가장 큰 것을 찾는다.
	int lo = mid, hi = mid + 1;
	int height = min(h[lo], h[hi]);
	
	//mid, mid+1만 포함하는 너비 2인 사격형을 고려한다.
	ret = max(ret, height * 2);
	while (left < lo || hi < right) {
		//항상 높이가 더 높은쪽으로 확장한다.
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
			++hi;
			height = min(height, h[hi]);
		}
		else {
			--lo;
			height = min(height, h[lo]);
		}

		//확장후 넓이
		ret = max(ret, height * (hi - lo + 1));
	}
	return ret;
}
int main()
{
	int C = 0; cin >> C;

	for (int j = 0; j < C; ++j) {
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			int a = 0; cin >> a;
			h.push_back(a);
		}

		cout << solve(0, N - 1) << endl;
		h.clear();
	}

}