#include <iostream>
#include <string>
using namespace std;

const int SIZE = 1000;
string strings[2];
int cache[SIZE];


//문자열 A, B가 있다.
/*
* A and B 에서 가장 긴 부분 수열을 찾는다. 
* A를 기준으로 찾자. B기준으로 찾자
* 
*/

//int FindIndexB(char c,int index)//index이후부터
//{
//	for(int i=0;i<strings[1].length();++i)
//}

int solution(int index,int indexB)
{
	if (cache[index]!= -1)
		return cache[index];

	int& ret = cache[index];
	ret = 1;
	for (int i = index+1; i < strings[0].length(); ++i)
	{
		for (int j = indexB; j < strings[1].length(); ++j) {
			if (strings[0][i] == strings[1][j]){
				ret = max(ret, ret+solution(i, j));
				break;
			}
		}
	}
	return ret;
}

int main()
{
	for (int i = 0; i < 2; ++i) {
		cin >> strings[i];
	}
	memset(cache, -1, sizeof(cache));
	cout << solution(0, 0);


}


//안되네 뭐가 문제인지 고민고고씽~~

//서로 번갈아가면서 하는 방법을 해보자.