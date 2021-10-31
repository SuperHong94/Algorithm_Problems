#include <iostream>
#include <string>
using namespace std;

string reverse(string::iterator& iter)
{
	char head = *iter;
	++iter;
	if (head!='x')
		return string{ head };

	string UL = reverse(iter);
	string UR = reverse(iter);
	string DL = reverse(iter);
	string DR = reverse(iter);
	return "x"+DL+DR+UL+UR;
}

int main()
{
	int C = 0; cin >> C;
	for (int i = 0; i < C; ++i)
	{
		string s; cin >> s;
		auto iter = s.begin();
		cout << reverse(iter) << endl;
	}
}