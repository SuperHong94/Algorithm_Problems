//정답은 오른쪽 연결된 선에서 가장긴 부분수열 구하는것이다!
//이걸 토대로 다시해보자
//
/*
내가 못한 이유 규칙을 못찾음 -> 머리속에서 그림을 못그렸다!

*/
#include <iostream>
using namespace std;


int lines[501];
int cache[501];
int N;

int solution(int start)
{
	if (cache[start] != 0)
		return cache[start];

	int& ret = cache[start]=1;

	for (int i = start+1; i < 501; ++i) {
		if (lines[start] < lines[i]) {
			ret = max(ret, solution(i)+1);
		}
	}
	return ret;
}

int main()
{
	int a = 0, b = 0;
	cin >> N;
	int total = N;
	while (N--)
	{
		cin >> a >> b;
		lines[a] = b;
	}
	//for (int i = 0; i < N; ++i) {
	//	cin >> lines[i];
	//}
	int ret = 0;
	for (int i = 0; i < 501; ++i)
	{
		if (lines[i] != 0)
			ret = max(ret, solution(i));
	}
	cout << total- ret << endl;

}