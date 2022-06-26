#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

struct Player
{
	set<int> win; //승리한 플레이어
	set<int> lose;//진 플레이어
};
int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	vector<Player> players;
	players.resize(results.size() + 1);

	for (auto& result : results) {
		int winPlayer = result[0];
		int losePlayer = result[1];
		players[winPlayer].win.insert(losePlayer);
		for (int d : players[losePlayer].win)  //진플레이어가 이긴 모든 플레이어는 승리플레이어도 이긴다.
			players[winPlayer].win.insert(d);

		players[losePlayer].lose.insert(winPlayer);
		for (int d : players[winPlayer].lose) //승리플레이어가 패배한 모든플레이어는 진플레이어도 진다.
			players[losePlayer].lose.insert(d);
	}

	for (int i = 1; i <= n; ++i) {

		for (int win = 0; win < n; ++win) {
			if (players[i].win.size()==win && players[i].lose.size() == n-win-1)
				answer++;
		}
	}
	return answer;
}