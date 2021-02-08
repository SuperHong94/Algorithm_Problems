#include <iostream>
#include <vector>
using namespace std;

//�־��� ĭ�� ���� �� �ִ� �� ���� ���
//������ �����ϴ� �� ĭ�� ����� ��ġ(dy,dx)�� ���
const int coverType[4][3][2] =
{
	{{0,0},{1,0},{0,1}}, //��
	{{0,0},{0,1},{1,1}},// ��
	{{0,0},{1,0},{1,1}}, //��
	{{0,0},{1,0},{1,-1}} //��
};
//board��(y,x)�� type�� ������� ���ų�, ������ ������ ���ش�.
//delta=1�̸� ����, -1�̸� ������ ������ ���ش�.
//����  ������ ����� ������ ���� ��� (������ ������ �����ų�, ��ġ�ų�, ���� ĭ�� ���� ��) false�� ��ȯ�Ѵ�.

bool set(vector<vector<int>>& board, int y, int x, int type, int delta)
{
	bool ok = true;
	for (int i = 0; i < 3; ++i) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
			ok = false;
		else if ((board[ny][nx] += delta) > 1)
			ok = false;
	}
	return ok;
}

//board�� ��� ��ĭ�� ���� �� �ִ� ����� ���� ��ȯ�Ѵ�.
//board[i][j]=1 �̹� ���� ĭ Ȥ�� ����ĭ
//board[i][j]=0 ���� ������ ����ĭ

int cover(vector<vector<int>>& board) {
	//���� ä���� ���� ĭ �� ���� ���� ���ʿ� �ִ� ĭ�� ã�´�.
	int y = -1; int x = -1;
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[i].size(); ++j)
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		if (y != 1)
			break;
	}
	//���� ���: ��� ĭ�� ä������ 1�� ��ȯ�Ѵ�.
	if (y == -1)
		return 1;
	int ret = 0;
	for (int type = 0; type < 4; ++type) {
		//���� board[y][x]�� type���·� ���� �� ������ ��� ȣ���Ѵ�.
		if (set(board, y, x, type, 1))
			ret += cover(board);
		//������ ������ ġ���.
		set(board, y, x, type, -1);
	}
	return ret;
}

int main() {
	int H, W;
	int t;
	char c;
	cin >> t;
	vector<vector<int>> board;
	for (int testcase = 0; testcase < t; testcase++) {
		cin >> H >> W;
		board.resize(H);
		for (int i = 0; i < H; i++) {
			board[i].resize(W);
			for (int j = 0; j < W; j++) {
				cin >> c;
				c == '#' ? board[i][j] = 1 : board[i][j] = 0;
			}
		}
		cout << cover(board) << '\n';
	}

	return 0;
}