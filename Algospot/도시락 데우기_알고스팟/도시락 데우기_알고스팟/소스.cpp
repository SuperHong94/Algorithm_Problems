//https://www.algospot.com/judge/problem/read/LUNCHBOX



#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int waveTimes[10000];
int eatTimes[10000];
int N = 0;


//Á¦ÀÏÂªÀº waveTime »Ì±â
//¹ä¸Ô±â (wave³¡³µÀ¸¸é)

int GeMinWaveIndex()
{
	int MIN = 12345679;
	int index = -1;
	for (int i = 0; i < N; ++i) {
		if (waveTimes[i] == 0)continue;
		if (MIN > waveTimes[i]) {
			MIN = waveTimes[i];
			index = i;
		}
	}

	return index;
}

int main()
{
	int C = 0; cin >> C;



	/*
	------
	 - -- -
	*/
	while (C--)
	{
		cin >> N;

		for (int j = 0; j < N; ++j)
			cin >> waveTimes[j];
		for (int j = 0; j < N; ++j)
			cin >> eatTimes[j];


		vector<int> eatIndex;
		int totalTime = 0;
		while (true)
		{
			int index = GeMinWaveIndex();
			int breakCnt = 0;
			int minusTime = 1;
			if (index != -1) {
				minusTime = waveTimes[index];
				waveTimes[index] = waveTimes[index] - minusTime;

				for (int index : eatIndex)
				{
					if (eatTimes[index] <= 0) {
						breakCnt++;
						continue;
					}
					eatTimes[index] -= minusTime;
				}
				eatIndex.push_back(index);
			}
			else {
				for (int index : eatIndex)
				{
					if (eatTimes[index] <= 0) {
						breakCnt++;
						continue;
					}
					eatTimes[index] -= minusTime;
				}
			}
		
		
			if (breakCnt == N)
				break;

		
			totalTime += minusTime;
		}

		cout << totalTime << endl;
	}
}