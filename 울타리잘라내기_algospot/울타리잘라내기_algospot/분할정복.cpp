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

	int ret = max(solve(left, mid), solve(mid + 1, right));//�����Ͽ� ���� ������ū�� Ȯ���Ѵ�.

	//�κκп� ��� ��ġ�� �簢���� ���� ū ���� ã�´�.
	int lo = mid, hi = mid + 1;
	int height = min(h[lo], h[hi]);
	
	//mid, mid+1�� �����ϴ� �ʺ� 2�� ������� ����Ѵ�.
	ret = max(ret, height * 2);
	while (left < lo || hi < right) {
		//�׻� ���̰� �� ���������� Ȯ���Ѵ�.
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
			++hi;
			height = min(height, h[hi]);
		}
		else {
			--lo;
			height = min(height, h[lo]);
		}

		//Ȯ���� ����
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