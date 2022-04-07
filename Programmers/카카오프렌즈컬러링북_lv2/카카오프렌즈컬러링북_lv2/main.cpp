#include <vector>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

int DFS(int y, int x, vector<vector<int>>& picture, int area) { //연결된영역 크기를 리턴한다.


	int dy[] = { -1,1,0,0 };
	int dx[] = { 0,0,-1,1 };

	int color = picture[y][x];
	picture[y][x] = 0;
	area += 1; //넓이 추가
	for (int i = 0; i < 4; ++i) {
		if (y + dy[i] < 0 || y + dy[i] >= picture.size() || x + dx[i] < 0 || x + dx[i] >= picture[0].size())
			continue;
		if (color == picture[y + dy[i]][x + dx[i]]) {
			area = DFS(y + dy[i], x + dx[i], picture, area);
		}
	}

	return area;

}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	bool flag = true;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (picture[i][j] != 0) {
				int ret = DFS(i, j, picture, 0);
				number_of_area += 1;
				max_size_of_one_area=max(max_size_of_one_area, ret);
				i = 0;
				j = 0;
			}

		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

int main()
{
	vector<int> answer = solution(6, 4, { {1, 1, 1, 0},{1, 2, 2, 0},{1, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 3},{0, 0, 0, 3} });
	int a = 10;
}