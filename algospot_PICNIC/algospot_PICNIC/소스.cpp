#include <iostream>	
#include <vector>
#include <memory.h>
using namespace std;

bool couples[10][10];
bool isVist[10];
int search(int startNum, int n, int cnt, int ret)
{

	if (n == cnt)
		return 1;
	for (int i = 0; i < n; ++i) {
		if (isVist[startNum] == false) {
			if (isVist[i] == false && couples[startNum][i] == true) {
				isVist[startNum] = true;
				isVist[i] = true;
				ret += search(startNum + 1, n, cnt + 2, 0);
				isVist[startNum] = false;
				isVist[i] = false;
			}
		}
		else {
			ret += search(startNum + 1, n, cnt, 0);
			break;
		}
	}
	return ret;
}
int solution(int n, int m)
{
	int ret = 0;


	for (int j = 0; j < n; ++j) {
		memset(isVist, false, sizeof(isVist));
		if (couples[0][j] == true) {
			isVist[0] = true;
			isVist[j] = true;
			couples[0][j] = false;
			couples[j][0] = false;
			ret += search(1, n, 2, 0);

		}
	}
	return ret;
}
int main()
{
	int C = 0;
	cin >> C;
	for (int i = 0; i < C; ++i) {
		int n = 0; //학생 수
		cin >> n;
		int m = 0;  //친구 쌍의 수
		cin >> m;
		memset(couples, false, sizeof(couples));
		for (int j = 0; j < m; ++j) {
			int a = 0, b = 0;
			cin >> a >> b;
			couples[a][b] = true;
			couples[b][a] = true;
		}
		int res = solution(n, m);
		cout << res << endl;
	}
}