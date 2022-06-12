//복습
#include <iostream>
#include <queue>
using namespace std;

char Map[1500][1500];
bool Visit[1500][1500];

constexpr char SWAN = 'L';
constexpr char WATER = '.';
constexpr char ICE = 'X';


//백조가 만나는지 검사!
//얼음 지우기
int targetX[2];
int targetY[2];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int R = 0, C = 0;
queue<pair<int, int>> water;
queue<pair<int, int>> next_water;
queue<pair<int, int>> swan;
queue<pair<int, int>> next_swan;

bool Range(int x, int y)
{
	if (x < 0 || x >= C)
		return false;
	if (y < 0 || y >= R)
		return false;

	if (Visit[y][x] == true)
		return false;

	return true;

}

bool SearchSwan()
{
	while (!swan.empty())
	{
		auto pos = swan.front();
		swan.pop();

		if (pos.first == targetX[1] && pos.second == targetY[1])
			return true;

		for (int i = 0; i < 4; ++i) {
			int newX = pos.first + dx[i];
			int newY = pos.second + dy[i];
			if (false == Range(newX, newY)) continue;
			if (Map[newY][newX] == ICE) {
				Visit[newY][newX] = true;
				next_swan.push({ newX,newY });
			}
			else if(Map[newY][newX]==WATER ){
				Visit[newY][newX] = true;
				swan.push({ newX, newY });
			}
		}

	}
	return false;
}

void EraseIce()
{
	while (!water.empty())
	{
		auto pos = water.front();
		water.pop();

		for (int i = 0; i < 4; ++i)
		{
			int newX = pos.first + dx[i];
			int newY = pos.second + dy[i];
			if (false == Range(newX, newY)) continue;
			if (Map[newY][newX] == ICE) {
				next_water.push({ newX,newY });
				Map[newY][newX] = WATER;
			}
		}

	}
}
int sol()
{
	int day = 0;
	swan.push({ targetX[0],targetY[0] });
	while (false == SearchSwan())
	{
		day++;
		//얼음 지우기
		EraseIce();
		water = next_water;
		swan = next_swan;
		next_water = queue<pair<int, int>>();
		next_swan = queue<pair<int, int>>();

	}
	return day;
}
int main()
{
	cin >> R >> C;
	int x = 0, y = 0;
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j) {
			cin >> Map[i][j];
			if (Map[i][j] == SWAN) {
				targetX[x++] = j;
				targetY[y++] = i;
				Map[i][j] = WATER;
				water.push({ j,i });
			}
			else if (Map[i][j] == WATER)
				water.push({ j,i });
		}

	cout << sol() << endl;
}