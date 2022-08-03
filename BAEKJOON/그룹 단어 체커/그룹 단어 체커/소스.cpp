//https://www.acmicpc.net/problem/1316

#include <iostream>
#include <memory.h>
#include <string>

using namespace std;

bool abc[26];
int main()
{

	int ret = 0;
	int N = 0; cin >> N;
	while (N--)
	{
		memset(abc, 0, sizeof(abc));

		string word;
		cin >> word;

		char cur = word[0];

		abc[cur - 'a'] = true;
		bool flag = true;
		for (int i = 1; i < word.size(); ++i) {
			if (word[i] != cur) {
				if (abc[word[i] - 'a'] == true) {
					flag = false;
					break;
				}
				abc[word[i] - 'a'] = true;
				cur = word[i];
			}
		}
		if (flag == true)
			ret += 1;
	}

	cout << ret;

}