#include <iostream>

using namespace std;



int MaxNum = 0;
int MinNum = 1000;
int numbers[101];
int main()
{
	int C = 0;
	cin >> C;
	int N = 0, S = 0;
	cin >> N >> S;

	for (int i = 0; i < N; ++i)
	{
		cin >> numbers[i];
		MaxNum = max(MaxNum, numbers[i]);
		MinNum = min(MinNum, numbers[i]);
	}

}