//https://www.acmicpc.net/problem/2749
/*
그냥 하면 시간초과 뜬다 O(n)으로는 안된다.
O(log n) 정돈 되야한다.
그래서 행렬 멱법 사용한다.


*/

#include <iostream>
using namespace std;

const int MOD = 1000000;
typedef unsigned long long MAT[2][2];
unsigned long long matrix[2][2] = { {1,1},{1,0} };


void MatrixXMatrix(MAT a, MAT b)
{
	unsigned long long r00 = ((a[0][0] * b[0][0]) % MOD + (a[0][1] * b[1][0]) % MOD) % MOD;
	unsigned long long r01 = ((a[0][0] * b[0][1]) % MOD + (a[0][1] * b[1][1]) % MOD) % MOD;
	unsigned long long r10 = ((a[1][0] * b[0][0]) % MOD + (a[1][1] * b[1][0]) % MOD) % MOD;
	unsigned long long r11 = ((a[1][0] * b[0][1]) % MOD + (a[1][1] * b[1][1]) % MOD) % MOD;

	a[0][0] = r00; a[0][1] = r01;
	a[1][0] = r10; a[1][1] = r11;
}


void multipleMatrix(unsigned long long n)
{
	unsigned long long ret[2][2] = { {1,0},{0,1} };
	while (n)
	{
		if (n & 1)
			MatrixXMatrix(ret, matrix);

		MatrixXMatrix(matrix, matrix);

		n = n >> 1;

	}
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			matrix[i][j] = ret[i][j];
}
int main()
{
	unsigned long long N = 0; cin >> N;


	multipleMatrix(N);

	cout << matrix[1][0]<<endl;
}