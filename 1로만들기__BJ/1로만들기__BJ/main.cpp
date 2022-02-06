#include <iostream>
#include <memory.h>
using namespace std;




int cache[1'000'000 + 1];



int main()
{
	int num = 0;
	cin >> num;

	for (int i = 2; i <= num; ++i)
	{
		cache[i] = cache[i - 1]+1;
		if (0 == i % 3) cache[i] = min(cache[i],cache[i / 3] + 1);
		if (0 == i % 2) cache[i] = min(cache[i], cache[i / 2] + 1);
	}

	cout << cache[num] << '\n';
}