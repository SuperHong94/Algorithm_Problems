#include <iostream>
#include <string>
using namespace std;
string s;
int cnt = 0;
int len = 0;
void solution(int b, int e);
int main()
{

	cin >> s;
	len = s.length();
	solution(0, len);
	cout << cnt;

}

void solution(int b, int e)
{
	int a = 0;
	int c = 0;
	if (s[0] == '0')
		a++;
	else
		c++;
	for (int i = 1; i < e; i++)
	{ 
		if (s[i] != s[i - 1]) {
			if (s[i] == '0')
				a++;
			else
				c++;
		}
	}


	cnt = (a < c ? a : c);
}