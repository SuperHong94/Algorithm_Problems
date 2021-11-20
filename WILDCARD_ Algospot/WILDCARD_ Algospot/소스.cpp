#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <chrono>
#include <memory.h>
using namespace std;
using namespace chrono;
bool solution(const string& s, const string& ss)
{
	if (s.size() == 0 && ss.size() == 0)
		return true;
	if (s.size() == 0 || ss.size() == 0)
		return false;

	if (s[0] == '?' || s[0] == ss[0])
		return solution(s.substr(1), ss.substr(1));
	else {
		if (s[0] == '*') {
			int k = 0;
			for (k; k < s.size(); ++k) {
				if (s[k] != '*')
					break;
			}
			if ((k == s.size()) == true)
				return true;
			if (s.back() == '*')
				for (int i = 0; i < ss.size(); ++i) {
					if (s[k] == ss[i]) {
						return solution(s.substr(k), ss.substr(i));
					}
				}
			return false;
		}
		else
			return false;
	}

}

bool solution2(const string& w, const string& s)  //중복문제 발생
{
	int pos = 0;
	while (pos < w.size() && pos < s.size() && (w[pos] == '?' || w[pos] == s[pos]))
		pos++;

	if (pos == w.size()) //*만나지않고 끝난것이다.
		return pos == s.size();

	//*을 만난 경우
	if (w[pos] == '*')
		for (int skip = 0; pos + skip <= s.size(); ++skip)
			if (solution2(w.substr(pos + 1), s.substr(pos + skip)))
				return true;
	return false;
}


int cache[101][101];
string S, W;
bool solution3(int w, int s)
{
	int& ret = cache[w][s];
	if (ret != -1)return ret;
	while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
		w++;
		s++;
	}
	if (w == W.size())
		return ret = (s == S.size());

	if (W[w] == '*')
		for (int skip = 0; skip + s <= S.size(); ++skip)
			if (solution3(w + 1, s + skip))
				return ret = 1;
	return ret = 0;
}

bool solution4(int w, int s)
{
	int& ret = cache[w][s];
	if (ret != -1)return ret;
	while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
		return ret=solution4(w + 1, s + 1);
	}
	if (w == W.size())
		return ret = (s == S.size());

	if (W[w] == '*')
		if (solution4(w + 1, s)||(s<S.size()&&solution4(w,s+1)))
			return ret = 1;
	return ret = 0;
}
int main()
{
	int C = 0; cin >> C;
	string s;
	int N = 0;

	for (int c = 0; c < C; ++c) {
		vector<string> ret;

		//cin >> s;
		cin >> W;
		cin >> N;

		//auto start = system_clock::now();
		for (int i = 0; i < N; ++i) {
			//string ss;
			//cin >> ss;
			memset(cache, -1, sizeof(cache));
			cin >> S;
			if (solution4(0, 0) == true)
				ret.emplace_back(S);
		}
		sort(ret.begin(), ret.end());
		//auto end = system_clock::now();
		//cout << "----------------------\n";
		//cout << "duration time : " << duration_cast<milliseconds>(end - start).count() << '\n';
		for (const auto& r : ret)
			cout << r << '\n';
		//cout << "----------------------\n";

	}
}