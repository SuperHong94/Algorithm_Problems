#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <array>

using namespace std;

char words[5][5];
bool memory[5][5][10];
constexpr int dx[8] = { -1,0,1,-1,1,-1,0,1 };
constexpr int dy[8] = { -1,-1,-1,0,0,1,1,1 };

bool findWord(const string& word, int y, int x, int wordN)
{
	
	if (x < 0 || y < 0 || x >=5 || y >= 5)
		return false;
	memory[y][x][wordN] = false; //이미 방문
	if (words[y][x] != word[wordN]) {
		return false;
	}

	if (word.size()-1 == wordN)
		return true;
	for (int i = 0; i < 8; ++i) {
		if (memory[y + dy[i]][x + dx[i]][wordN + 1])
			if (findWord(word, y + dy[i], x + dx[i], wordN + 1))
				return true;
	}
	return false;
}

bool solution(const string& word)
{

	memset(memory, true, sizeof(memory));
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (findWord(word, i, j, 0))
				return true;
		}
	}
	return false;
}
int main()
{
	int C = 0;
	cin >> C;


	for (int caseN = 0; caseN < C; ++caseN) {
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				cin >> words[i][j];
			}
		}

		int N = 0;//알고있는 단어의 수
		cin >> N;
		string arr[10];
		for (int i = 0; i < N; ++i) {
			cin >> arr[i];

		}

		for (int i = 0; i < N; ++i) {
			cout << arr[i];
			if (solution(arr[i]))
				cout << " YES\n";
			else
				cout << " NO\n";
		}
	}
}
