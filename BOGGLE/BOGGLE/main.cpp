#include <iostream>
#include <vector>
#include <string>

using namespace std;
int solution(vector<string> inputs, string word, int x, int y, int wordN);
bool flag = false; 
void F(vector<string> inputs, string word)
{
	flag = false;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			int r = 0;
			r = solution(inputs, word, j, i, 0);
			if (r != 0)
			{
				cout << r;
				cout << word << " YES\n";
				return;
			}
		}
	}
	cout << word << " NO\n";
}
int solution(vector<string> inputs, string word, int x, int y, int wordN)
{
	if (wordN == word.size() - 1){
		flag = true;
		return 1;
	}
	if (x < 0 || x>5 || y < 0 || y>5)
		return 0;
	if (inputs[y][x] != word[wordN])
		return 0;
	else {
		int result = 0;
		if (x - 1 >= 0 && y - 1 >= 0) //ÁÂ»ó
		{ 
			result += solution(inputs, word, x - 1, y - 1, wordN + 1);
			if (flag)
				return result;
		}
		if (y - 1 >= 0) //»ó
			result += solution(inputs, word, x, y - 1, wordN + 1);
		if (flag)
			return result;
		if (x + 1 < 5 && y - 1 >= 0) //¿ì»ó
			result += solution(inputs, word, x + 1, y - 1, wordN + 1);
		if (flag)
			return result;
		if (x - 1 >= 0) //ÁÂ
			result += solution(inputs, word, x - 1, y, wordN + 1);
		if (flag)
			return result;
		if (x + 1 < 5) //¿ì
			result += solution(inputs, word, x + 1, y, wordN + 1);
		if (flag)
			return result;
		if (x - 1 >= 0 && y + 1 < 5) //ÁÂÇÏ
			result += solution(inputs, word, x - 1, y + 1, wordN + 1);
		if (flag)
			return result;
		if (y + 1 < 5) //ÇÏ
			result += solution(inputs, word, x, y +1, wordN + 1);
		if (flag)
			return result;
		if (x + 1 < 5 && y + 1 < 5) //¿ìÇÏ
			result += solution(inputs, word, x + 1, y + 1, wordN + 1);
		if (flag)
			return result;
		return result;
	}
}

int main()
{
	vector<string> inputs;
	int n = 0;
	cin >> n;

	int N = 0;
	string knownWord[10];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 5; ++j) {
			string tmp;
			cin >> tmp;
			inputs.emplace_back(tmp);
		}
		cin >> N;
		for (int k = 0; k < N; ++k) {
			cin >> knownWord[k];
			F(inputs, knownWord[k]);
		}


	}
}