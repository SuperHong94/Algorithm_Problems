#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;


int cache[1000];// ù������ n�϶��� ���� ����
int s = 0;
vector<int> numbers;//���̸�ŭ�� ���� 
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

		sort(numbers.begin(), numbers.end());//������� �������ֱ�

		//����ȭ�ϱ�
		//���?
		//s=�� 1�̸�
		//number[0]���� number[n-1]���� ���� �õ��ϱ�
		//s�� 2�̸�
		//s[0] s[1],  s[0] s[2] ,,,s[0] s[n-1]   n��
		//s[1] s[2], ,,, s[n-2] s[n-1] n-1��
		// ,
		// ,
		// ,
		//s[n-2] s[n-1]  1�� 

		//�ٵ� number�� �ߺ��� �� �ִ�. ���� �̹��ߴ��� ���� �ʿ䰡����.
		//�̰��� ���ؾ��Ѵ�. ���? ������ȹ���� ������ ����
		//int cache[1000]// ù������ n�϶��� ���� ���� ������? ���������� ���� �ּҰ�
		
	

		

	}
}