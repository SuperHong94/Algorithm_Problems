#include <string>
#include <vector>

using namespace std;


const string numbers[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };



char StringToNumber(const string& s, int& index)
{
    for (int i = 0; i < 10; ++i)
    {
        int numlength = numbers[i].length();
        if (s.length() < numlength)continue;
        if (s.substr(0, numlength) == numbers[i]) {
            index += numlength-1;
            return i + '1'-1;
        }
    }
}
int solution(string s) {
    string answer="";
    for (int i = 0; i < s.length(); ++i) {
        if (0 == isalpha(s[i])) {
            answer += s[i];
        }
        else {
            answer+=StringToNumber(s.substr(i), i);
        }
    }
 
    return atoi(answer.data());
}




//심박한 풀이
#include <regex>

int solution2(string s) {
    s = regex_replace(s, regex("zero"), "0");
    s = regex_replace(s, regex("one"), "1");
    s = regex_replace(s, regex("two"), "2");
    s = regex_replace(s, regex("three"), "3");
    s = regex_replace(s, regex("four"), "4");
    s = regex_replace(s, regex("five"), "5");
    s = regex_replace(s, regex("six"), "6");
    s = regex_replace(s, regex("seven"), "7");
    s = regex_replace(s, regex("eight"), "8");
    s = regex_replace(s, regex("nine"), "9");
    return stoi(s);
}
