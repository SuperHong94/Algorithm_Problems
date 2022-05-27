/*
https://www.acmicpc.net/problem/1655


*/


//�ڷᱸ���� �����ϸ鼭 �ִ´�. ¦���� ��� N/2 -1 index ���
//�ڷᱸ���� �ߺ��Ǿ� �ϰ� ������ �����ؾ� �Ѵ�.



//������ �ִ� �ڷᱸ�� �迭 �׸��� index�� ������ �� �ִ°�
//heap�� ������.

//�ִ���(root�� ���� ū��), �ּ���(root�� ���� ���� ��)



#include <iostream> 
#include <vector>
#include <queue>
using namespace std;


class MAX_HEAP
{
	vector<int> v;
	int size = 0;
public:


	void insert(int num)
	{
		int parent = (size - 1) / 2;
		v.push_back(num); //�����ٰ� �ֱ�
		if (size == 0) {
			size++;
			return;
		}
		int cur = size;
		for (int i = parent; i >= 0; i=(i-1)/2) {
			if (v[i] < num)
			{
				int tmp = v[cur];
				v[cur] = v[i];
				v[i] = tmp;
				cur = i;
				if (i == 0)
					break;
			}
			else
				break;
		}
		size++;

	}

	void Print()
	{
		for (int d : v)
			cout << d << ' ';
		cout << endl;
	}
};


class MIN_HEAP
{
	vector<int> v;
	int size = 0;
public:


	void insert(int num)
	{
		int parent = (size - 1) / 2;
		v.push_back(num); //�����ٰ� �ֱ�
		if (size == 0) {
			size++;
			return;
		}
		int cur = size;
		for (int i = parent; i >= 0; i = (i - 1) / 2) {
			if (v[i] > num)
			{
				int tmp = v[cur];
				v[cur] = v[i];
				v[i] = tmp;
				cur = i;
				if (i == 0)
					break;
			}
			else
				break;
		}
		size++;

	}

	void Print()
	{
		for (int d : v)
			cout << d << ' ';
		cout << endl;
	}
};


int main()
{
	int N; cin >> N;
	MAX_HEAP maxh;
	MIN_HEAP minh;

	for (int i = 0; i < N; ++i)
	{
		int num; cin >> num;
		maxh.insert(num);
		minh.insert(num);
	}
	maxh.Print();
	minh.Print();
}