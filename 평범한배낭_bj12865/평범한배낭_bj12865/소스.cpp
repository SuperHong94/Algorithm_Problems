#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;


int N; //��ǰ��
int K; //��ƿ �� �ִ� ����
int MAX;

struct Object
{
	int _weight;
	int _value;
};


vector<Object> objects;
int cache[100][100];//

/// <summary>
/// 
/// </summary>
/// <param name="index"> ���� �ε���</param>
/// <param name="weight"> ���ݱ����� ����</param>
/// <returns></returns>
int DFS(int index, int weight)
{

	cache[index][index] = objects[index]._value;

	//cache[weight] = objects[index]._value;
	int ret = objects[index]._value;
	for (int i = index; i < objects.size(); ++i) {
		if (cache[index][i] == -1)
			if (i, weight + objects[i]._weight <= K)
				cache[index][i] = objects[index]._value + DFS(i, weight + objects[i]._weight);
		ret = max(cache[index][i], ret);
	}
	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		Object temp;
		cin >> temp._weight >> temp._value;
		objects.emplace_back(temp);
	}
	for (int i = 0; i < N; ++i) {
		MAX = max(MAX, DFS(i, objects[i]._weight));
	}
	cout << MAX << '\n';
}