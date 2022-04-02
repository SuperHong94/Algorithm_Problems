#include <iostream>
using namespace std;

int memo[100];


int fibo(int n)
{
	if (memo[n] != 0)
		return memo[n];
	else
		memo[n] = fibo(n - 2) + fibo(n - 1);
	return memo[n];
}

int main()
{
	memo[1] = 1;

	memo[2] = 1;
	
	fibo(9);

	cout << memo[9] << '\n';
}