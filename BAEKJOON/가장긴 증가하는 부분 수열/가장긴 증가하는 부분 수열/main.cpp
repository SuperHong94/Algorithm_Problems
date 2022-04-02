#include <iostream>	
using namespace std;

int N = 0;
int arr[1000];
int cache[1000];


int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	for (int i = N - 1; i >= 0; --i) {
		cache[i] = 1;
		for (int j = i + 1; j < N; ++j) {
			if (arr[i] < arr[j])
				cache[i] = max(cache[i], cache[j] + 1);
		}

	}
	int MAX = 0;
	for (int i = 0; i < N; ++i)
		MAX = max(MAX, cache[i]);

	cout << MAX << endl;

}