#include <iostream>
#include <vector>

using namespace std;

vector<int> gradingStudents(vector<int> grades)
{

	for (auto& d : grades) {
		if (d <= 37)
			continue;
		int remain = d % 5;
		int k = ((d - remain) + 5 - d);
		if (k < 3) {
			d += k;
		}
	}

	return grades;
}

int main()
{
	vector<int> grades = { 84,29,57 };
	for (auto d : gradingStudents(grades))
		cout << d << ' ';
}