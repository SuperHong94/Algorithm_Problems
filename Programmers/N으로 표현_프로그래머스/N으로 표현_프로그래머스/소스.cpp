#include <string>
#include <vector>
using namespace std;

/*
문제를 쪼갤 수 있나
자리수 추가
+,-,*,/

*/


int cache[9];
int sol(int N, int number, int now, int cnt)
{
    if (cnt > 8)
        return  -1;
    if (now == number)
    {
        return cache[cnt] = 1;
    }
    if (cache[cnt] != 0)
        return cache[cnt];


    string s = to_string(N);
    s = s + to_string(N);
    int ret = sol(N, number, atoi(s.c_str()), cnt + 1);

    ret = sol(N, number, now + N, cnt + 1);
    ret = sol(N, number, now - N, cnt + 1);
    ret = sol(N, number, now * N, cnt + 1);

    ret = sol(N, number, now / N, cnt + 1);


    return cache[cnt];

}


int solution(int N, int number) {
    int answer = 0;
    answer = sol(N, number, N, 1);


    for (int i = 1; i <= 8; ++i)
        if (cache[i] == 1) {
            return answer = i;

        }

    return -1;
}