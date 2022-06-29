/*
https://www.acmicpc.net/problem/10830

그냥 하면 시간초과 난다. 

A^4=A*A*A*A 이것보다.
A^4=A^2*A^2 이렇게 해야겠다.
곱셈 거듭제곱하듯이 해야겠다.
*/
#include <iostream>
using namespace std;
int matrix[5][5];

int N;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int B = 0;
	cin >> N >> B;

	int ret[5][5];

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			cin >> matrix[i][j];
			ret[i][j] = matrix[i][j];
		}


	for (int b = 1; b < B; ++b) {
		int tmp_ret[5][5];
		for (int i = 0; i < N; ++i)  
		{
			for (int j = 0; j < N; ++j)
			{
				int tmp = 0;
				for (int k = 0; k < N; ++k)
				{
					tmp += (ret[i][k] * matrix[k][j])%1000;
				}
				tmp_ret[i][j] = tmp%1000;

			}
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				ret[i][j]= tmp_ret[i][j];
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << ret[i][j] << ' ';
		}
		cout << endl;
	}

}