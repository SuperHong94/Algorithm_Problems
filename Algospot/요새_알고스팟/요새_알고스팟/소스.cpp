//https://algospot.com/judge/problem/read/FORTRESS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//반지름 작은 순으로 정렬
//작은것 부터 자신의 부모 찾기
//

class Wall
{
public:
	int x, y, r;
	vector<Wall> childeren;
	Wall(int px, int py, int rad) :x(px), y(py), r(rad) {}
	bool operator<(const Wall& right) const
	{
		return r < right.r;
	}

	int leafLevel()
	{
		int maxlv =1;
		for (int i = 0; i < childeren.size(); ++i)
		{
			maxlv = max(childeren[i].leafLevel()+1, maxlv);
		}

		return maxlv;
	}
};


bool isContain(const Wall& w1, const Wall& w2) //w1이 w2에 포함되나?
{
	int x1 = w1.x, x2 = w2.x, y1 = w1.y, y2 = w2.y, r = w2.r;
	int X = (x1 - x2); X = X * X;
	int Y = (y1 - y2); Y = Y * Y;

	return (X + Y) <r*r;
}


int getHeight( Wall& cas)
{
	vector<int> heights;
	int max_height = 0;

	if (cas.childeren.size() == 0)
		return 0;

	for (int i = 0; i < cas.childeren.size(); ++i) {
		

		heights.push_back(cas.childeren[i].leafLevel());
		max_height = max(max_height, heights.back());
	}

	if (cas.childeren.size() > 1) {
		sort(heights.begin(), heights.end());
		max_height = max(max_height, heights[heights.size() - 1] + heights[heights.size() - 2]);
	}

	return max_height;
}

int main()
{
	int T = 0; cin >> T;

	while (T--)
	{
		int n = 0; cin >> n;
		vector<Wall> v;
		int x = 0, y = 0, r = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> x >> y >> r;
			v.push_back({ x,y,r });

		}
		sort(v.begin(), v.end());

		for (int i = 0; i < n; ++i)
		{


			for (int j = i + 1; j < n; ++j)
			{
				if (true == isContain(v[i], v[j])) {
					v[j].childeren.push_back(v[i]);
				
					break;
				}
			}
		}
		//트리 만들었음 
		/*int maxlv = 0, sublv = 0;
		for (int i = 0; i < v[n - 1].childeren.size(); ++i)
		{
			int r = v[n - 1].childeren[i].leafLevel();
			if (r >= maxlv) {
				sublv = maxlv;
				maxlv = r;
			}
			else if (r >= sublv)
			{
				sublv = r;
			}
		}*/

		int ret = getHeight(v[n - 1]);
		cout << ret << '\n';
	}
}