#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

//잘라서 넣기 최소 길이로
bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> um;
    int minLen = phone_book[0].length();
    for (const auto& num : phone_book)
    {
      
        minLen = min((int)num.length(), minLen);
        if (um.find(num.substr(0, minLen)) == um.end())
        {
            um[num]++;
        }
        else
            return false;
    }
    return answer;
}

int main()
{
    solution({ "12", "123", "1235", "567", "88" });
}