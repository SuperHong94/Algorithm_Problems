#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int minlength = s.length();

    //필요한것 비교하려는 문자열, 문자수
    //압축된문자열
    for (int i = 1; i <=s.length()/2; ++i)
    {
        string compressedStr = "";
        string cmpStrA = s.substr(0,i);
        int cnt = 1; //같은 횟수
        for (int j = i; j <= s.length(); j += i)
        {
            string cmpStrB = s.substr(j,  i);
            if (cmpStrA == cmpStrB)
                cnt += 1;
            else {
                if (1 < cnt) {
                    compressedStr += to_string(cnt);
                }
                compressedStr += cmpStrA;
                cmpStrA = cmpStrB;
                cnt = 1;
            }
            if (j + i > s.length()) {
                compressedStr += s.substr(j);
                break;
            }
        }
        minlength = min(minlength, (int)compressedStr.length());

    }
    answer = minlength;
    return answer;
}


int main()
{
    solution("aabbaccc");
}