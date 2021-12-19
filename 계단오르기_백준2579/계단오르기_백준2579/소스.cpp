#include <iostream>	

using namespace std;

int stairs[300];
int cache[300];

int N;

int solv(int end)
{



	if (end < 0)
		return 0;

	if (cache[end] != 0)
		return cache[end];

	return cache[end] = max(stairs[end] + solv(end - 2), stairs[end] + stairs[end - 1] + solv(end -3));
}

int main()
{

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> stairs[i];
	cout << solv(N-1);

}