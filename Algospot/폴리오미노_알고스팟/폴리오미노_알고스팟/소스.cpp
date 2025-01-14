/*
https://algospot.com/judge/problem/read/POLY
熱戚

室稽 舘繕戚糠稽 亜稽匝精 掻娃拭 朔牒 蒸戚 析慶稽 赤陥.
湛匝拭 i鯵拭 紫唖莫戚 赤生檎
蟹袴走巨 n-i鯵税 紫唖莫生稽 虹軒神耕葛研 幻級壱 湛匝拭 旋箭備 細戚檎 吉陥. 
ex)
i=2, n=4
けけ

けけけ
け  

戚係惟 赤生檎
けけ
けけけ
け

  けけ
けけけ
け

    けけ
けけけ
け

けけ
  けけけ
  け


戚係惟 乞莫戚 臣 呪 赤陥.
益 井酔税 呪澗 湛匝+砧腰属匝税 紫唖莫 呪 -1 戚陥.

*/

#include <iostream>

using namespace std;

constexpr int MOD = 10000000;
int cache[101][101];//n鯵税 紫唖莫析 凶税 室稽 舘繕 虹軒神耕葛税 鯵呪




int sol(int n, int first)
{
	if (n == first)return 1;
	if (cache[n][first] != 0)
		return cache[n][first];
	for (int i = 1; i <= n-first; ++i)
	{
		int ret = i + first - 1;
		ret *= sol(n - first, i);
		ret %= MOD;
		cache[n][first] += ret;
		cache[n][first] %= MOD;	

	}
	return cache[n][first];
}

int main()
{
	int C = 0; cin >> C;

	while (C--)
	{
		//memset(cache, 0, sizeof(cache));
		int n = 0; cin >> n;

		int ret = 0;
		for(int i=1;i<=n;++i){
			ret += sol(n, i);
			ret %= MOD;
		}
		cout << ret << endl;

	}
}