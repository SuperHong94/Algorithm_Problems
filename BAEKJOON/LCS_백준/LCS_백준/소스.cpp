#include <iostream>
#include <memory.h>
#include <string>
using namespace std;

const int SIZE = 1000;
string strings[2];
int cache[SIZE][SIZE];


int solution(int indexA,int indexB)
{
	if (indexA == -1 || indexB == -1)
		return 0;
	if (cache[indexA][indexB] != -1)
		return cache[indexA][indexB];
	if (strings[0][indexA] == strings[1][indexB])
		return cache[indexA][indexB] = solution(indexA - 1, indexB - 1) + 1;

	else
		return cache[indexA][indexB] = max(solution(indexA - 1, indexB), solution(indexA, indexB - 1));

}


int main()
{
	for (int i = 0; i < 2; ++i) {
		cin >> strings[i];
	}
	memset(cache, -1, sizeof(cache));

	int ret = 0;
	cout << solution(strings[0].length()-1,strings[1].length()-1) << endl;


}

