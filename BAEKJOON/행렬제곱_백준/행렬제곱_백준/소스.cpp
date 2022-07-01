/*
https://www.acmicpc.net/problem/10830

그냥 하면 시간초과 난다.

A^4=A*A*A*A 이것보다.
A^4=A^2*A^2 이렇게 해야겠다.
곱셈 거듭제곱하듯이 해야겠다.
*/
#include <iostream>
#include <memory.h>
using namespace std;
int matrix[5][5];
int ret[5][5];
int N;



void matrxMul(int A[5][5], int B[5][5])
{
	int tmp_ret[5][5];
	//memset(tmp_ret, 0, sizeof(tmp_ret));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int tmp = 0;
			for (int k = 0; k < N; ++k)
			{
				tmp +=((A[i][k]%1000) * (B[k][j]%1000))%1000;
			}
			tmp_ret[i][j] = tmp%1000;

		}
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			A[i][j] = tmp_ret[i][j];
	}


}
void mul(long long n)
{


	while (n)
	{

		if (n & 1)
		{
			
			matrxMul(ret, matrix);

		}
		matrxMul(matrix, matrix);
		n /= 2;

	}

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long B = 0;
	cin >> N >> B;



	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			cin >> matrix[i][j];
			if (i == j)
				ret[i][j] = 1;
		}




	mul(B);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << ret[i][j] << ' ';
		}
		cout << endl;
	}
}