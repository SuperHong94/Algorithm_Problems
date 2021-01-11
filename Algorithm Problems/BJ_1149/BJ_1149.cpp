/////*
////����
////RGB�Ÿ����� ���� N�� �ִ�. �Ÿ��� �������� ��Ÿ�� �� �ְ�, 1�� ������ N�� ���� ������� �ִ�.
////
////���� ����, �ʷ�, �Ķ� �� �ϳ��� ������ ĥ�ؾ� �Ѵ�. ������ ���� ����, �ʷ�, �Ķ����� ĥ�ϴ� ����� �־����� ��,
////�Ʒ� ��Ģ�� �����ϸ鼭 ��� ���� ĥ�ϴ� ����� �ּڰ��� ���غ���.
////
////1�� ���� ���� 2�� ���� ���� ���� �ʾƾ� �Ѵ�.
////N�� ���� ���� N-1�� ���� ���� ���� �ʾƾ� �Ѵ�.
////i(2 �� i �� N-1)�� ���� ���� i-1��, i+1�� ���� ���� ���� �ʾƾ� �Ѵ�.
////
////
////�Է�
////ù° �ٿ� ���� �� N(2 �� N �� 1,000)�� �־�����.
////��° �ٺ��� N���� �ٿ��� �� ���� ����, �ʷ�, �Ķ����� ĥ�ϴ� ����� 1�� ������ �� �ٿ� �ϳ��� �־�����. ���� ĥ�ϴ� ����� 1,000���� �۰ų� ���� �ڿ����̴�.
////
////���
////ù° �ٿ� ��� ���� ĥ�ϴ� ����� �ּڰ��� ����Ѵ�.
////
////
////*/
////
//#include <iostream>
//#include <memory.h>
//using namespace std;
//
//
///// <summary>
///// ���� ��
///// </summary>
//int N;
//
///// <summary>
///// �� ����
///// </summary>
//enum EColor
//{
//	eRed = 0, eGreen, eBlue
//};
//int myMin = 10000000;//��ĥ�ϴ� ����ִ밪
//int colors[1000][3];
//
//
////0~3���� �ִ�. 3�迭���� ���� ���� ������ �� �ִ�.
//int compareValue[1000][3][3];
//
//
//
//
//
////��� DFS�� ��� �˻�!�Ѵ�.->�̰ɷ��ϸ� �ð��ʰ��ٿ´�. Dynamic Programing���� Ǯ��ߵȴ�.
////ó�� ������, �Ķ���, �ʷ��� ������ 3��ã���� ������?
//
//
//int Getmin(int i, EColor color);
//int main()
//{
//	memset(compareValue, 0, sizeof(compareValue));
//	memset(compareValue, 0, sizeof(colors));
//	cin >> N;
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> colors[i][eRed];
//		cin >> colors[i][eGreen];
//		cin >> colors[i][eBlue];
//	}
//	int a = 0, b = 0, c = 0;
//
//	Getmin(0, eRed);
//	Getmin(0, eGreen);
//	Getmin(0, eBlue);
//
//
//	cout << compareValue[0][eRed][eBlue] << ' ' << compareValue[0][eRed][eGreen] << endl;
//	cout << compareValue[0][eGreen][eRed]<<' ' << compareValue[0][eGreen][eBlue] << endl;
//	cout << compareValue[0][eBlue][eRed]<<' ' << compareValue[0][eBlue][eGreen] << endl;
//}
//
//int Getmin(int i, EColor color)
//{
//	if (i == N) {
//		return colors[i - 1][color];
//	}
//
//	switch (color)
//	{
//	case eRed:
//		if (compareValue[i][color][eBlue] != 0)
//			return compareValue[i][color][eBlue];
//		else {
//			compareValue[i][color][eBlue] = colors[i][color] + Getmin(i + 1, eBlue);
//		}
//		if (compareValue[i][color][eGreen] != 0)
//			return compareValue[i][color][eGreen];
//		else
//			compareValue[i][color][eGreen] = colors[i][color] + Getmin(i + 1, eGreen);
//		break;
//	case eGreen:
//		if (compareValue[i][color][eBlue] != 0)
//			return compareValue[i][color][eBlue];
//		else
//			compareValue[i][color][eBlue] = colors[i][color] + Getmin(i + 1, eBlue);
//
//		if (compareValue[i][color][eRed] != 0)
//			return compareValue[i][color][eRed];
//		else
//			compareValue[i][color][eRed] = colors[i][color] + Getmin(i + 1, eRed);
//		break;
//	case eBlue:
//		if (compareValue[i][color][eRed] != 0)
//			return compareValue[i][color][eRed];
//		else
//			compareValue[i][color][eRed] = colors[i][color] + Getmin(i + 1, eRed);
//
//
//		if (compareValue[i][color][eGreen] != 0)
//			return compareValue[i][color][eGreen];
//		else
//			compareValue[i][color][eGreen] = colors[i][color] + Getmin(i + 1, eGreen);
//		break;
//	default:
//		break;
//	}
//
//}
#include<iostream>
#include <algorithm>
#define endl "\n"
#define MAX 1000 + 1

using namespace std;

int N, Answer;
int MAP[MAX][3];
int DP[MAX][3];

int Min(int A, int B) { if (A < B) return A; return B; }

void Input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> MAP[i][j];
        }
    }
    DP[0][0] = DP[0][1] = DP[0][2] = 0;
    MAP[0][0] = MAP[0][1] = MAP[0][2] = 0;
}

void Solution()
{
    for (int i = 1; i <= N; i++)
    {
        DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + MAP[i][0];
        DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + MAP[i][1];
        DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + MAP[i][2];
    }
    Answer = min(min(DP[N][0], DP[N][1]), DP[N][2]);
    cout << Answer << endl;
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("Input.txt", "r", stdin);
    Solve();

    return 0;
}
