#include <iostream>
using namespace std;

int A[101];
int B[101];
int cahce[101][101];
int N = 0;
int M = 0;
long long MIN = INT64_MIN;
int solv(int indexA,int indexB)
{
	int& ret = cahce[indexA][indexB];
	if (ret != 0)
		return ret;
	
	int value = 0;
	if (indexA == 0 && indexB == 0)
		value = MIN;
	else
		value = max(A[indexA], B[indexB]);


	for (int i = indexA+1; i <= N; ++i) {
		if( value < A[i])
			ret = max(ret, solv(i,indexB) + 1);
	}


	for (int i = indexB + 1; i <= M; ++i) {
		if (value < B[i])
			ret = max(ret, solv(indexA,i ) + 1);
	}

	return ret;
}



int main()
{
	int C = 0; cin >> C;
	while (C--)
	{
		cin >> N;
		cin >> M;
		for (int i = 1; i <= N; ++i)
			cin >> A[i];
		
		for (int i = 1; i <= M; ++i)
			cin >> B[i];

		memset(cahce, 0, sizeof(cahce));
		cout << solv(0,0) << endl;
	}
	
}


//기존에 solv(index)는 index에서의 최대 부분 증가 수열인데
//위의 코드로 하면 좋은점이 한번의 solv로 전체 배열에서 최대 부분증가 수열원소의 개수를 알 수 있다.