#include <iostream>
#include <string>
using namespace std;

const int SIZE = 1000;
string strings[2];
int cache[SIZE];


//���ڿ� A, B�� �ִ�.
/*
* A and B ���� ���� �� �κ� ������ ã�´�. 
* A�� �������� ã��. B�������� ã��
* 
*/

//int FindIndexB(char c,int index)//index���ĺ���
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


//�ȵǳ� ���� �������� ��ΰ���~~

//���� �����ư��鼭 �ϴ� ����� �غ���.