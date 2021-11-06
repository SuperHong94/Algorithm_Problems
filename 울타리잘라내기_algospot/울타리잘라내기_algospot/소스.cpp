#include <iostream>

using namespace std;

int HEIGHT[20000];
int N = 0;
int GetArea(int index)
{
	int h = HEIGHT[index];
	int area = 0;
	//ÀÚ±â ±âÁØ ¿ÞÂÊ²¨ ¿À¸¥ÂÊ ³ÐÀÌ ´õÇÏ±â!
	for (int i = index; i >= 0; --i)
	{
		if (HEIGHT[i] < h)
			break;
		area += h;
	}

	for (int i = index; i <N; ++i)
	{
		if (HEIGHT[i] < h)
			break;
		area += h;
	}

	area -= h;
	return area;
}
int main()
{
	int C = 0; cin >> C;

	for (int j = 0; j < C; ++j) {
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			cin >> HEIGHT[i];
		}

		int MAX = 0;
		for (int i = 0; i < N; ++i)
		{
			MAX = max(MAX, GetArea(i));
		}
		cout << MAX << '\n';
	}
}