#include <iostream>
#include <vector>
using namespace std;
constexpr int MAX = 99999999;
vector<int> switchs[10];
int switchCnt[10];
int clocks[16];
int MIN = MAX;
void PlusTime(int index) //index�� ��ġ�� ����ġȿ���� ����
{
	for (const int& n : switchs[index]) {
		if (clocks[n] == 12) {
			clocks[n] = 3;
		}
		else
			clocks[n] += 3;
	}


}
void MinusTime(int index)
{
	for (const int& n : switchs[index]) {
		if (clocks[n] == 3) {
			clocks[n] = 12;
		}
		else
			clocks[n] -= 3;
	}

}
void solution(int cnt) //cnt�� ���� Ƚ��
{
	bool flag = false;

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 4; ++j) {
			solution(cnt + 1);

		}
	}
}

//���� �Լ�
int solve(int sw)//sw�� ����ġ 0~9�� 4���� ������ ������.
{
	if (sw == 10) {
		bool flag = true;
		for (const int& c : clocks) {
			if (c != 12) {
				flag = false;
				break;
			}
		}
		return flag ? 0 : MAX;
	}
	int ret = MAX;
	for (int cnt = 0; cnt < 4; ++cnt) {//������ 4���� ���� ������� ���ƿ´�.

		ret = min(ret, cnt + solve(sw + 1));
		PlusTime(sw);

	}
	return ret;
}
int main()
{
	switchs[0] = { 0,1,2 };
	switchs[1] = { 3, 7, 9, 11 };
	switchs[2] = { 4, 10, 14, 15 };
	switchs[3] = { 0, 4, 5, 6, 7 };
	switchs[4] = { 6, 7, 8, 10, 12 };
	switchs[5] = { 0, 2, 14, 15 };
	switchs[6] = { 3, 14, 15 };
	switchs[7] = { 4, 5, 7, 14, 15 };
	switchs[8] = { 1, 2, 3, 4, 5 };
	switchs[9] = { 3, 4, 5, 9, 13 };

	int C = 0; cin >> C;
	for (int c = 0; c < C; ++c)
	{
		for (int i = 0; i < 16; ++i) {
			cin >> clocks[i];
		}
		//solution(0);
		//cout << MIN << endl;
		if (solve(0) == MAX)
			cout << -1 << endl;
		else
			cout << solve(0) << endl;
	}

}