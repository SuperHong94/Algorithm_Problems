#include <iostream>

using namespace std;

int w = 0;
int h = 0;
int myMap[50][50];
bool isMap[50][50];

int cnt = 0;

void search(int y, int x);
int main()
{


	while (true) {
		for (int i = 0; i < 50; ++i)
			for (int j = 0; j < 50; ++j) {
				myMap[i][j] = 0;
				isMap[i][j] = false;
			}
		cnt = 0;
		std::cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				cin >> myMap[i][j];

		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j) {
				if (myMap[i][j] == 1 && isMap[i][j] == false) {
					cnt += 1;
					search(i, j);
				}
			}
		cout << cnt << endl;
	}
}

void search(int y, int x)
{
	if (y < 0 || y == h || x < 0 || x == w)
		return;
	if (myMap[y][x] == 0) {
		return;
	}
	else
		isMap[y][x] = true;




	if (y - 1 >= 0 && x - 1 >= 0) //аб╩С
	{
		if (!isMap[y - 1][x - 1])
			search(y - 1, x - 1);
	}
	if (y - 1 >= 0)   //╩С
		if (!isMap[y - 1][x])
			search(y - 1, x);


	if (y - 1 >= 0&& x + 1 < w) //©Л╩С
		if (!isMap[y -1][x + 1])
			search(y - 1, x + 1);


	if (x - 1 >= 0) //аб
		if (!isMap[y][x - 1])
			search(y, x - 1);


	if (x + 1 < w)//©Л
		if (!isMap[y][x + 1])
			search(y, x + 1);

	if (y + 1 < h && x - 1 >= 0)
		if (!isMap[y + 1][x - 1])
			search(y + 1, x - 1);

	if (y + 1 < h)
		if (!isMap[y + 1][x])
			search(y + 1, x);

	if (y + 1 < h && x + 1 < w)
		if (!isMap[y + 1][x + 1])
			search(y + 1, x + 1);

}

