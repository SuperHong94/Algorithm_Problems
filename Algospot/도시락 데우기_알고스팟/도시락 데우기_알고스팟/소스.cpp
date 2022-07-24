////https://www.algospot.com/judge/problem/read/LUNCHBOX
//
//
//
//#include <iostream>
//#include <queue>
//#include <vector>
//using namespace std;
//
////int waveTimes[10000];
//int eatTimes[10000];
//int N = 0;
//
//
////제일짧은 waveTime 뽑기 단순히 이렇게하면안됨 다먹는시간이 최소가 되는것이 정답이다.
////밥먹기 (wave끝났으면)
//
//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> waveTimes;
//
////int GeMinWaveIndex()
////{
////	int MIN = 12345679;
////	int index = -1;
////	for (int i = 0; i < N; ++i) {
////		if (waveTimes[i] == 0)continue;
////		if (MIN > waveTimes[i]) {
////			MIN = waveTimes[i];
////			index = i;
////		}
////	}
////
////	return index;
////}
//
//int main()
//{
//	int C = 0; cin >> C;
//
//	while (C--)
//	{
//		cin >> N;
//
//		for (int j = 0; j < N; ++j) {
//			int time;
//			cin >> time;
//
//			waveTimes.push({ time,j });
//		}
//
//
//		for (int j = 0; j < N; ++j)
//			cin >> eatTimes[j];
//
//
//		vector<int> eatIndex;
//		int totalTime = 0;
//		while (waveTimes.empty() == false)
//		{
//
//			auto item = waveTimes.top();
//			waveTimes.pop();
//			int waveTime = item.first;
//			int index = item.second;
//			totalTime += waveTime;
//
//			for (auto i : eatIndex)
//			{
//				if (eatTimes <= 0)continue;
//				eatTimes[i] -= waveTime;
//			}
//			eatIndex.push_back(index);
//		}
//
//		for (auto i : eatIndex)
//		{
//			if (eatTimes[i] > 0)
//			{
//				totalTime += eatTimes[i];
//				break;
//			}
//		}
//
//		cout << totalTime << endl;
//	}
//}