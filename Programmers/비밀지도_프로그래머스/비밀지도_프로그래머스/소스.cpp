#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    answer.resize(n);
    vector<int> ret;
    ret.resize(n);
    for (int i = 0; i < ret.size(); ++i)
    {
        ret[i] = arr1[i] | arr2[i];
        int k = 1;
        k=k << (n - 1);
        for (int j = 0; j < n; ++j)
        {
            int a = k & ret[i];
            if ((k & ret[i]) == k)
                answer[i] += '#';
            else
                answer[i] += ' ';
            k=(k >> 1);
        }
    }



    return answer;
}

int main()
{
   auto s= solution(5, { 9, 20, 28, 18, 11 }, { 30, 1, 21, 17, 28 });
    int a = 10;
}