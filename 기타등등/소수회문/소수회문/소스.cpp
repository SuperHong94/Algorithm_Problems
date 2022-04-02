#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


bool isPrime(int n)
{
	if (n == 1)
		return false;
	for (int i = 2; i < n; ++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}
bool IsPalindrom(int n)
{
	string num = to_string(n);
	string rev = num;
	reverse(rev.begin(), rev.end());
	for (int i = 0; i < num.size(); ++i)
	{
		if (num[i] != rev[i])
			return false;
	}
	return isPrime(n);
}






int main()
{
	int N = 0; cin >> N;
	while (true) {
	
			if (IsPalindrom(N)) {
				cout << N;
				break;
			}
			N++;
	
	}

}