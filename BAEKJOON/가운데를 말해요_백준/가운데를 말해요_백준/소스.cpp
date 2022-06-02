/*
https://www.acmicpc.net/problem/1655


*/


//자료구조에 정렬하면서 넣는다. 짝수일 경우 N/2 -1 index 출력
//자료구조는 중복되야 하고 정렬을 유지해야 한다.



//순서가 있는 자료구조 배열 그리고 index로 접근할 수 있는것
//heap을 만들자.

//최대힙(root가 가장 큰값), 최소힙(root가 가장 작은 값)



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