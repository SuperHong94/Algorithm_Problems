//https://www.acmicpc.net/problem/9376
//�̵��Ÿ��� �ƴ� ������ ���� ������ �ٽ��̴�.
/*
	�ʺ��� w�� h�� 1���� ������ �����غ���.
	�ֳ� �̷��Ծ��ϸ� �ֺ��׵θ� �ϳ��� �� �˻��ؾ���
	�̷��� �ϴ°� ������ ������ �ִܰŸ� ���ϴ� ���̾ƴ϶� �������� ���ϴ� ���̱� ����!

	�׳� ť���� �޸� �ʰ�����. �׷��� deque�� ���༭ �պκп��� ����� �޺κп� ������������� ���� ������ �־���. 
	�̷����ϸ� �������������� �ٽ� ���ȿ��� ��������� ��� �Ƚᵵ �ȴ�.
*/


#include <iostream>
#include <queue>
#include <deque>
using namespace std;

constexpr char BLANK = '.';
constexpr char WALL = '*';
constexpr char PRISONER = '$';
constexpr int MAX = 123456789;

char Prison[102][102];

int people[3][102][102];
int h, w;

int main()
{
	int T = 0; cin >> T;
	while (T--)
	{
		cin >> h >> w;
		for (int i = 0; i < h + 2; ++i) {
			for (int j = 0; j < w + 2; ++j)
				Prison[i][j] = '.';
		}
		for (int k = 0; k < 3; ++k)
		{
			for (int i = 0; i < h + 2; ++i) {
				for (int j = 0; j < w + 2; ++j)
					people[k][i][j] = MAX;
			}
		}

		deque<pair<int, int>> q[3];
		q[0].push_front({ 0, 0 });
		{
			int index = 1;
			for (int i = 0; i < h; ++i) {
				for (int j = 0; j < w; ++j) {
					cin >> Prison[i + 1][j + 1];
					if (Prison[i + 1][j + 1] == PRISONER) {
						q[index].push_front({ i + 1, j + 1 });
						index++;
						Prison[i + 1][j + 1] = BLANK;
					}
				}
			}
		}
		int dx[] = { 0,0,-1,1 };
		int dy[] = { -1,1,0,0 };
		for (int i = 0; i < 3; ++i) {
			auto spos = q[i].front();
			people[i][spos.first][spos.second] = 0;
			while (q[i].empty() == false)
			{
				auto pos = q[i].front(); q[i].pop_front();
				int cur_y = pos.first, cur_x = pos.second;
				for (int d = 0; d < 4; ++d) {
					int newY = cur_y + dy[d], newX = cur_x + dx[d];
					if (newY < 0 || newY > h+1 || newX < 0 || newX > w+1) continue;// ���� ��
					if (Prison[newY][newX] == WALL || people[i][newY][newX] != MAX)continue;
					if (Prison[newY][newX] == '#')
					{
						people[i][newY][newX] = people[i][cur_y][cur_x] + 1;
						q[i].push_back({ newY,newX });
					}
					else if (Prison[newY][newX] == BLANK) {
						people[i][newY][newX] = people[i][cur_y][cur_x];
						q[i].push_front({ newY,newX });
					}
					
				}

			}

		}

		int ret = MAX;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (Prison[i + 1][j + 1] == WALL) continue;
				int people_sum = people[0][i + 1][j + 1] + people[1][i + 1][j + 1] + people[2][i + 1][j + 1];
				if (Prison[i + 1][j + 1] == '#') {
					people_sum -= 2;
				}

				ret = min(ret, people_sum);

			}
		}
		cout << ret << '\n';

	}
}