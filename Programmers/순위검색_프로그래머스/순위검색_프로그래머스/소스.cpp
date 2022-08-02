//https://school.programmers.co.kr/learn/courses/30/lessons/72412

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <algorithm>
using namespace std;


unordered_map<string, int> Map;
vector<int> List[4][3][3][3];
vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	Map["-"] = 0;
	Map["cpp"] = 1;
	Map["java"] = 2;
	Map["python"] = 3;
	Map["backend"] = 1;
	Map["frontend"] = 2;
	Map["junior"] = 1;
	Map["senior"] = 2;
	Map["chicken"] = 1;
	Map["pizza"]=2;

	for (auto str : info)
	{
		stringstream sst(str);
		string a,b,c,d;
		int score;
		sst >> a >> b >> c >> d >> score;
		int arr[4] = { Map[a],Map[b],Map[c],Map[d] };

		for (int i = 0; i < (1 << 4); ++i) {
			int idx[4] = { 0, };
			for (int j = 0; j < 4; ++j) {
				if (i & (1 << j)) {
					idx[j] = arr[j];
				}
			}
			List[idx[0]][idx[1]][idx[2]][idx[3]].push_back(score);
		}
	}

	for (int a = 0; a < 4; ++a) {
		for (int b = 0; b < 3; ++b) {
			for (int c = 0; c < 3; ++c) {
				for (int d = 0; d < 3; ++d) {
					sort(List[a][b][c][d].begin(), List[a][b][c][d].end());
				}
			}
		}
	}
	
	for (auto str : query)
	{
		stringstream sst(str);
		string a, b, c, d, tmp;
		int score;
		sst >> a >> tmp >> b >> tmp >> c >> tmp >> d >> score;

		auto& slist=List[Map[a]][Map[b]][Map[c]][Map[d]];

		vector<int>::iterator low = lower_bound(slist.begin(), slist.end(), score);
		answer.push_back(slist.end() - low);
	}


	return answer;
}

int main()
{
	auto r = solution({ "java backend junior pizza 150", "python frontend senior chicken 210", "python frontend senior chicken 150", "cpp backend senior pizza 260", "java backend junior chicken 80", "python backend senior chicken 50" },
		{ "java and backend and junior and pizza 100", "python and frontend and senior and chicken 200", "cpp and - and senior and pizza 250", "- and backend and senior and - 150", "- and - and - and chicken 100", "- and - and - and - 150" });
}