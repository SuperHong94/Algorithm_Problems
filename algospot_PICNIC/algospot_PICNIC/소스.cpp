#include <iostream>	
#include <vector>
#include <memory.h>
using namespace std;

bool couples[10][10];
bool people[10];
int search(int n, int cnt)
{
	if (cnt >= n)
		return 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
		}
	}
}
int solution(int n)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {

		}
	}
	
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
		int res = solution(n);

	}
}