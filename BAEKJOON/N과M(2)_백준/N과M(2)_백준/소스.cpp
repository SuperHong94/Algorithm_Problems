#include<iostream>
using namespace std;

int n(0), m(0);
int arr[10] = { 0 };
bool isUsed[10] = { 0 };

void subSeq(int cur, int latestNum) {
	if (cur == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = latestNum + 1; i <= n; i++) {
		if (!isUsed[i]) {
			isUsed[i] = true;
			arr[cur] = i;
			subSeq(cur + 1, i);
			isUsed[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	subSeq(0, 0);
	return 0;
}