#include <iostream>
#include <vector>
using namespace std;


/*
����� ���� ��
���� ���ڿ� �� ���� �׸��� ���̰� �־�����
���ۼ��ڿ� �� ���� ������ ���̸�ŭ�� ������ ��� ����ϰ� �ʹ�!



*/
int start = 1;
int End = 5;

vector<int> v;
int Combination(int s, int len)
{
	if (v.size()==3) {
		for (auto d : v)
			cout << d << ' ';
		cout << endl;

		return 0;
	}



	for (int i = s + 1; i <= End; ++i)
	{
		v.push_back(i);
		Combination(i, len - 1);
		v.pop_back();
	}
	return 0;
}

//������ �ϱ����ؼ���?
//

int main()
{
	for (int i = start; i <= End; ++i) {

		v.push_back(i);
		Combination(i, 3);
		v.pop_back();
	}
}