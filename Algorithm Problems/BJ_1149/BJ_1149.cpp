/////*
////문제
////RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.
////
////집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때,
////아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.
////
////1번 집의 색은 2번 집의 색과 같지 않아야 한다.
////N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
////i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.
////
////
////입력
////첫째 줄에 집의 수 N(2 ≤ N ≤ 1,000)이 주어진다.
////둘째 줄부터 N개의 줄에는 각 집을 빨강, 초록, 파랑으로 칠하는 비용이 1번 집부터 한 줄에 하나씩 주어진다. 집을 칠하는 비용은 1,000보다 작거나 같은 자연수이다.
////
////출력
////첫째 줄에 모든 집을 칠하는 비용의 최솟값을 출력한다.
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
///// 집의 수
///// </summary>
//int N;
//
///// <summary>
///// 집 색깔
///// </summary>
//enum EColor
//{
//	eRed = 0, eGreen, eBlue
//};
//int myMin = 10000000;//집칠하는 비용최대값
//int colors[1000][3];
//
//
////0~3열이 있다. 3배열에는 다음 집의 색깔이 들어가 있다.
//int compareValue[1000][3][3];
//
//
//
//
//
////방법 DFS로 모두 검색!한다.->이걸로하면 시간초과다온다. Dynamic Programing으로 풀어야된다.
////처음 빨강집, 파랑집, 초록집 순서로 3번찾으면 끝날듯?
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
