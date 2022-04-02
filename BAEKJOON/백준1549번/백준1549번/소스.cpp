//N과 M  내가쓴정답

#include <iostream>
#include <vector>
using namespace std;

int N = 0, M = 0;
bool vist[9] = { false, };
void Print(int n,int cnt,vector<int>& v)
{
	v.push_back(n);
	vist[n] = true;
	if (cnt == M) {
		for (int d : v)
			printf("%d ", d);
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; ++i) {
		if (vist[i] == false){
			Print(i,cnt+1,v);
			vist[i] = false;
			v.pop_back();
		}
	}
}
int main()
{
	cin >> N >> M;
	vector<int> v;
	for (int i = 1; i <= N; ++i){
		Print(i,1,v);
		vist[i] = false;
		v.pop_back();
	}
}


//N과 M 다른사람정답

#include <iostream>
//#include <vector>
using namespace std;

int N = 0, M = 0;
bool vist[9] = { false, };
int arr[9] = { 0, };
void Print(int cnt)
{

	if (cnt == M) {
		for (int i = 0; i < M; ++i)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; ++i) {
		if (vist[i] == false) {
			vist[i] = true;
			arr[cnt] = i;
			Print(cnt + 1);
			vist[i] = false;
		}
	}
}
int main()
{
	cin >> N >> M;
	Print(0);
}