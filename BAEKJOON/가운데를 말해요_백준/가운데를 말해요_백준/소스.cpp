/*
https://www.acmicpc.net/problem/1655


*/


//�ڷᱸ���� �����ϸ鼭 �ִ´�. ¦���� ��� N/2 -1 index ���
//�ڷᱸ���� �ߺ��Ǿ� �ϰ� ������ �����ؾ� �Ѵ�.



//������ �ִ� �ڷᱸ�� �迭 �׸��� index�� ������ �� �ִ°�
//heap�� ������.

//�ִ���(root�� ���� ū��), �ּ���(root�� ���� ���� ��)



#include <iostream> 
#include <vector>
#include <queue>
using namespace std;

int N = 0;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;

	priority_queue<int, vector<int>, less<int>> max_q;
	priority_queue<int, vector<int>, greater<int>> min_q;
	while (N--)
	{
		int a = 0; cin >> a;
		if (max_q.size() == min_q.size())
			max_q.push(a);
		else
			min_q.push(a);

		if (!max_q.empty() && !min_q.empty() && max_q.top() > min_q.top())
		{
			int tmp = min_q.top(); min_q.pop();
			min_q.push(max_q.top()); max_q.pop();
			max_q.push(tmp);
		}
		cout<< max_q.top()<<'\n';
	}
}