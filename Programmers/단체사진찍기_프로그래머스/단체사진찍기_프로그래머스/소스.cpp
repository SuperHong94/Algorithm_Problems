#include <iostream>

using namespace std;


#include <string>
#include <vector>
#include <memory.h>
using namespace std;

const int SIZE = 8;
/*5
예시
n=2, ["N~F=0", "R~T>2"]
N~F=0의 의미는
N은F와 간격이 0이기를 원한다.



그냥싹다 나열한다음에 이거 조건 같은지만 검사할까?

*/

int posArr[8];
int result = 0;


int FRIEND2int(char c)
{
	switch (c)
	{
	case 'A':
		return 0;
	case 'C':
		return 1;
	case 'F':
		return 2;
	case 'J':
		return 3;
	case 'M':
		return 4;
	case 'N':
		return 5;
	case 'R':
		return 6;
	case 'T':
		return 7;
	default:
		return -1;
		break;
	}
}
bool isTrue(const string& s)
{
	int left = FRIEND2int(s[0]);
	int right = FRIEND2int(s[2]);
	char op = s[3];
	int opValue = s[4]-'0';

	switch (op)
	{
	case '=':
		if (abs(posArr[left] - posArr[right]) == 1)
			return true;
		//break;
	case '<':
		if (abs(posArr[left] - posArr[right]) < opValue+1)
			return true;
		break;
	case '>':
		if (abs(posArr[left] - posArr[right]) > opValue + 1)
			return true;
		break;
	default:
		return false;
	}

	return false;
}

int DFS(int who, int index,const vector<string>& data) //who를 index로 채운다.
{



	posArr[who] = index;

	for (int i = 0; i < SIZE; ++i)
	{
		if (posArr[i] == -1) //아직 방문안한 노드
		{
			DFS(i, index + 1,data); //아직방문안한 노드에 index+1 번호 주기
			posArr[i] = -1;
		}
	}

	if (index == SIZE - 1)
	{
		bool flag = true;
		for (const auto& s : data)
		{
			if (isTrue(s) == false) {
				flag = false;
				break;
			}
		}
		if (true == flag)
			result += 1;
		
	}
	posArr[who] = -1;
	return 0;

}


int solution(int n, vector<string> data) {
	memset(posArr, -1, sizeof(posArr));
	result = 0;
	for (int i = 0; i < SIZE; ++i)
	{
		DFS(i, 0,data);
	}

	return result;
}


//답이 틀렸다 뭐가 문제였을까?
//DFS 바꿔서 해본다.
int main()
{

	cout<<solution(5, { "N~F=0", "R~T>2" });
	

}