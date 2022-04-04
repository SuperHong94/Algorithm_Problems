#include <iostream>
#include <vector>
using namespace std;


/*
만들고 싶은 것
시작 숫자와 끝 숫자 그리고 길이가 주어지면
시작숫자와 끝 숫자 사이의 길이만큼의 조합을 모두 출력하고 싶다!



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

//조합을 하기위해서는?
//

int main()
{
	for (int i = start; i <= End; ++i) {

		v.push_back(i);
		Combination(i, 3);
		v.pop_back();
	}
}