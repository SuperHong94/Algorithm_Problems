/*
https://www.acmicpc.net/problem/1655


*/


//자료구조에 정렬하면서 넣는다. 짝수일 경우 N/2 -1 index 출력
//자료구조는 중복되야 하고 정렬을 유지해야 한다.



//순서가 있는 자료구조 배열 그리고 index로 접근할 수 있는것
//heap을 만들자.

//최대힙(root가 가장 큰값), 최소힙(root가 가장 작은 값)



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
		v.push_back(num); //끝에다가 넣기
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
		v.push_back(num); //끝에다가 넣기
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