//���� ����� �賶���� �ٽ� �����غ���.

#include <iostream>
#include <vector>
using namespace std;

int N = 0, K = 0;

vector<pair<int, int>> objects;
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