#include <string>
#include <vector>
#include <memory.h>
using namespace std;

int dfs(const vector<int>& numbers, int index, int cur, int target)
{
    if (index == numbers.size())
    {
        return (cur == target) ? 1 : 0;
    }

    return dfs(numbers, index + 1, cur + numbers[index], target) + dfs(numbers, index + 1, cur - numbers[index], target);
}

int solution(vector<int> numbers, int target) {

    return  dfs(numbers, 0, 0, target);
}