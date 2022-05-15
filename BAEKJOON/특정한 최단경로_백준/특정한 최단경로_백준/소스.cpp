#include <iostream>
#include <queue>
using namespace std;
constexpr int INF = 99999999;


int N;
int map[801][801];
int v1, v2;
int dis[801];

struct Node
{
	int v, dis;
	constexpr bool operator<(const Node& left)const
	{
		return dis > left.dis;
	}
};


int DST(int start,int end)
{
	for (int i = 0; i <= N; ++i)
		dis[i] = INF;

	dis[start] = 0;
	priority_queue<Node> q;

	q.push({ start,0 });

	while (q.empty() == false)
	{

		Node newNode = q.top();
		int newV = newNode.v;
		q.pop();
		for (int i = 1; i <= N; ++i)
		{
			if (map[newV][i] == 0)continue;
			//if (dis[i] == 0)continue;
			int left = dis[i];
			int right = map[newV][i] + newNode.dis;
			if (left > right)
			{
				dis[i] = map[newV][i] + newNode.dis;
				q.push({ i,dis[i] });

			}
		}
	}
	//dis[start] = dis[end];
	return dis[end];
}


int main()
{

	int e = 0;
	int a = 0, b = 0, c = 0;
	cin >> N >> e;

	while (e--)
	{
			cin >> a >> b >> c;
			map[a][b] = c;
			map[b][a] = c;
	}
	cin >> v1 >> v2;
	int ret=min(DST(1,v1)+DST(v1,v2)+DST(v2,N), DST(1, v2) + DST(v2, v1) + DST(v1, N));

	
	if (ret >= INF)
		cout << -1;
	else
		cout << ret;
}