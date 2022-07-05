//백준 평범한 배낭부터 다시 도전해본다.
//https://www.acmicpc.net/problem/12865

#include <iostream>
#include <vector>
using namespace std;

int N = 0, K = 0;

vector<pair<int, int>> objects;
bool visit[100];
int sol()
{

	for (int i = 0; i < objects.size(); ++i)
	{
		int w = objects[i].first;
		int v = objects[i].second;


	}
}
int main()
{
	cin >> N >> K;
	int n = N;
	while (n--)
	{
		int w = 0, v = 0; cin >> w >> v;
		objects.emplace_back( w,v );

	}
}