#include <string>
#include <vector>

using namespace std;


const string numbers[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };

string answer = "";
int solution(string s) {
    int answer = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (0 == isalpha(s[i])) {
            answer += s[i];
        }
        else {
            for (int j = 0; j < 10; ++j) {

            }
        }
    }
 
    return answer;
}


int main()
{
    solution("s");
}
