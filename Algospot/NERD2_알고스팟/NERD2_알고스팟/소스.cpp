//https://algospot.com/judge/problem/read/NERD2
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

/*
�ð��ʰ� ����.
NlongN�ε� �� ?
�׷� longN�� ���⵵�� �����ߵǴµ�?
Ʈ���� ������ ���¿� ����� ���� N^2�� �Ǵ°Ÿ�?
->����� �����Ҳ��ƴϸ� �� �ִ°� ����
�� ����� ���� ���� ��� �׸� ���� ���� ���� ���ٰ� �����ص� �����ϴ�.
->�̺κ��� ��Ʈ�̴�.

�׷� map���� ������? ��� �׷���
21 22 /21 23 ���� ���� ?
������ q�� �������� ���µǰ� ���ִ�.

�׷� 21 22/ 23 25 �̸� ���ڴ� �������� �Ǵµ� �̰� ��� �Ҳ���?

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