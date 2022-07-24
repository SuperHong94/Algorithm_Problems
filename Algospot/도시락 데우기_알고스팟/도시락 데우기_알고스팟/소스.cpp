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
////����ª�� waveTime �̱� �ܼ��� �̷����ϸ�ȵ� �ٸԴ½ð��� �ּҰ� �Ǵ°��� �����̴�.
////��Ա� (wave��������)
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