#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

/*
������ �ɰ� �� �ֳ�
�ڸ��� �߰�
+,-,*,/
https://programmers.co.kr/learn/courses/30/lessons/42895?language=cpp#
�̹������� dp�� �������� ������ ���ΰ��� ������� �̤�
dp�� �� dp[i]�� i���ؼ� ���� �� �ִ� ���� �־�ߵȴ�.
*/


unordered_set<int> cache[9];
int sol(int N, int number, int now, int cnt)
{
	if (cnt > 8)
		return  -1;




	if (now == number)
	{
		cache[cnt].insert(now);
		return now;
	}
	if (cache[cnt].count(now) != 0)
		return now;


	cache[cnt].insert(now);
	string s = to_string(N);

	for (int i = 1; i < 8; ++i) {


		sol(N, number, now + atoi(s.c_str()), cnt + i);

		sol(N, number, now - atoi(s.c_str()), cnt + i);

		sol(N, number, now * atoi(s.c_str()), cnt + i);

		sol(N, number, now / atoi(s.c_str()), cnt + i);
		s = s + to_string(N);
	}


	return now;

}


int solution(int N, int number) {
	int answer = 0;
	answer = sol(N, number, N, 1);


	for (int i = 1; i < 9; ++i)
	{
		if (cache[i].count(number) != 0)
			return i;
	}

	return -1;
}

int main()
{
	solution(8, 53);
}



//
//#include <vector>
//#include <algorithm>
//#include <iostream>
//#define MAX 8
//using namespace std;
//
//int gloN, res = MAX + 1;
//void dfs(int number, int curNum, int cnt) {
//	if (cnt > MAX) return;
//	else if (curNum == number) {
//		res = min(res, cnt);
//		return;
//	}
//	int n = 0;
//	for (int i = 1; i <= 6; i++) {
//		n = n * 10 + gloN;
//		dfs(number, curNum + n, cnt + i);
//		dfs(number, curNum - n, cnt + i);
//		if (curNum != 0) {
//			dfs(number, curNum * n, cnt + i);
//			dfs(number, curNum / n, cnt + i);
//		}
//	}
//}
//
//int solution(int N, int number) {
//	gloN = N;
//	dfs(number, 0, 0);
//	return (res == 9) ? -1 : res;
//}