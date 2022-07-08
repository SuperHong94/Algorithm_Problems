//���� ����� �賶���� �ٽ� �����غ���.
//https://www.acmicpc.net/problem/12865

#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int N = 0, K = 0;

vector<pair<int, int>> objects;
bool visit[100];
int cache[101][100001];


int pack(int capacity, int item)
{
	if (item == N)
		return 0;
	int& ret = cache[item][capacity];
	if (ret != -1) return ret;
	ret = pack(capacity, item + 1); //���� �ȴ�´�.
	if (capacity >= objects[item].first) //���� ��´�.
		ret = max(ret, pack(capacity - objects[item].first, item + 1) + objects[item].second);

	return ret;
}
int main()
{
	cin >> N >> K;
	int n = N;
	memset(cache, -1, sizeof(cache));
	while (n--)
	{
		int w = 0, v = 0; cin >> w >> v;
		objects.emplace_back( w,v );

	}
	cout << pack(K,0) << endl;
}