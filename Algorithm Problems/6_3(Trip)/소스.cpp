//#include <iostream>
//#include <vector>
//using namespace std;
//
//int n;
//bool areFriends[10][10];
//int res = 0;
//int cnt = 0;
//void Answer();
//int countPairings(bool taken[10]);
//int main()
//{
//	Answer();
//}
//
//void Answer()
//{ //����Ž�� �׷���
//	int C = 0; //���� ���̽�
//	int m = 0;// �л���, ģ������ ��;
//	bool taken[10];
//	std::cin >> C;
//
//	for (int i = 0; i < C; ++i) {
//		memset(areFriends, false, sizeof(areFriends));
//		memset(taken, false, sizeof(taken));
//		res = 0;
//		std::cin >> n >> m;
//		int a = 0, b = 0;
//		for (int j = 0; j < m; j++) {
//			cin >> a >> b;
//			areFriends[a][b] = areFriends[b][a] = true;
//		}
//		std::cout << countPairings(taken);
//	}
//
//
//}
//
//int countPairings(bool taken[10])
//{
//	cnt++;
//	//���� �л��� �� ���� ��ȣ�� ���� �л��� ã�´�.
//	int firstFree = -1;
//	cout << "���κ�\n";
//	for (int i = 0; i < n; ++i)
//		cout << taken[i] << ' ';
//	std::cout <<"\t"<<cnt<<"° ����"<< endl;
//	for (int i = 0; i < n; ++i)
//		if (!taken[i]) {
//			firstFree = i;
//			break;
//		}
//
//	//��� �л��� ¦�� ã������ �� ���� ����� ã������ �����Ѵ�.
//	if (firstFree == -1) {
//		return 1;
//	}
//	int ret = 0;
//	//�� �л��� ¦���� �л��� �����Ѵ�.
//	for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
//		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
//			taken[firstFree] = taken[pairWith] = true;
//			ret += countPairings(taken);
//			
//			taken[firstFree] = taken[pairWith] = false;
//			for (int i = 0; i < n; ++i)
//				cout << taken[i] << ' ';
//			std::cout << endl;
//		}
//	}
//	return ret;
//}
//
//
//
//
include <iostream>

#include <algorithm>

#include <vector>

using namespace std;



const int MAX = 6;



int k;

int lotto[MAX];

int arr[13];



//idx1�� arr�� �ε���, idx2�� lotto�� �ε���

void printLotto(int idx1, int idx2)

{

	//6�� ���� ��� ���� ��� ���

	if (idx2 == MAX)

	{

		for (int i = 0; i < MAX; i++)

			cout << lotto[i] << " ";

		cout << endl;

		return;

	}



	//���������� �־��

	for (int i = idx1; i < k; i++)

	{

		lotto[idx2] = arr[i];

		printLotto(i + 1, idx2 + 1);

	}

}



int main(void)

{

	while (1)

	{

		cin >> k;

		if (k == 0)

			break;



		for (int i = 0; i < k; i++)

			cin >> arr[i];



		printLotto(0, 0);

		cout << endl;

	}

	return 0;

}