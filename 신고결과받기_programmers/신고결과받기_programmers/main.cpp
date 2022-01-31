#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;
	answer.resize(id_list.size());
	//A가 B를 신고했다.
	//A는 이제 B를 신고못함 
	//이것을 어떻게 알지? A가 B를 신고했다? 신고받은 ID를 키로 갖고 신고한 ID들을set으로하여 그것을 value로 갔는 map이 존재한다면 중복없이 개수를 셀수있다. 그럼 고고
	//누가 얼마나 신고받았는지는 이제 알겠다 그러면 신고한애가 자기가 신고해서 몇명이 리폿처리되었는지는 어캐알지?맵에서 set의 수가 k보다 크거나 같으면 신고처리가된것이고 순회해서 그사람 개수 추가!

	std::map<std::string, std::set<std::string>> reportList;
	for (const auto& s : report)
	{
		auto off = s.find(" ");
		reportList[s.substr(off + 1, s.length())].emplace(s.substr(0, off)); //B가 A에게 신고당했다.
	}

	for (const auto& item : reportList) {
		if (item.second.size() >= k)
		{
			for (const auto reporter : item.second) {
				for (int i = 0; i < id_list.size(); ++i) {
					if (reporter == id_list[i])
						answer[i] += 1;
				}
			}
		}
	}



	return answer;
}