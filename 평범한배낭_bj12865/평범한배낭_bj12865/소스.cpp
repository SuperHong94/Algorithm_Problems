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
	Object operator+(const Object& right)
	{
		_weight = _weight + right._weight;
		_value = _value + right._value;
		return *this;
	}
	bool operator<(const Object& right) const {
		return _value < right._value;
	}

};


vector<Object> objects;
Object cache[100];//

/// <summary>
/// 
/// </summary>
/// <param name="index"> ���� �ε���</param>
/// <param name="weight"> ���ݱ����� ����</param>
/// <returns></returns>
Object DFS(int index)
{
	if (cache[index]._value != -1)
		return cache[index];

	Object ret = objects[index];

	for (int i = index+1; i < objects.size(); ++i) {

		Object temp= objects[index]+ DFS(i);
		if (temp._weight > K)continue;
		ret = max(ret, temp);
	}
	return cache[index]=ret;
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
	
	cout << DFS(0)._value << '\n';
}