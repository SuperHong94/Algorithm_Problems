#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer;

	int lowScore = 0;
	int highScore = 0;
	//1. 원래 가지고 있던 번호에서 맞는번호 제외하기
	for (int i = 0; i < lottos.size(); ++i) {
		for (int j = 0; j < win_nums.size(); ++j) {
			if (lottos[i] == win_nums[j]) {
				win_nums[j] = -1;
				lottos[i] = -1;
				lowScore += 1;
				break;
			}
		}
	}
	for (int i = 0; i < lottos.size(); ++i)
	{
		if (0 == lottos[i])
			highScore += 1;
	}


	int highRank = 7 - (highScore + lowScore);
	int lowRank = 7 - lowScore;
	if (lowRank >= 7)
		lowRank = 6;
	if (highRank >= 7)
		highRank = 6;
	answer.push_back(highRank); answer.push_back(lowRank);

	return answer;
}