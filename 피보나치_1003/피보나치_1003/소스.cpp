#include <iostream>
using namespace std;



int zeroCnt = 0;
int oneCnt = 0;
int zeroArr[41];
int oneArr[41];
void fibonacci(int n)
{
	if (n == 0) {
		zeroArr[0] = 1;
		zeroCnt += 1;
	}
	else if (n == 1) {
		oneArr[1] = 1;
		oneCnt += 1;
	}

	else if (zeroArr[n] != 0&& oneArr[n]!=0) {
		zeroCnt += zeroArr[n];
		oneCnt += oneArr[n];
	}
	else {
		fibonacci(n - 1); fibonacci(n - 2);
		zeroArr[n] = zeroArr[n - 1] + zeroArr[n - 2];
		oneArr[n] = oneArr[n - 1] + oneArr[n - 2];

	}
}
int main()
{
	int T = 0; cin >> T;
	while (T--)
	{
		int num = 0;
		cin >> num;
		fibonacci(num);
		cout << zeroCnt << ' ' << oneCnt << '\n';
		zeroCnt = 0;
		oneCnt = 0;
	}
}