#include <iostream>
#include <vector>
using namespace std;


/*
����� ���� ��
���� ���ڿ� �� ���� �׸��� ���̰� �־�����
���ۼ��ڿ� �� ���� ������ ���̸�ŭ�� ������ ��� ����ϰ� �ʹ�!



*/
int start = 1;
int End = 10;

vector<int> v;
int Combination(int s, int len)
{
	if (len == 0) {
		for (auto d : v)
			cout << d << ' ';
		cout << endl;
		return 0;
	}


	for (int i = s + 1; i <= End; ++i)
	{
		v.push_back(s);
		Combination(i, len - 1);
		v.pop_back();
	}

	return 0;
}



int main()
{
	for (int i = start; i <= End - 4; ++i) {

		Combination(i, 4);
	}
}