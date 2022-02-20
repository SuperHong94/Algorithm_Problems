#include <iostream>
#include <vector>
using namespace std;


int N; //물품수
int K; //버틸 수 있는 무게
int MAX;

struct Object
{
	int _weight;
	int _value;
};


vector<Object> objects;
int cache[100][100];// 조합되었는지 안되었는지 확인

int DFS(int index)
{
	cache[index][index] = 1;
	int ret = 0;
	for (int i = 0; i < objects.size(); ++i) {
		if (cache[index][i] == 1) continue;
		cache[index][i] = 1;  
		cache[i][index] = 1;
		if()
	}
}

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		Object temp;
		cin >> temp._weight >> temp._value;
		objects.emplace_back(temp);
	}

}