#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	int N = board.size();
	vector<int> basket;
	//뽑기 basket에 넣기
	for (const int target : moves) {
		for (int i = 0; i < N; ++i) {
			if (board[i][target-1] != 0) {
				basket.push_back(board[i][target-1]); //바구니에 넣기;
				board[i][target-1] = 0;
				//연속되는지 검사
				if (basket.size() >=2) {
					/*	if (basket[basket.size() - 1] == basket[basket.size() - 2]) {*/
					if (*(basket.end() - 1) == *(basket.end() - 2)) {
						basket.pop_back();
						basket.pop_back();
						answer += 2;
					}
				}
				break;
			}
		}

		
	}

	return answer;
}

int main()
{
	solution({ {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} }, { 1, 5, 3, 5, 1, 2, 1, 4 });
}