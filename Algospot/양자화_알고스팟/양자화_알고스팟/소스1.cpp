#include <iostream>
#include <vector>
using namespace std;


/*
만들고 싶은 것
시작 숫자와 끝 숫자 그리고 길이가 주어지면
시작숫자와 끝 숫자 사이의 길이만큼의 조합을 모두 출력하고 싶다!



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