//백준 평범한 배낭부터 다시 도전해본다.
//https://www.acmicpc.net/problem/12865

#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;

int N = 0, K = 0;

vector<pair<int, int>> objects;
string names[101];
vector<int> results;
int cache[101][100001];


int pack(int capacity, int item)
{
	if (item == N)
		return 0;
	int& ret = cache[item][capacity];
	if (ret != -1) return ret;
	ret = pack(capacity, item + 1); //물건 안담는다.
	if (capacity >= objects[item].first) {//물건 담는다.
		ret = max(ret, pack(capacity - objects[item].first, item + 1) + objects[item].second);
	}
	return ret;
}

void reconstruct(int capacity, int item)
{
	if (item == N)
		return;
	if (pack(capacity, item) == pack(capacity, item + 1))
		reconstruct(capacity, item + 1);
	else
	{
		results.push_back(item);
		reconstruct(capacity - objects[item].first, item + 1);
	}
}
int main()
{
	int C = 0; cin >> C;
	while (C--) {
		results.clear();
		objects.clear();
		cin >> N >> K;
		memset(cache, -1, sizeof(cache));
		for(int i=0;i<N;++i){
			cin >> names[i];
			int w = 0, v = 0; cin >> w >> v;
			
			objects.emplace_back(w, v);
		}
		reconstruct(K, 0);
		cout << pack(K, 0) <<' '<<results.size()<<'\n';
		for (int i : results)
			cout << names[i] << '\n';
	}
}