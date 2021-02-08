#include <iostream>
#include <chrono>

using namespace std;
int fastSum(int n)
{
	if (n == 1)return 1;
	if (n % 2 == 1)return fastSum(n - 1) + n;
	return 2 * fastSum(n / 2) + (n / 2) * (n / 2);
}

int recusiveSum(int n)
{
	if (n == 1)return 1;
	return n + recusiveSum(n - 1);
}

int main()
{
	int n = 3;
	auto start = chrono::system_clock::now();
	fastSum(n);
	auto sec = chrono::system_clock::now() - start;
	cout << sec.count() << "s" << endl;


	start = chrono::system_clock::now();
	recusiveSum(n);
	sec = chrono::system_clock::now() - start;
	cout << sec.count() << "s" << endl;

}