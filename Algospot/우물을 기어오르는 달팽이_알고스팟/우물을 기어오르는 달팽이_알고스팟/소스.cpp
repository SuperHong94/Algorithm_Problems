#include <iostream>	
#include <memory.h>
using namespace std;

/*
* https://algospot.com/judge/problem/read/SNAIL
* ���̰� n�� �칰 �ǹؿ� �����̰� �ִ�.
* �񰡳����� �����̴� �Ϸ翡 2m �ö󰣴�.
* ���� ������ 1m �ö󰣴�.
* 
* m�ϰ� �� �ϸ��� ���Ȯ���� 75% m�Ͼȿ� �����̰� �칰������ �ö� Ȯ���� ����ϴ� ���Ϸ�
* 13�� 12��
* 0.75 0.75 0.75 
*/

constexpr float SUCESS = 0.75f;
constexpr float FAIL = 0.35f;
int N = 0, M = 0;
double cache[1001][1001 * 2];

double  solution(int d,int dis)
{
	if (d == M)
		return dis >=N? 1.0f : 0.0f;
	if (cache[d][dis] != -1.0f)
		return cache[d][dis];
	return cache[d][dis]=(0.75f * solution(d +1, dis + 2) + 0.25f * solution(d + 1, dis + 1));
}
int main()
{
	int C = 0; cin >> C;
	while (C--)
	{
		cin >> N >> M;
		for (int i = 0; i < 1001; ++i)
			for (int j = 0; j < 1001*2; ++j)
				cache[i][j] = -1.0f;

		printf("%.10lf\n", solution(0, 0));
	}

}