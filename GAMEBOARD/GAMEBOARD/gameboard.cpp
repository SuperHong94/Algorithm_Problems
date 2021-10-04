//�˰��� ������ ����
/*

H* W ũ���� �������� �ֽ��ϴ�.�������� ���� ĭ�� �� ĭ���� ������ ���� ����� �ϰ� �ִµ� �� �� ��� �� ĭ�� 3ĭ¥�� L�� ����� ������� ���� �ͽ��ϴ�.�� �� ��ϵ��� �����Ӱ� ȸ���ؼ� ���� �� ������, ���� ��ġ�ų�, ���� ĭ�� ���ų�, ������ ������ �������� �� �˴ϴ�.�� �׸��� �� �����ǰ� �̸� ���� ����� �����ݴϴ�.

�������� �־��� �� �̸� ���� ����� ���� ����ϴ� ���α׷��� �ۼ��ϼ���.

�Է�
���� ù �ٿ��� �׽�Ʈ ���̽��� �� C(C <= 30) �� �־����ϴ�.�� �׽�Ʈ ���̽��� ù �ٿ��� 2���� ���� H, W(1 <= H, W <= 20) �� �־����ϴ�.���� H �ٿ� �� W ���ڷ� �������� ����� �־����ϴ�. # �� ���� ĭ, . �� �� ĭ�� ��Ÿ���ϴ�.�Է¿� �־����� �����ǿ� �ִ� �� ĭ�� ���� 50 �� ���� �ʽ��ϴ�.

���
�� �ٿ� �ϳ��� �� ĭ�� ��� ���� ����� ���� ����մϴ�.
*/
/// 
#include <iostream>
#include <memory.h>
using namespace std;

int H;
int W;

char BOARD[20][20]; //
/*
0. ���
#
##
1. ���
 #
##
2. ���
##
 #
3. ���
##
#
*/

int fill_0_Shape(int x, int y, int cnt);
int fill_1_Shape(int x, int y, int cnt);
int fill_2_Shape(int x, int y, int cnt);
int fill_3_Shape(int x, int y, int cnt);

int solution(int clearCnt);

int main()
{
	int C = 0; cin >> C; //test case�� ��
	int result = 0;

	for (int c = 0; c < C; ++c)
	{
		
		int clearCnt = 0;
		cin >> H; cin >> W;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				char tmp = ' ';
				cin >> tmp;
				if (tmp == '.')
					clearCnt += 1;
				BOARD[i][j] = tmp;
			}
		}
		result = solution(clearCnt);
		cout << result << endl;
	}

}

int  fill_0_Shape(int x, int y, int cnt)
{
	int result = 0;
	if (cnt == 0)
		return 1;
	//���� �˻�
	if (y + 1 >= H || x + 1 >= W)
		return 0;
	//���� �� �ִ� �ڸ����� �˻�
	if (BOARD[y][x] != '.' || BOARD[y + 1][x] != '.' || BOARD[y + 1][x + 1] != '.')
		return 0;


	BOARD[y][x] = '#';
	BOARD[y + 1][x] = '#';
	BOARD[y + 1][x + 1] = '#';



	//���� ��带 ��� �����ұ�? ���� 8����˻�?
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j) {
			if (BOARD[i][j] == '.') { //.�����°� �Ѱ����ϸ� �Ϸ�!
				result += fill_0_Shape(j, i, cnt - 3);
				result += fill_1_Shape(j, i, cnt - 3);
				result += fill_2_Shape(j, i, cnt - 3);
				result += fill_3_Shape(j, i, cnt - 3);
				BOARD[y][x] = '.';
				BOARD[y + 1][x] = '.';
				BOARD[y + 1][x + 1] = '.';
				if (cnt - 3 == 0)
					result += 1;
				return result;
	
			}
		}

}

int  fill_1_Shape(int x, int y, int cnt)
{
	int result = 0;
	if (cnt == 0)
		return 1;
	//���� �˻�
	if (y + 1 >= H || x - 1 >= W)
		return 0;
	//���� �� �ִ� �ڸ����� �˻�
	if (BOARD[y][x] != '.' || BOARD[y + 1][x] != '.' || BOARD[y + 1][x - 1] != '.')
		return 0;

	BOARD[y][x] = '#';
	BOARD[y + 1][x] = '#';
	BOARD[y + 1][x - 1] = '#';



	//���� ��带 ��� �����ұ�? ���� 8����˻�?
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j) {
			if (BOARD[i][j] == '.') { //.�����°� �Ѱ����ϸ� �Ϸ�!
				result += fill_0_Shape(j, i, cnt - 3);
				result += fill_1_Shape(j, i, cnt - 3);
				result += fill_2_Shape(j, i, cnt - 3);
				result += fill_3_Shape(j, i, cnt - 3);
				BOARD[y][x] = '.';
				BOARD[y + 1][x] = '.';
				BOARD[y + 1][x - 1] = '.';
				if (cnt - 3 == 0)
					result += 1;
				return result;
			}
		}


}

int fill_2_Shape(int x, int y, int cnt)
{
	int result = 0;
	if (cnt == 0)
		return 1;
	//���� �˻�
	if (y + 1 >= H || x + 1 >= W)
		return 0;
	//���� �� �ִ� �ڸ����� �˻�
	if (BOARD[y][x] != '.' || BOARD[y][x + 1] != '.' || BOARD[y + 1][x + 1] != '.')
		return 0;

	BOARD[y][x] = '#';
	BOARD[y][x + 1] = '#';
	BOARD[y + 1][x + 1] = '#';




	//���� ��带 ��� �����ұ�? ���� 8����˻�?
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j) {
			if (BOARD[i][j] == '.') { //.�����°� �Ѱ����ϸ� �Ϸ�!
				result += fill_0_Shape(j, i, cnt - 3);
				result += fill_1_Shape(j, i, cnt - 3);
				result += fill_2_Shape(j, i, cnt - 3);
				result += fill_3_Shape(j, i, cnt - 3);
				BOARD[y][x] = '.';
				BOARD[y][x + 1] = '.';
				BOARD[y + 1][x + 1] = '.';
				if (cnt - 3 == 0)
					result += 1;
				return result;
			}
		}
	//return result;
}

int fill_3_Shape(int x, int y, int cnt)
{
	int result = 0;
	if (cnt == 0)
		return 1;
	//���� �˻�
	if (y + 1 >= H || x + 1 >= W)
		return 0;
	//���� �� �ִ� �ڸ����� �˻�
	if (BOARD[y][x] != '.' || BOARD[y][x + 1] != '.' || BOARD[y + 1][x] != '.')
		return 0;

	BOARD[y][x] = '#';
	BOARD[y][x + 1] = '#';
	BOARD[y + 1][x] = '#';


	//���� ��带 ��� �����ұ�? ���� 8����˻�?
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j) {
			if (BOARD[i][j] == '.') { //.�����°� �Ѱ����ϸ� �Ϸ�!
				result += fill_0_Shape(j, i, cnt - 3);
				result += fill_1_Shape(j, i, cnt - 3);
				result += fill_2_Shape(j, i, cnt - 3);
				result += fill_3_Shape(j, i, cnt - 3);
				BOARD[y][x] = '.';
				BOARD[y][x + 1] = '.';
				BOARD[y + 1][x] = '.';


				if (cnt - 3 == 0)
					result += 1;
				return result;
			}
		}
	
}

int solution(int clearCnt)
{
	int result = 0;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (BOARD[i][j] == '.') { //.�����°� �Ѱ����ϸ� �Ϸ�!
				result += fill_0_Shape(j, i, clearCnt);
				result += fill_1_Shape(j, i, clearCnt);
				result += fill_2_Shape(j, i, clearCnt);
				result += fill_3_Shape(j, i, clearCnt);
				return result;
			}

		}
	}
	return result;
}
