#include <iostream>

using namespace std;

int sequence[1000];
int cache[1000];
int N;
//�ڱ��ε��� ���� ū���� ������ ��ȯ�ϸ� ���(�ڱ� ����)?
//{10, 20, 10, 30, 20, 50}�� ������
//{4��,3��,3��,2��,2��,1��} -> �̷��� �ϸ�ɱ�?
/*
*
* ������ N��°�� ȣ���ϸ�
* �˻��ϴ� ������ N��° �������� ũ��{
*	ĳ�� N���� ����Ȱ��� ������ �� ���� �����Ѵ�.
*	�˻��ϴ°��� ������ N��° ������ ������Ʈ�Ѵ�.
*	ĳ���� solv(N+1, �˻��ϴ°�)+1 �ְ� �� ĳ���� �����Ѵ�.
*
* }
* solv(N+1, �˻��ϴ°�)�� �����Ѵ�.



* N+1��°�� ȣ���Ѵ�.
* N+1�� ��͸� �ݺ� ������
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
	//������ġ���� �� �� �ִ� �κм����� ���̴� 1 �̻�
	sequence[start] = 1;
	//���簪���� �� ū �������� ������ �� ū �������� ��ġ���� Ž���Ѵ�.
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