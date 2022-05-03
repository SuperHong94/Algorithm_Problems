#include <iostream>

using namespace std;


int arr[1000];
int cache[1000];
int N = 0;

int solution(int start, bool order)
{
	int& ret = cache[start];
	if (ret != 0)
		return ret;

	ret = 1; //자기자신
	for (int i = start + 1; i < N; ++i) {
		if (true == order) {
			if (arr[start] < arr[i])
				ret = max(ret, solution(i, true) + 1);
		}
		if (arr[start] > arr[i])
			ret = max(ret, solution(i, false) + 1);

	}
	return ret;
}

int main()
{

	cin >> N;
	for (int i = 0; i < N; ++i) cin >> arr[i];

	int ret = 0;
	for (int i = 0; i < N; ++i)
		ret = max(ret, solution(i, true));

	cout << ret;

}