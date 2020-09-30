#include <iostream>
#include <vector>
using namespace std;

int n;
bool areFriends[10][10];
int res = 0;
int cnt = 0;
void Answer();
int countPairings(bool taken[10]);
int main()
{
	Answer();
}

void Answer()
{
	int C = 0; //문제 케이스
	int m = 0;// 학생수, 친구쌍의 수;
	bool taken[10];
	std::cin >> C;

	for (int i = 0; i < C; ++i) {
		memset(areFriends, false, sizeof(areFriends));
		memset(taken, false, sizeof(taken));
		res = 0;
		std::cin >> n >> m;
		int a = 0, b = 0;
		for (int j = 0; j < m; j++) {
			cin >> a >> b;
			areFriends[a][b] = areFriends[b][a] = true;
		}
		std::cout << countPairings(taken);
	}


}

int countPairings(bool taken[10])
{
	cnt++;
	//남은 학생들 중 가장 번호가 빠른 학생을 찾는다.
	int firstFree = -1;
	cout << "윗부분\n";
	for (int i = 0; i < n; ++i)
		cout << taken[i] << ' ';
	std::cout <<"\t"<<cnt<<"째 루프"<< endl;
	for (int i = 0; i < n; ++i)
		if (!taken[i]) {
			firstFree = i;
			break;
		}

	//모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료한다.
	if (firstFree == -1) {
		return 1;
	}
	int ret = 0;
	//이 학생과 짝지을 학생을 결정한다.
	for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			
			taken[firstFree] = taken[pairWith] = false;
			for (int i = 0; i < n; ++i)
				cout << taken[i] << ' ';
			std::cout << endl;
		}
	}
	return ret;
}

