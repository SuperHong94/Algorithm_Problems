#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    //A�� B�� �Ű��ߴ�.
    //A�� ���� B�� �Ű���� 
    //�̰��� ��� ����? A�� B�� �Ű��ߴ�? �Ű���� ID�� Ű�� ���� �Ű��� ID�� value�� ���� map�� �����Ѵٸ� �ߺ����� ������ �����ִ�. �׷� ���
    //���� �󸶳� �Ű�޾Ҵ����� ���� �˰ڴ� �׷��� �Ű��Ѿְ� �ڱⰡ �Ű��ؼ� ����� ����ó���Ǿ������� ��ĳ����?
    //
    std::map<std::string, std::string> reportList;
    for (const auto& s : report)
    {
        auto off = s.find(" ");
        reportList.emplace(s.substr(off + 1, s.length()), s.substr(0, off)); //B�� A���� �Ű���ߴ�.
    }

    for (const auto& item : reportList) {
        if (item.length() >= k) {

        }
    }



    return answer;
}