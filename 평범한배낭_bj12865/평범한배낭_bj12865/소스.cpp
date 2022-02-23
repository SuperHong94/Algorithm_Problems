//#include <iostream>
//#include <vector>
//#include <memory.h>
//using namespace std;
//
//
//int N; //물품수
//int K; //버틸 수 있는 무게
//
//
//struct Object
//{
//	int _weight;
//	int _value;
//	Object operator+(const Object& right)
//	{
//		_weight = _weight + right._weight;
//		_value = _value + right._value;
//		return *this;
//	}
//	bool operator<(const Object& right) const {
//		return _value < right._value;
//	}
//
//};
//
//
//vector<Object> objects;
//Object cache[100];//
//
///// <summary>
///// 
///// </summary>
///// <param name="index"> 현재 인덱스</param>
///// <param name="weight"> 지금까지의 무게</param>
///// <returns></returns>
//Object DFS(int index)
//{
//	if (cache[index]._value != -1)
//		//return cache[index];
//
//	Object ret = objects[index];
//
//	for (int i = 0; i < objects.size(); ++i) {
//		if (i == index)continue;
//		Object temp = DFS(i);
//		if (temp._weight + ret._weight > K)
//			ret = max(ret, temp);
//		else
//			ret = ret + temp;
//
//		if (objects[index]._weight + objects[i]._weight > K)continue;
//		ret = max(ret, objects[index]);
//
//
//
//	}
//	return cache[index] = ret;
//}
//
//int main()
//{
//	memset(cache, -1, sizeof(cache));
//	cin >> N >> K;
//	for (int i = 0; i < N; ++i) {
//		Object temp;
//		cin >> temp._weight >> temp._value;
//		objects.emplace_back(temp);
//	}
//	int MAX = 0;
//	for (int i = 0; i < N; ++i) {
//		memset(cache, -1, sizeof(cache));
//		MAX = max(MAX, DFS(i)._value);
//	}
//	cout << MAX << '\n';
//}



#include <iostream>

#define endl "\n"
#define MAX 110
using namespace std;

int N, K;
int Weight[MAX];
int Value[MAX];
int DP[MAX][100010];

int Max(int A, int B) { if (A > B) return A; return B; }

void Input()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> Weight[i] >> Value[i];
    }
}

void Solution()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (j >= Weight[i])    DP[i][j] = Max(DP[i - 1][j], DP[i - 1][j - Weight[i]] + Value[i]);
            else DP[i][j] = DP[i - 1][j];
        }
    }
    cout << DP[N][K] << endl;
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("Input.txt", "r", stdin);
    Solve();

    return 0;
}

