//알고스팟 보드판 덮기
/*

H* W 크기의 게임판이 있습니다.게임판은 검은 칸과 흰 칸으로 구성된 격자 모양을 하고 있는데 이 중 모든 흰 칸을 3칸짜리 L자 모양의 블록으로 덮고 싶습니다.이 때 블록들은 자유롭게 회전해서 놓을 수 있지만, 서로 겹치거나, 검은 칸을 덮거나, 게임판 밖으로 나가서는 안 됩니다.위 그림은 한 게임판과 이를 덮는 방법을 보여줍니다.

게임판이 주어질 때 이를 덮는 방법의 수를 계산하는 프로그램을 작성하세요.

입력
력의 첫 줄에는 테스트 케이스의 수 C(C <= 30) 가 주어집니다.각 테스트 케이스의 첫 줄에는 2개의 정수 H, W(1 <= H, W <= 20) 가 주어집니다.다음 H 줄에 각 W 글자로 게임판의 모양이 주어집니다. # 은 검은 칸, . 는 흰 칸을 나타냅니다.입력에 주어지는 게임판에 있는 흰 칸의 수는 50 을 넘지 않습니다.

출력
한 줄에 하나씩 흰 칸을 모두 덮는 방법의 수를 출력합니다.
*/
/// 
#include <iostream>
#include <memory.h>
using namespace std;

int H;
int W;

char BOARD[20][20]; //
/*
0. 모양
#
##
1. 모양
 #
##
2. 모양
##
 #
3. 모양
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
	int C = 0; cin >> C; //test case의 수
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
	//범위 검사
	if (y + 1 >= H || x + 1 >= W)
		return 0;
	//넣을 수 있는 자리인지 검사
	if (BOARD[y][x] != '.' || BOARD[y + 1][x] != '.' || BOARD[y + 1][x + 1] != '.')
		return 0;


	BOARD[y][x] = '#';
	BOARD[y + 1][x] = '#';
	BOARD[y + 1][x + 1] = '#';



	//다음 노드를 어떻게 가야할까? 블럭당 8방향검사?
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j) {
			if (BOARD[i][j] == '.') { //.나오는곳 한곳만하면 완료!
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
	//범위 검사
	if (y + 1 >= H || x - 1 >= W)
		return 0;
	//넣을 수 있는 자리인지 검사
	if (BOARD[y][x] != '.' || BOARD[y + 1][x] != '.' || BOARD[y + 1][x - 1] != '.')
		return 0;

	BOARD[y][x] = '#';
	BOARD[y + 1][x] = '#';
	BOARD[y + 1][x - 1] = '#';



	//다음 노드를 어떻게 가야할까? 블럭당 8방향검사?
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j) {
			if (BOARD[i][j] == '.') { //.나오는곳 한곳만하면 완료!
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
	//범위 검사
	if (y + 1 >= H || x + 1 >= W)
		return 0;
	//넣을 수 있는 자리인지 검사
	if (BOARD[y][x] != '.' || BOARD[y][x + 1] != '.' || BOARD[y + 1][x + 1] != '.')
		return 0;

	BOARD[y][x] = '#';
	BOARD[y][x + 1] = '#';
	BOARD[y + 1][x + 1] = '#';




	//다음 노드를 어떻게 가야할까? 블럭당 8방향검사?
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j) {
			if (BOARD[i][j] == '.') { //.나오는곳 한곳만하면 완료!
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
	//범위 검사
	if (y + 1 >= H || x + 1 >= W)
		return 0;
	//넣을 수 있는 자리인지 검사
	if (BOARD[y][x] != '.' || BOARD[y][x + 1] != '.' || BOARD[y + 1][x] != '.')
		return 0;

	BOARD[y][x] = '#';
	BOARD[y][x + 1] = '#';
	BOARD[y + 1][x] = '#';


	//다음 노드를 어떻게 가야할까? 블럭당 8방향검사?
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j) {
			if (BOARD[i][j] == '.') { //.나오는곳 한곳만하면 완료!
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
			if (BOARD[i][j] == '.') { //.나오는곳 한곳만하면 완료!
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
