/*
https://algospot.com/judge/problem/read/ASYMTILING

1. ��ü�� ��쿡�� ��Ī�� ������ ���°� �������ΰ�?
2. �ƴϸ� ���Ī�� ������ ���°��� ���� ���ΰ�?
���� �� �ִ� ���
��
��
or
����
����
�̷��� 2��

1�� ��� ��ü�� ������ �˾ƾ���
�׸��� ��Ī�� ������ �˾ƾ���
-> n�� �ݸ�ŭ�� ���� �ƴ� �žƴ�?

1������ �Ѵ�.
��ü���� ���ϸ鼭 �ݸ�ŭ�� ���� ���� ���� ���Ѵ�.



2�� ��� ���Ī�� ������ �˾ƾ���

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
