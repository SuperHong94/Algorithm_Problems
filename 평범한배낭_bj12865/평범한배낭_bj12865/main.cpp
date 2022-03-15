#include <iostream>
using namespace std;

int N;//������ ��
int K;//�賶�� �ִ� ����
int Weight[101];
int Value[101];

int cache[101][100000];
int main()
{
	cin >> N >> K;

	for (int i = 1; i <= N; ++i)
	{
		cin >> Weight[i] >> Value[i];//i��°���� ���Կ� ��ġ����
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j <= K; ++j)
		{
			if (Weight[i] <= j) {
				cache[i][j] = max(Value[i] + cache[i - 1][j - Weight[i]], cache[i - 1][j]);
			}
			else
				cache[i][j] = cache[i - 1][j];
		}
	}

	cout << cache[N][K] << endl;

}