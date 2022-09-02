#include <iostream>
#include <string>
#include <stack>
using namespace std;


bool sol(const string& s)
{
	stack<char> left;
	for (auto& c : s)
	{
		if (c == '(' || c == '[' || c == '{')
			left.push(c);
		else {
			if (left.empty() == true)
				return false;

			char compC = ' ';
			switch (left.top())
			{
			case '(':
				compC = ')';
				break;
			case '[':
				compC = ']';
				break;
			case '{':
				compC = '}';
				break;
			default:
				break;
			}
			if (compC != c)
				return false;
			left.pop();
		}
	}
	return left.empty();
}


int main()
{
	int T = 0; cin >> T;
	while (T--)
	{
		string word;
		cin >> word;
		sol(word)==true?cout<<"YES\n":cout<<"NO\n";
	}
}