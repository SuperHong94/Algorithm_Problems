#include <string>
#include <vector>
#include <queue>
#include <memory.h>


using namespace std;
constexpr int INF = 123456789;

struct Node
{
    int node, dis;
    constexpr bool operator <(const Node& right) const
    {
        return dis > right.dis;
    }
};
int dist[20001];
int map[20001][20001];

int solution(int n, vector<vector<int>> edge) {

    memset(map, 0, sizeof(map));
    for (const auto& item : edge)
    {
        map[item[0]][item[1]] = 1;
        map[item[1]][item[0]] = 1;
    }
    for (int i = 1; i <= n; ++i)
        dist[i] = INF;

    int answer = 0;
    int start = 1;
    dist[start] = 0;
    priority_queue<Node> q;
    q.push({ start,0 });
    while (q.empty() == false)
    {
        Node newNode = q.top();
        int node = newNode.node;
        int dis = newNode.dis;
        q.pop();

        for (int i = 1; i <= n; ++i)
        {
            if (i == node)continue;
            if (map[node][i] == 0)continue;//연결안된거
            int newDis = dis + map[node][i];
            if (dist[i] > newDis)
            {
                answer = max(answer, newDis);
                dist[i] = newDis;
                q.push({ i,newDis });
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {

        if (answer == dist[i])
            cnt += 1;
    }

    return cnt;
}