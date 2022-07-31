

#include <iostream>
#include<vector>
#include <memory.h>
using namespace std;

int R = 0, C = 0;


int cache[1000][1000];
int DFS(int y, int x,const vector<vector<int>>& board)
{
    if (y < 0 || y >= R || x < 0 || x >= C)
        return 0;

    int& ret = cache[y][x];
    if (cache[y][x] != -1)
        return cache[y][x];
  
    if (board[y][x] == 0)
        return ret =0;
    ret = 1;
    int a = DFS(y + 1, x, board),b= DFS(y, x + 1, board),c= DFS(y + 1, x + 1, board);

    
    int MIN= min(a, b);
    MIN = min(MIN, c);

    return ret = MIN+1;

}

int solution(vector<vector<int>> board)
{
    memset(cache, -1, sizeof(cache));
    int answer = 1234;
    R = board.size(); C = board[0].size();
    int MAX = 0;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j) {
            int w = DFS(i, j, board);
            MAX = max(MAX, w*w);
        }
    }

    return MAX;
}


