#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	unordered_map<string, int> um;
	for (const auto& s : participant) {
		um[s]++;
	}

	for (const auto& s : completion) {
		um[s]--;
	}

	for (const auto& s : participant) {
		if (um[s] != 0)
			return s;
	}


	return answer;
}