//https://algospot.com/judge/problem/read/NERD2
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

/*
시간초과 난다.
NlongN인데 왜 ?
그럼 longN의 복잡도를 가져야되는데?
트리가 사향의 형태에 가까워 져서 N^2의 되는거면?
->레드블랙 구현할꺼아니면 걍 있는거 쓰자
두 사람의 문제 수나 라면 그릇 수가 같은 경우는 없다고 가정해도 좋습니다.
->이부분이 힌트이다.

그럼 map으로 조질까? 잠깐 그러면
21 22 /21 23 같은 경우면 ?
어차피 q가 작은넘은 도태되게 돼있다.

그럼 21 22/ 23 25 이면 전자는 지워져야 되는데 이건 어떻게 할꺼임?

*/
map<int, int> m;
bool isDominated(int x, int y)
{
	auto iter = m.lower_bound(x);
	if (iter == m.end())return false;
	return y < iter->second;
}

void removeDominated(int x, int y)
{
	auto iter = m.lower_bound(x);
	if (iter == m.begin())return;
	--iter;
	while (true)
	{
		if (iter->second > y)break;
		if (iter == m.begin()) {
			m.erase(iter);
			break;
		}
		else {
			auto jt = iter;
			--jt;
			m.erase(iter);
			iter = jt;
		}
	}

}

int registered(int x, int y)
{
	if (isDominated(x, y))return m.size();
	removeDominated(x, y);
	m[x] = y;
	return m.size();
}
int main()
{
	ios_base::sync_with_stdio(0);

	int T = 0; cin >> T;

	while (T--)
	{
		int N = 0;
		cin >> N;

		int ret = 0;
		int p = 0, q = 0;
		for (int i = 0; i < N; ++i)
		{
			cin >> p >> q;
			ret += registered(p, q);
		}
		cout << ret << '\n';
		m.clear();
	}

}