#include <iostream>
#include <memory.h>
#include <string>
using namespace std;


int cache[10005];
//3개로 끊었을때 ~5개로 끊었을때! 비교?

int Getlevel(const string& s)
{
	bool flag = true;
	for (int i = 1; i < s.size(); ++i) //level 1판별
	{
		if (s[i] != s[i - 1]) {
			flag = false;
			break;
		}
	}
	if (flag == true)
		return 1;

	flag = true;
	for (int i = 1; i < s.size(); ++i) //level 단조증가판별
	{
		if (s[i] - s[i - 1] != 1) {
			flag = false;
			break;
		}
	}
	if (flag == true)
		return 2;

	flag = true;
	for (int i = 1; i < s.size(); ++i) //level 단조감소판별
	{
		if (s[i] - s[i - 1] != -1) {
			flag = false;
			break;
		}
	}
	if (flag == true)
		return 2;

	flag = true;
	for (int i = 2; i < s.size(); ++i) //level 번갈아가면서
	{
		if (s[i] != s[i - 2]) {
			flag = false;
			break;
		}
	}
	if (flag == true)
		return 4;

	flag = true;
	/*int d = s[1] - s[0];
	for (int i = 2; i < s.size(); ++i) {
		if (s[i] != s[0] + (i * d)) {
			flag = false;
			break;
		}
	}*/
	int d = s[1] - s[0];
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] - s[i - 1] != d) {
			flag = false;
			break;
		}
	}

	if (flag == true)
		return 5;

	return 10;

}

int SIZE = 0;
int solv(const string& s, int index)
{
	if (s.size() ==0)
		return 0;
	if (cache[index] != 0)
		return cache[index];
	cache[index] = 99999;
	for (int i = 3; i <= 5; ++i)
	{
		if (s.size() < i) continue;
		string temp = s.substr(0, i);
		int level = Getlevel(temp);
		int ret = solv(s.substr(i), i + index);
		cache[index] = min(cache[index], level + ret);
	}
	return cache[index];



}


int main()
{
	int c; cin >> c;

	while (c--)
	{
		memset(cache, 0, sizeof(cache));
		string s;
		cin >> s;
		SIZE = s.size();
		cout << solv(s, 0) << '\n';
	}
}