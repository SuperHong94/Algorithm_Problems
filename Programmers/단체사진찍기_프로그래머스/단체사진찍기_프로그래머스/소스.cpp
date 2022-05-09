#include <iostream>




#include <string>
#include <vector>
#include <memory.h>
using namespace std;

int SIZE =8;
int posArr[8];
int result = 0;
bool visit[8];

int FRIEND2int(char c)
{
	switch (c)
	{
	case 'A':
		for (int i = 0; i < SIZE; ++i)
			if (posArr[i] == 0)
				return i;
	case 'C':
		for (int i = 0; i < SIZE; ++i)
			if (posArr[i] == 1)
				return i;

	case 'F':
		for (int i = 0; i < SIZE; ++i)
			if (posArr[i] == 2)
				return i;

	case 'J':
		for (int i = 0; i < SIZE; ++i)
			if (posArr[i] == 3)
				return i;

	case 'M':
		for (int i = 0; i < SIZE; ++i)
			if (posArr[i] == 4)
				return i;

	case 'N':
		for (int i = 0; i < SIZE; ++i)
			if (posArr[i] ==5)
				return i;

	case 'R':
		for (int i = 0; i < SIZE; ++i)
			if (posArr[i] == 6)
				return i;

	case 'T':
		for (int i = 0; i < SIZE; ++i)
			if (posArr[i] == 7)
				return i;
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
	opValue += 1;

	switch (op)
	{
	case '=':
		if (abs(left- right) == opValue)
			return true;
		break;
	case '<':
		if (abs(left -right) < opValue)
			return true;
		break;
	case '>':
		if (abs(left - right) > opValue)
			return true;
		break;
	
	}

	return false;
}





void DFS2(int index, const vector<string>& data)
{

	if (index == SIZE)
	{
		bool flag = true;
		for (const auto& s : data)
		{
			if (isTrue(s) == false) {
				return;
			}
		}
		if (true == flag)
			result += 1;
		return;
	}
	for (int i = 0; i < SIZE; ++i) {
		if (visit[i] == false) {
			posArr[index] = i;
			visit[i] = true;
			DFS2(index + 1,data);
			visit[i] = false;

		}
	}

}

int solution(int n, vector<string> data) {
	SIZE = 8;
	memset(posArr, 0, sizeof(posArr));
	memset(visit, false, sizeof(visit));
	result = 0;
	//for (int i = 0; i < SIZE; ++i)
	//{
	//	DFS(i, 0,data);
	//}
	DFS2(0, data);

	return result;
}


//답이 틀렸다 뭐가 문제였을까?
//DFS 바꿔서 해본다.
int main()
{

	cout<<solution(5, { "N~F=0", "R~T>2" });
	
	//DFS2(0);
}


int DFS(int who, int index, const vector<string>& data) //who를 index로 채운다.
{



	posArr[who] = index;

	for (int i = 0; i < SIZE; ++i)
	{
		if (posArr[i] == -1) //아직 방문안한 노드
		{
			DFS(i, index + 1, data); //아직방문안한 노드에 index+1 번호 주기
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