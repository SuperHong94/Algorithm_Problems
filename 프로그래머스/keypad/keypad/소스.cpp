#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Hand
{
	int x, y;

	int GetDistance(const Hand& hand) {
		int ry = abs(y - hand.y);
		int rx = abs(x - hand.x);
		return ry + rx;
	}
};

void judgeHand(int x, int y, string& answer, Hand& left, Hand& right, bool isRight)
{
	Hand target = { x,y };
	int leftDis = left.GetDistance(target);
	int rightDis = right.GetDistance(target);
	if (leftDis > rightDis) {//오른쪽이 더 가까운 경우
		answer += "R";
		right = target;
	}
	else if (leftDis < rightDis) {
		answer += "L";
		left = target;
	}
	else {
		if (true == isRight) {
			answer += "R";
			right = target;
		}
		else {
			answer += "L";
			left = target;
		}
	}
}
string solution(vector<int> numbers, string hand) {
	string answer = "";
	Hand left = { 0,3 }, right = { 2,3 };

	bool isRight = "right" == hand;

	for (auto num : numbers) {
		switch (num)
		{
		case 1:
			answer += "L";
			left = { 0,0 };
			break;
		case 4:
			answer += "L";
			left = { 0,1 };
			break;
		case 7:
			answer += "L";
			left = { 0,2 };
			break;

			/////////////

		case 3:
			answer += "R";
			right = { 2,0 };
			break;
		case 6:
			answer += "R";
			right = { 2,1 };
			break;
		case 9:
			answer += "R";
			right = { 2,2 };
			break;

			/// 2 5 8 0
		case 2:
			judgeHand(1, 0, answer, left, right, isRight);
			break;
		case 5:
			judgeHand(1, 1, answer, left, right, isRight);
			break;
		case 8:
			judgeHand(1, 2, answer, left, right, isRight);
			break;
		case 0:
			judgeHand(1, 3, answer, left, right, isRight);
			break;
		default:
			break;
		}
	}
	return answer;
}

int main()
{
	std::cout << solution({ 1,3,4,5,8,2,1,4,5,9,5 }, "right");
}