#include <iostream>

using namespace std;

int main()
{
	int N = 0; cin >> N;
	
	int MAXSCORE = 0;
	int winplayer = 0;
	int p1 = 0;
	int p2 = 0;
	int p1_score = 0;
	int p2_score = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> p1;
		cin >> p2;
		p1_score += p1;
		p2_score += p2;
		int ret = p1_score - p2_score;
		if (MAXSCORE < abs(ret))
		{
			MAXSCORE = abs(ret);
			ret >= 0?winplayer = 1 : winplayer = 2;
		}
	}

	cout << winplayer << ' ' << MAXSCORE;
}