#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;
	answer.resize(id_list.size());
	//A�� B�� �Ű��ߴ�.
	//A�� ���� B�� �Ű���� 
	//�̰��� ��� ����? A�� B�� �Ű��ߴ�? �Ű���� ID�� Ű�� ���� �Ű��� ID����set�����Ͽ� �װ��� value�� ���� map�� �����Ѵٸ� �ߺ����� ������ �����ִ�. �׷� ���
	//���� �󸶳� �Ű�޾Ҵ����� ���� �˰ڴ� �׷��� �Ű��Ѿְ� �ڱⰡ �Ű��ؼ� ����� ����ó���Ǿ������� ��ĳ����?�ʿ��� set�� ���� k���� ũ�ų� ������ �Ű�ó�����Ȱ��̰� ��ȸ�ؼ� �׻�� ���� �߰�!

	std::map<std::string, std::set<std::string>> reportList;
	for (const auto& s : report)
	{
		auto off = s.find(" ");
		reportList[s.substr(off + 1, s.length())].emplace(s.substr(0, off)); //B�� A���� �Ű���ߴ�.
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