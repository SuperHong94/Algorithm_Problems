#include <string>
#include <vector>

using namespace std;

int cache[500][500];
int sol(const vector<vector<int>>& triangle, int x, int y)
{
    if (y == triangle.size())
        return 0;
    int& ret = cache[y][x];
    if (ret != 0)
        return ret;

    return ret = max(sol(triangle, x, y + 1), sol(triangle, x + 1, y + 1)) + triangle[y][x];

}

int solution(vector<vector<int>> triangle) {
    int answer = sol(triangle, 0, 0);
    return answer;
}