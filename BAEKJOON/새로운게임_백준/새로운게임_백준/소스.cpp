#include <iostream>
#include <vector>
using namespace std;
constexpr int WHITE = 0;
constexpr int RED = 1;
constexpr int BLUE = 2;

int MAP[14][14];

constexpr int dirX[] = { 0,-1,1,0,0 };
constexpr int dirY[] = { 0,0,0,-1,1 };
int N = 0, K = 0;
enum DIR
{
	LEFT = 1, RIGHT, UP, DOWN
};
struct Node
{
	int x, y;
	int dir;
	int r = 1;
	Node* bottom = this;
	Node* top = this;

	Node* GetTop(int& cnt)
	{
		Node* temp = top;
		cnt = 0;
		while (temp != this) {
			temp = top->top;
			cnt++;
		}

		return top;
	}
	void DirChange()
	{
		r *= -1;
		Node* temp = top;
		while (temp != this) {
			temp = top->top;
			temp->r *= -1;
		}

	}
	Node* GetBottom()
	{
		Node* temp = bottom;
		while (temp != this)
			temp = bottom->bottom;

		return bottom;
	}
};
vector<Node> nodes;

int sol()
{

	int turn = 0;
	while (turn < 1000)
	{
		for (int i = 0; i < K; ++i)
		{
			if (nodes[i].bottom == nodes[i].GetBottom()) {
				int dir = nodes[i].dir;
				int nextX = nodes[i].x + (dirX[dir] * nodes[i].r);
				int nextY = nodes[i].y + (dirY[dir] * nodes[i].r);
				if (nextX <= 0 && nextX > N && nextY <= 0 && nextY > N)continue;

				switch (MAP[nextY][nextX])
				{
				case WHITE:
				{
					int cnt = 0;
					Node* temp = GetNode(i, nextX, nextY, cnt);
					if (temp != nullptr) {
						if (cnt == 3)
							return turn;
						temp->top = &nodes[i];
						nodes[i].bottom = temp;
					}
					nodes[i].x = nextX; nodes[i].y = nextY;
					break;
				}
				case RED:
				{
					int cnt = 0;
					Node* temp = GetNode(i, nextX, nextY, cnt);
					if (temp != nullptr) {
						temp->top = &nodes[i];
						nodes[i].bottom = temp;
					}
					nodes[i].x = nextX; nodes[i].y = nextY;
					nodes[i].DirChange();
					break;
				}
				break;
				case BLUE:
				{
					nodes[i].r *= -1;
					nextX = nodes[i].x + (dirX[dir] * nodes[i].r);
					nextY = nodes[i].y + (dirY[dir] * nodes[i].r);
					if (nextX <= 0 && nextX > N && nextY <= 0 && nextY > N)continue;
					if (MAP[nextY][nextX] == BLUE) continue;
					int cnt = 0;
					Node* temp = GetNode(i, nextX, nextY, cnt);
					if (temp != nullptr) {
						if (cnt == 3)
							return turn;
						temp->top = &nodes[i];
						nodes[i].bottom = temp;
					}
					nodes[i].x = nextX; nodes[i].y = nextY;
					break;

				}
					break;
				default:
					break;
				}
			}
		}
	}
	if (turn >= 1000)
		turn = -1;

	return  turn;
}
Node* GetNode(int id, int x, int y, int& cnt)
{
	for (int i = 0; i < K; ++i)
	{
		if (id == i)continue;
		if (nodes[id].x == nodes[i].x && nodes[id].y == nodes[i].y) {
			return nodes[i].GetTop(cnt);
		}

	}
	return nullptr;
}

int main()
{
	cin >> N >> K;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j) {
			cin >> MAP[i][j];
		}
	}

	nodes.resize(K);
	for (int i = 0; i < K; ++i)
	{
		cin >> nodes[i].x >> nodes[i].y >> nodes[i].dir;
	}

}