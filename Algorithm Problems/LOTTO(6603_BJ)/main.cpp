#include <iostream>
#include <algorithm>
using namespace std;

void mySwap(int& a, int& b);
void ShowS(int* s, int k, int left, int right);
int main()
{
	while(1){
	int K = 0;
	cin >> K;
	if (K == 0)
		break;
	int* S = nullptr;
	S = new int[K];
	for (int i = 0; i < K; ++i)
		cin >> S[i];

	//����Ǽ��� nCr�� �ϸ�Ǵµ� ������� ���� ����ؾߵǴ±�
	ShowS(S, K, 5, 6);  //S�迭�� K�� , �ǹ� p
	cout << endl;
	delete[] S;
	}


}
void mySwap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

void ShowS(int* s, int k, int left, int right)
{
	static int cnt = 0;
	
	if (right >= k) {
		left--;
		right = 6;
	}
	if (left < 0) {
		left = 5;
		cnt++;
		
	}
	if (cnt >= k - 6)
		return;
	//sort(&s[0], &s[6]);
	for (int i = 0; i < 6; ++i)
		cout << s[i] << ' ';
	cout << endl;
	mySwap(s[left], s[right]);
	
	
	
	

	
	ShowS(s, k, left, right+1);
	
	
}

//#include <iostream>
//using namespace std;
//
//int lotto[6];
//int arr[13];
//int k = 0;
//void PrintL(int left, int right)
//{
//	if (right == 6) {
//		for (int i = 0; i < 6; i++)
//			cout << lotto[i] << ' ';
//		cout << endl;
//		return;
//	}
//
//	for (int i = left; i < k; i++) {
//		lotto[right] = arr[i];
//		PrintL(i + 1, right + 1);
//	}
//
//}
//int main()
//{
//	//memset(lotto, 0, 6);
//	//memset(arr, 0, 13);
//
//	while (1) {
//		cin >> k;
//		if (k == 0)
//			break;
//		for (int i = 0; i < k; i++)
//			cin >> arr[i];
//
//		PrintL(0, 0);
//		cout << endl;
//
//	}
//}

/*
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



��ó: https://jaimemin.tistory.com/579 [������]


*/

