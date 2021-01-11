#include <iostream>
using namespace std;

int main()
{
	int N = 0; //ÀÔ·Â
	int cnt = 0;//ºÀÁö¼ö

	cin >> N;


	while (N > 0) {
		if (N % 5 == 0) {

			cnt = cnt+N / 5;
			N = N % 5;
			break;
		}
		N -= 3;
		cnt += 1;
	}
	if (N < 0)
		cout << -1;
	else
		cout << cnt << endl;

}