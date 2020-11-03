#include <iostream>
using namespace std;

int N;

void drawStar(int i, int j, int n);
int main()
{
	int r;
	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			drawStar(i, j, N);
		}
		cout << '\n';
	}




}



void drawStar(int i, int j, int n)
{
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
		cout << ' ';
	else
	{
		if (n / 3 == 0)
			cout << '*';
		else
			drawStar(i, j, n / 3);
	}
}
