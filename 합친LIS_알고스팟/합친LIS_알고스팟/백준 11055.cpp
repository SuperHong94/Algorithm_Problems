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


//������ solv(index)�� index������ �ִ� �κ� ���� �����ε�
//���� �ڵ�� �ϸ� �������� �ѹ��� solv�� ��ü �迭���� �ִ� �κ����� ���������� ������ �� �� �ִ�.