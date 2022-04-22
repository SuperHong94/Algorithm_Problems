#include <iostream>
#include <memory.h>
using namespace std;



//어떻게 풀까? 끊기만하면된다.
//전기줄 이어야할 곳이 한곳 만있으면 없애야하는 최소 개수는 0
//이어야할 곳이 2개이고 꼬여있으면 없애야하는 개수 1개
//이어야할 곳이 3개이고 꼬여있으면 재수없으면 2개  아니면 1개
//흠 교차(꼬여)있다는 것은 어떻게 알지?
//전기선은 번호로 연결되어있다. ex) 1, 3 
/*
1 , 3
2, 1
이러면 교차
1, 3
2, 4
이러면 괜찮음

1, 5
2, 3
3, 2
이러면 교차

아하 두 번쨰번호가 앞에 두번쨰번호들보다 앞으로가면 꼬이는 구나 !
관점에 따라 앞에 두번쨰번호가 뒤에 두번쨰 번호보다 크면 꼬임


그러면 이제 자료구조는 어떻게할까?
2차원배열로 하는게 편할듯 그렇게하면 루프돌기도 편하고 이어짐 끊는것 0, 1로 표현할 수 있어서 편할듯

교차되는 것도 알았고 자료구조도 알았으니 이제 최소한으로 어떻게 끊을까?

방법 1.
1번부터 n번까지 루프를 돌면서 해당줄과 교차하면 끊는다. 시간복잡도? n(번루프)*(n번가 안꼬인들선에서 그기준으로 끊기 여기서 동적계획법쓸 수 있겠군)

*/


int lines[502];//예시 1, 200연결이면 lines[1][0]=200; 이렇게할꺼임
int copylines[502];
int cache[502];
int N;
int MIN = 100;

int CutCrossline(int point)
{

	int ret = 0;

	cache[point] = 1;  //방문
	for (int i = 1; i <= 500; ++i) {  //겹친거 끊는 루프
		if (cache[i] != 0)continue;//이미 자른거임
		if (copylines[i] != 0) {
			if (point < i) {
				if (copylines[point] > copylines[i]) {
					ret += 1;
					cache[i] = 1;// 지웠다 치고

				}
			}
			else if (point > i) {
				if (copylines[point] < copylines[i]) {
					ret += 1;
					cache[i] = 1;
				}
			}

		}
	}

	//copylines[point] = 0;
	int minRet = 0;
	for (int i = 1; i <=500; ++i) {
		if (copylines[i] == 0) continue;
		if (cache[i] == 0){
			cache[i] = 1;
			minRet = min(minRet, CutCrossline(i));
			cache[i] = 0;
		}
	}

	return ret;
}
int main()
{
	cin >> N;
	int a = 0, b = 0;//두 점
	for (int i = 0; i < N; ++i) {
		cin >> a >> b;
		lines[a] = b;

	}

	for (int i = 1; i <= 500; ++i) {
		if (lines[i] == 0) continue;
		memcpy(copylines, lines, sizeof(lines));
		memset(cache, 0, sizeof(cache));
		//CutCrossline(i);
		MIN = min(MIN, CutCrossline(i));
	}

	//for (int i = 0; i < 501; i++) {
	//	if (cache[i] == 0)continue;
	//	MIN = min(MIN, cache[i]);
	//}
	cout << MIN << endl;
}