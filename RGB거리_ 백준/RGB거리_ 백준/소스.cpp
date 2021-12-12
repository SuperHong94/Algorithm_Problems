#include <iostream>

using namespace std;

enum COLOR :int
{
	RED = 0, BLUE, GREEN
};

int RGB[3][1000];
int cache[3][1000];

int F(int n, COLOR cur)
{
	if (n == -1)
		return 0;
	if (cache[cur][n] != 0)
		return cache[cur][n];
	switch (cur)
	{
	case RED: {
		int B = F(n - 1, BLUE);
		int G = F(n - 1, GREEN);
		return B < G ? cache[cur][n] = RGB[RED][n] + B : cache[cur][n] = RGB[RED][n] + G;
		break;
	}
	case BLUE:
	{
		int R = F(n - 1, RED);
		int G = F(n - 1, GREEN);
		return R < G ? cache[cur][n] = RGB[BLUE][n] + R : cache[cur][n] = RGB[BLUE][n] + G;
		break;
	}
	case GREEN:
	{
		int R = F(n - 1, RED);
		int B = F(n - 1, BLUE);
		return R < B ? cache[cur][n] = RGB[GREEN][n] + R : cache[cur][n] = RGB[GREEN][n] + B;
		break;
	}

	}
}
int main()
{
	int n = 0; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> RGB[RED][i] >> RGB[BLUE][i] >> RGB[GREEN][i];
	}

	int MIN = 9999999;
	for (int i = 0; i < 3; ++i)
	{
		F(n - 1, (COLOR)i);
		MIN = min(MIN, cache[(COLOR)(i)][n - 1]);
	}
	cout << MIN;
}