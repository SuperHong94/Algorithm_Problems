/*
https://algospot.com/judge/problem/read/ASYMTILING

1. 전체의 경우에서 대칭의 개수를 빼는게 빠를것인가?
2. 아니면 비대칭의 개수를 세는것이 빠를 것인가?
나올 수 있는 모양
ㅁ
ㅁ
or
ㅁㅁ
ㅁㅁ
이렇게 2개

1번 방법 전체의 개수를 알아야함
그리고 대칭의 개수를 알아야함
-> n의 반만큼만 가면 아는 거아님?

1번으로 한다.
전체개수 구하면서 반만큼만 갔을 때도 같이 구한다.



2번 방법 비대칭의 개수를 알아야함

*/


#include <iostream>
#include <memory.h>
using namespace std;

constexpr unsigned int MOD = 1000000007;
unsigned long long cache[101];

int N = 0;

int comp;


unsigned long long  sol3(int x)
{
	if (x < 0)
		return 0;
	if (x == 0)
		return 1;
	unsigned long long& ret = cache[x];
	if (ret != -1)
		return ret;




	return ret = (sol3(x - 1) + sol3(x - 2))%MOD;
}

int main()
{
	int C = 0; cin >> C;
	while (C--)
	{
		memset(cache, -1, sizeof(cache));

		cin >> N;
		int ret = 0;
		if ((N & 1) == 1)
			 ret = (sol3(N) - sol3(N/2)+MOD) % MOD;
		else{
			ret= (sol3(N) - sol3(N/2)+MOD) % MOD;
			ret = (ret - sol3(N / 2 - 1) + MOD) % MOD;
		}
			cout << ret << '\n';
	}
}



//#include <iostream>
//#include <memory.h>
//using namespace std;
//
//constexpr int MOD = 1000000007;
//unsigned long long cache[101];
//unsigned long long  half[51];
//int N = 0;
//
//int comp;
//unsigned long long  sol(int x)
//{
//	if (x > N)
//		return 0;
//
//	unsigned long long& ret = cache[x];
//	if (ret != -1)
//		return ret;
//	if (x == N)
//		return 1;
//
//
//
//	return ret = sol(x + 1) + sol(x + 2);
//}
//
//unsigned long long   sol2(int x)
//{
//
//	if (x > comp)
//		return 0;
//
//	unsigned long long& ret = half[x];
//	if (ret != -1)
//		return ret;
//	if (x == comp)
//		return 1;
//
//
//	return ret = sol2(x + 1) + sol2(x + 2);
//}
//
//int main()
//{
//	int C = 0; cin >> C;
//	while (C--)
//	{
//		memset(cache, -1, sizeof(cache));
//		memset(half, -1, sizeof(half));
//		cin >> N;
//		(N & 1) == 1 ? comp = N / 2 : comp = (N / 2) + 1;
//		unsigned long long   ret = (sol(0) - sol2(0)) % MOD;
//		cout << ret << '\n';
//	}
//}
//
