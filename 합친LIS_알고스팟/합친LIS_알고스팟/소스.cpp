#include <iostream>
#include <memory.h>
#include <set>
using namespace std;

/*
* 가장먼저 드는 생각
* 두 배열을 하나로 합친다음에 LIS를 만들어보자.
* -> 안된다. 두개로 합치면 순서가 날라갈 수 있다.
* 그러면 어캐해!
* A의 각각의 부분증가수열하고 B의 각각의 부분 증가수열을 합쳐야되는데
* 이게 쉽지가 않은데?
* 왜 쉽지가 않지?
* A각각의 부분증가수열 구하는게 N^2이다.
* 그러면 그것에 또 B의 부분 증가수열을 한다? 음 이건쫌
* 그러면 어캐해야되?
* A={10, 20, 30, 1, 2}
* 여기서 얻는 부분증가수열
* {10,20,30}, { 1, 2}  크게 두가지로 나타낼 수있다.
* B={10, 20, 30} B가 이렇다면
* A+B={1,2,10,20,30}이 된다.
* 즉 둘의 최대 증가 수열끼리 합치면 죽도밥도 안된다는 고런 말씀!
* 그러면 A를 구하고 B를 합쳐 볼까?
* A만 구했을 때 A의 캐시에는 {3,2,1,2,1} 이렇게 있을테고
* 여기에 B를 합치면 캐시에는 {3,2,1, 5, 4} 가 될꺼 같다.
* 그렇기위해서는 A 부분증가수열 최대를 캐시에 넣어놓고 B는 B대로 적어놓고
* 그리고 합쳐야 겠다.
* -> 실패 실패의 원인
* 3 2 1 2 1 는 {10,20,30,1,2}에 대응 되고 3,2,1은 10, 20, 30에 대응된다.
* 근데 문제는 뭐냐?! 나의 로직은
* A의 n번째 인덱스가 B의 n번째인덱스보다 작으면  A의 n번째 인덱스를 A의 n번째 캐시+B의 n번째캐시 더하는 것으로 업데이트를 했다.
* 문제는 A의 [0]번쨰와 B의 1번째를 비교하는 경우 이값이 이미 중복이 되었기에  더하면 안되는데 더한다는 것이다.
* 그래서 A 수열을 이루고 있는 정보를 가지고 있어야해서 자료구조를 변경하였다.
* cache를 set의 배열로하여 부분증가 수열의 원소들을 저장해 두었다. 하지만??????????/ 오답이 나왔다.
*
* 1
* 5 5
* 2 7 7 7 1
* 5 9 3 6 3
* 이 테스트 의 경우 답이 4가 나와야 되는데 6이나와버렸다. 처음 부분증가순열을 만드는것에서 완벽하지 않았기 때문이다.
*
* 새로운방법
* 합치는것이 아니라 한번할때 한꺼번에 한다.
*
* 정답을 참고한 코드이다.
*
* 근데 long long 의 최솟값을 하는지는 알겠다. 입력이 32비트 정수이니깐
* 근데 왜 검색을 0~N] 까지 인지를 모르겠다. 그리고 왜 최솟값부터 연결하고 시작하는지 모르겠다. 처음부터 순서대로 따라가면서 이해해야겠다.
*/
int N = 0, M = 0;

int A[100];
int B[100];
int cache[100][100];
//set<int>cache[300];

long long MIN_VALUE = INT64_MIN;
int solv(int indexA, int indexB, int pred) {

	if (indexA == N || indexB == M)
		return 0;
	int& ret = cache[indexA][indexB];
	if (ret != 0)
		return ret;

	ret = 1;
	//ret = 2; //A와 B 두개 가 있기에
	int value = pred;


	//int max_value = 0;
	for (int i = indexA + 1; i < N; ++i)
	{
		if (value < A[i])
			ret = max(ret, solv(i, indexB, A[i]) + 1);
	}

	for (int i = indexB; i < M; ++i)
	{
		if (value < B[i])
			ret = max(ret, solv(indexA, i, B[i]) + 1);
	}
	//ret = max_value;
	return ret;

}


int main()
{

	int C = 0; cin >> C;
	while (C--) {
		cin >> N >> M;

		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		for (int j = 0; j < M; ++j)
			cin >> B[j];
		memset(cache, 0, sizeof(cache));
		int MAX = 0;
		for (int i = 0; i < N; ++i) {
			MAX = max(MAX, solv(i, 0, A[i]));
		}
		for (int i = 0; i < M; ++i) {
			MAX = max(MAX, solv(0, i, B[i]));
		}
		cout << MAX << endl;


	}
}