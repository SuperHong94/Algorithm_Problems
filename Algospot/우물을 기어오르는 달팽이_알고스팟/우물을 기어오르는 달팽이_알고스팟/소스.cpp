#include <iostream>	

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
float  solution(int n,int m)
{
	if (n <=0)
		return 1.0f;
	if (m == 0)
		return 1.0f;

	return (0.75f * solution(n - 2, m - 1) + 0.25f * solution(n - 1, m - 1));
}
int main()
{
	int C = 0; cin >> C;
	while (C--)
	{
		cin >> N >> M;
	}

}