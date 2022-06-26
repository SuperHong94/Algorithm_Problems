#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

struct Player
{
	set<int> win; //�¸��� �÷��̾�
	set<int> lose;//�� �÷��̾�
};
int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	vector<Player> players;
	players.resize(results.size() + 1);

	for (auto& result : results) {
		int winPlayer = result[0];
		int losePlayer = result[1];
		players[winPlayer].win.insert(losePlayer);
		for (int d : players[losePlayer].win)  //���÷��̾ �̱� ��� �÷��̾�� �¸��÷��̾ �̱��.
			players[winPlayer].win.insert(d);

		players[losePlayer].lose.insert(winPlayer);
		for (int d : players[winPlayer].lose) //�¸��÷��̾ �й��� ����÷��̾�� ���÷��̾ ����.
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