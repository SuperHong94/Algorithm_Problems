#include <iostream>

using namespace std;


int arr[1000];
int lefts[1000];
int rights[1000];
int cache[1000];
int N = 0;

int leftnums(int start)
{
	int& ret = lefts[start];
	if (ret != 0)
		return ret;
	ret = 1;
	for (int i = start - 1; i >= 0; --i) {

		if (arr[start] > arr[i])
			ret = max(ret, leftnums(i) + 1);

	}
	return ret;
}

int rightNums(int start)
{
	int& ret = rights[start];
	if (ret != 0)
		return ret;

	ret = 1;
	for (int i = start +1; i<N; ++i) {

		if (arr[start]> arr[i])
			ret = max(ret, rightNums(i) + 1);

	}
	return ret;
}


int main()
{

	cin >> N;
	for (int i = 0; i < N; ++i) cin >> arr[i];

	int ret = 0;
	for (int i = 0; i < N; ++i){
		ret = max(ret, leftnums(i)+rightNums(i)-1); //�ߺ��� �ڱ��ڽ� ���ֱ�

	}
	cout << ret;

}


/*
���� �������� �ڱ� �������δ� ���� �۾�����
�ڱ� ���������δ� ���� ũ���ؼ� ������ ����!
-> ���� ���


�̰� �ƴ϶�
 f(n)=f(k)+f(r);
 k<n and n<r �̰�
arr[k] <arr[n] and arr[n]>arr[r]  
�̷��� �ؾߵȴ�.


*/