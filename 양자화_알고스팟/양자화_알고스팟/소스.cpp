#include <iostream>

using namespace std;


int numbers[101];
int main()
{
	int c = 0; cin >> c;
	while (c--)
	{
		int n = 0; cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> numbers[i];
	}
}