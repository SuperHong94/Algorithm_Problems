//https://www.algospot.com/judge/problem/read/LUNCHBOX



#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//익히는 시간+ 먹는시간 최대로 되는것으로 우선순위 큐에 담는다.
int waveTimes[10000];
int eatTimes[10000];
int N = 0;


priority_queue<pair<int, int>> q;


int main()
{
	int C = 0; cin >> C;

	while (C--)
	{
		cin >> N;

		for (int j = 0; j < N; ++j) {
			cin >> waveTimes[j];
		}
		for (int j = 0; j < N; ++j)
			cin >> eatTimes[j];

		for (int j = 0; j < N; ++j)
		{
			q.push({ eatTimes[j] ,waveTimes[j] });
		}


		vector<int> eat;
		int totalTime = 0;
		while (q.empty() == false)
		{

			auto item = q.top(); q.pop();
			int eatTime = item.first;
			int waveTime = item.second;
		
			totalTime += waveTime;

			for (auto& i : eat)
			{
				if (eatTimes <= 0)continue;
				i -= waveTime;
			}
			eat.push_back(eatTime);
		}

		int MAX = 0;
		for (auto i : eat)
		{
			if (i> 0)
			{
				MAX=max(MAX,i);
	
			}
		}
		totalTime += MAX;
		cout << totalTime << endl;
	}
}