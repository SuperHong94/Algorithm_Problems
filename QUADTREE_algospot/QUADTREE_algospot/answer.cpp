//쿼드 트리 뒤집기 정답
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
using namespace std;
constexpr int MAXSIZE = 1000;
char decompressed[MAXSIZE][MAXSIZE];

void decompress(string::iterator& it, int y, int x, int size) //s를 압축해제하여 decompressed구간에 쓴다.
{
	char head = *(it++);
	if (head == 'b' || head == 'w') {
		for (int dy = 0; dy < size; ++dy) {
			for (int dx = 0; dx < size; ++dx) {
				decompressed[y + dy][x + dx] = head;
			}
		}
	}
	else {
		int half = size / 2;
		decompress(it, y, x, half);
		decompress(it, y, x + half, half);
		decompress(it, y + half, x, half);
		decompress(it, y + half, x + half, half);
	}
}

string reverse(string::iterator& it)
{
	char head = *it;
	++it;
	if (head == 'b' || head == 'w')
		return string(1, head);
	string UL = reverse(it);
	string UR = reverse(it);
	string LL = reverse(it);
	string LR = reverse(it);

	return "x" + LL + LR + UL + UR;
}

int main()
{
	int C = 0; cin >> C;
	for (int i = 0; i < C; ++i)
	{
		string s;
		cin >> s;
		string result;

		auto it = s.begin();
		result = reverse(it);

		cout << result << endl;
		//cout << s << endl;
	}
}