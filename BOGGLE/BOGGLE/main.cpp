#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
	vector<string> inputs;
	int n = 0;
	cin >> n;

	int N = 0;
	string knownWord[10];
	for (int i = 0; i < n; ++i) {
		for(int j=0;j<5;++j){
		string tmp;
		cin >> tmp;
		inputs.emplace_back(tmp);
		}
		cin >> N;
		for (int k = 0; k < N; ++k) {
			cin >> knownWord[k];
		}

		//
	}
}