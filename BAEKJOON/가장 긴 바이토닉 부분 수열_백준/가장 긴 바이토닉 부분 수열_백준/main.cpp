#include <iostream>

using namespace std;


int arr[1000];
int cache[1000];
int N = 0;

int solution(int start)
{
	int& ret = cache[start];
	if (ret != 0)
		return ret;


	for (int i = start + 1; i < N; ++i) {
		if (true == order) {
			if (arr[start] < arr[i])
				ret = max(ret, solution(i, true) + 1);
		}
		if (arr[start] > arr[i])
			ret = max(ret, solution(i, false) + 1);

	}
	//int left =1;
	//int right = 1;
	//for (int i = start - 1; i >= 0; --i) {
	//	if (arr[start] > arr[i])
	//		left = max(left, solution(i) + 1);
	//}
	//for (int i = start + 1; i < N; ++i) {
	//	if (arr[start] < arr[i])
	//		right = max(right, solution(i) + 1);
	//}
	//ret = left + right - 1;
	return ret;
}

int main()
{

	cin >> N;
	for (int i = 0; i < N; ++i) cin >> arr[i];

	int ret = 0;
	for (int i = 0; i < N; ++i)
		ret = max(ret, solution(i));

	cout << ret;

}


/*
���� �������� �ڱ� �������δ� ���� �۾�����
�ڱ� ���������δ� ���� ũ���ؼ� ������ ����!
-> ���� ���


*/