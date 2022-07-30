

#include <iostream>
#include<vector>
#include <memory.h>
using namespace std;

int R = 0, C = 0;
int GetMaxArea(int y, int x, const vector<vector<int>>& board) //이걸로 풀면 효율성 탈락함
{
    int area = 0;
    for (int i = 1;; ++i)
    {
        for (int dy = 0; dy < i; ++dy) {
            for (int dx = 0; dx < i; ++dx) {
                if (dy + y >= R || dx + x >= C)
                    return area;
                if (board[dy + y][dx + x] == 0)
                    return area;
            }
        }
        area = i * i;
    }

}

int solution(vector<vector<int>> board)
{
    int answer = 1234;
    R = board.size(); C = board[0].size();
    int MAX = 0;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j) {
            MAX = max(MAX, GetMaxArea(i, j, board));
        }
    }

    return MAX;
}