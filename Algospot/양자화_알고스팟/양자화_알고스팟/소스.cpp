#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;


int cache[1000];// 첫시작이 n일때의 값을 저장
int s = 0;
vector<int> numbers;//길이만큼의 조합 
int start = 0;
int End = 0;
int quant(const vector<int>& numbers, int start)
{
	if (cache[start] != -1)
		return cache[start];

	cache[start] = 2000;
	//for(int i=num)
}


int main()
{
	int c = 0; cin >> c;
	while (c--)
	{
		memset(cache, -1, sizeof(cache));
		int n = 0; cin >> n;
		 cin >> s;
		vector<int> numbers;
		numbers.resize(n);
		for (auto& n : numbers)
			cin >> n;

		sort(numbers.begin(), numbers.end());//순서대로 정렬해주기

		//양자화하기
		//어떻게?
		//s=가 1이면
		//number[0]부터 number[n-1]까지 전부 시도하기
		//s가 2이면
		//s[0] s[1],  s[0] s[2] ,,,s[0] s[n-1]   n번
		//s[1] s[2], ,,, s[n-2] s[n-1] n-1번
		// ,
		// ,
		// ,
		//s[n-2] s[n-1]  1번 

		//근데 number가 중복될 수 있다. 따라서 이미했던거 또할 필요가없다.
		//이것을 피해야한다. 어떻게? 동적계획으로 갔던것 저장
		//int cache[1000]// 첫시작이 n일때의 값을 저장 무슨값? 오차제곱의 합의 최소값
		
	

		

	}
}