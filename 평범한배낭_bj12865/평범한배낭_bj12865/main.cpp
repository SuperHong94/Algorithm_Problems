#include <iostream>
using namespace std;

int N;//물건의 수
int K;//배낭의 최대 무게
int Weight[101];
int Value[101];

int cache[101][100000];
int main()
{
	cin >> N >> K;

	for (int i = 1; i <= N; ++i)
	{
		cin >> Weight[i] >> Value[i];//i번째물건 무게와 가치설정
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