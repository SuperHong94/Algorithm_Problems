#include <iostream>
#include <queue>
#include <vector>
using namespace std;

constexpr int INF = 100'000'001;
int N;
int M;
struct Bus
{
	int target, dis;

	constexpr bool operator<(const Bus& b) const
	{
		return dis > b.dis;
	}
};

vector<Bus> citis[1001];
int d[1001];

void GetminDis(int start)
{
	d[start] = 0;
	priority_queue<Bus> q;
	q.push(Bus{ start, 0 });
	while (q.empty() == false)
	{
		Bus newBus = q.top();
		q.pop();
		if (newBus.dis < d[newBus.target])
			continue;
		for (int i = 0; i < citis[newBus.target].size(); ++i)
		{

			int target = citis[newBus.target][i].target;
			int dis = newBus.dis + citis[newBus.target][i].dis;
			if (d[target] > dis) {
				d[target] = dis;
				citis[newBus.target][i].dis = d[target];
				q.push(citis[newBus.target][i]);
			}
		}
	}
}
int main()
{
	for (auto& dis : d)
	{
		dis = INF;
	}
	cin >> N >> M;
	int start = 0, target = 0, dis = 0;
	for (int i = 0; i < M; ++i)
	{
		cin >> start >> target >> dis;
		citis[start].emplace_back(Bus{ target, dis });
	}
	cin >> start >> target;

	GetminDis(start);
	cout << d[target];


}
