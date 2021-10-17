#include <iostream>
#include <vector>
using namespace std;

vector<int> SWITCHS[10];

int clocks[16];
const int MAX = 9999999;
void pushSwitch(int num)
{
	for (int t : SWITCHS[num]) {
		clocks[t] += 3;
		if (clocks[t] == 15)
			clocks[t] = 3;
	}
}
bool isFinish()
{
	for (int i = 0; i < 16; ++i)
	{
		if (clocks[i] != 12)
			return false;
	}
	return true;
}
int solution(int sw)
{
	if (sw == 10) { //끝까지 갔다
		if (isFinish()==true) {
			return 0;
		}
		return MAX;
	}
	int ret = MAX;

	for (int i = 0; i < 4; ++i) //4번 돌리기
	{
		ret = min(ret, i + solution(sw + 1));
		pushSwitch(sw);
	}
	return ret;
}
int main()
{
	SWITCHS[0] = { 0, 1, 2 };
	SWITCHS[1] = { 3, 7, 9, 11 };
	SWITCHS[2] = { 4, 10, 14, 15 };
	SWITCHS[3] = { 0, 4, 5, 6, 7 };
	SWITCHS[4] = { 6, 7, 8, 10, 12 };
	SWITCHS[5] = { 0, 2, 14, 15 };
	SWITCHS[6] = { 3, 14, 15 };
	SWITCHS[7] = { 4, 5, 7, 14, 15 };
	SWITCHS[8] = { 1, 2, 3, 4, 5 };
	SWITCHS[9] = { 3, 4, 5, 9, 13 };


	int C = 0; cin >> C;
	for (int c = 0; c < C; ++c) {

		for (int i = 0; i < 16; ++i)
			cin >> clocks[i];
		int ret = solution(0);
		if (ret == MAX)
			cout << -1 << endl;
		else
			cout << ret << endl;
	}
}