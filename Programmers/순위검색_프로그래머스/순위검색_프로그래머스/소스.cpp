#include <string>
#include <vector>

using namespace std;


int GetNum(const vector<string>& info, const string& lan, const string& pos, const string& level,
	const string& food, const string& score)
{
	int ret = 0;
	int sc = stoi(score);
	for (const auto& item : info) {
		int i = item.rfind(" ");
		string itemScore = item.substr(i);
		int itemSc = stoi(itemScore);
		if (item.find(lan) == -1)continue;
		if (item.find(pos) == -1)continue;
		if (item.find(level) == -1)continue;
		if (item.find(food) == -1)continue;
		if (itemSc < sc)continue;
		ret += 1;

	}
	return ret;
}

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;

	for (const auto& item : query)
	{
		int p = 0;
		int cur = item.find(" and ");
		string language = item.substr(p, cur - p);

		p = cur + 1;
		cur = item.find(" and ", p);
		string position = item.substr(cur+5, cur-5 - p);

		p = cur + 1;
		cur = item.find(" and ", p);
		string level = item.substr(cur + 5, cur-5 - p);

		p = cur + 1;
		cur = item.find(" and ", p);
		string food = item.substr(cur + 5, cur - 5 - p);

		p = cur + 1;
		cur = item.find(" and ", p);
		string score = item.substr(cur + 5, cur - 5 - p);
		int ret = GetNum(info, language, position, level, food, score);
		answer.push_back(ret);
	}
	return answer;
}

int main()
{
	auto r = solution({ "java backend junior pizza 150", "python frontend senior chicken 210", "python frontend senior chicken 150", "cpp backend senior pizza 260", "java backend junior chicken 80", "python backend senior chicken 50" },
		{ "java and backend and junior and pizza 100", "python and frontend and senior and chicken 200", "cpp and - and senior and pizza 250", "- and backend and senior and - 150", "- and - and - and chicken 100", "- and - and - and - 150" });
}