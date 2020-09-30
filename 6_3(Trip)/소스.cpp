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
	int C = 0; //���� ���̽�
	int m = 0;// �л���, ģ������ ��;
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
	//���� �л��� �� ���� ��ȣ�� ���� �л��� ã�´�.
	int firstFree = -1;
	cout << "���κ�\n";
	for (int i = 0; i < n; ++i)
		cout << taken[i] << ' ';
	std::cout <<"\t"<<cnt<<"° ����"<< endl;
	for (int i = 0; i < n; ++i)
		if (!taken[i]) {
			firstFree = i;
			break;
		}

	//��� �л��� ¦�� ã������ �� ���� ����� ã������ �����Ѵ�.
	if (firstFree == -1) {
		return 1;
	}
	int ret = 0;
	//�� �л��� ¦���� �л��� �����Ѵ�.
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

