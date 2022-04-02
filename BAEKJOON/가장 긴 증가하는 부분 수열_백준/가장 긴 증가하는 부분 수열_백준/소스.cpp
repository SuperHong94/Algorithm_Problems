#include <iostream>

using namespace std;

int sequence[1000];
int cache[1000];
int N;
//자기인덱스 보다 큰것의 개수를 반환하면 어떨까(자기 포함)?
//{10, 20, 10, 30, 20, 50}이 있으면
//{4개,3개,3개,2개,2개,1개} -> 이렇게 하면될까?
/*
*
* 예를들어서 N번째를 호출하면
* 검사하는 값보다 N번째 수열보다 크면{
*	캐시 N번에 저장된값이 있으면 그 값을 리턴한다.
*	검사하는값을 수열의 N번째 값으로 업데이트한다.
*	캐쉬에 solv(N+1, 검사하는값)+1 넣고 그 캐쉬를 리턴한다.
*
* }
* solv(N+1, 검사하는값)을 리턴한다.



* N+1번째를 호출한다.
* N+1은 재귀를 반복 끝까지
*/

int solv(int index, int rValue)
{

	if (index == N)
		return 0;
	int MAX = 0;
	for (int i = index; i < N; ++i)
		if (rValue < sequence[i]) {
			if (cache[i] != 0)
				cache[index] = max(cache[i]+1, cache[index]);
			else
				cache[index] = max(cache[index], solv(i + 1, sequence[i]) + 1);
		}
		else
			solv(i + 1, rValue) + 1;

	return cache[index];
}


int dp(int start) {
	if (cache[start] != 0)
		return cache[start];
	//현재위치에서 올 수 있는 부분수열의 길이는 1 이상
	sequence[start] = 1;
	//현재값보다 더 큰 다음값을 만나면 더 큰 다음값의 위치부터 탐색한다.
	for (int next = start + 1; next < N; ++next)
		if (sequence[start] < sequence[next])
			cache[start] = max(cache[start], dp(next) + 1);

	return cache[start];
}

int main()
{
	N = 0;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> sequence[i];
	}

	int MAX = 0;
	for (int i = 0; i < N; ++i) {
		MAX = max(MAX, dp(i));
	}

	for (int i = 0; i < N; i++)
		cout << cache[i] << ' ';
	//cout << MAX << endl;

}