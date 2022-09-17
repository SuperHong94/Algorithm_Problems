//https://algospot.com/judge/problem/read/FORTRESS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Wall
{
public:
	int x, y, r;
	Wall(int _x, int _y, int _r) :x(_x), y(_y), r(_r) {}

	vector<Wall*> children; //포함되는녀석

	bool operator<(const Wall& right)const
	{
		return r < right.r;
	}



};



int longest;
int height(Wall* root)
{
	vector<int> heights;
	for (int i = 0; i < root->children.size();++i)
	{
		heights.push_back(height(root->children[i]));
	}
	if (heights.empty())return 0;
	sort(heights.begin(), heights.end());
	if (heights.size() >= 2)
		longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);

	return heights.back() + 1;
}


bool IsContain(const Wall& a, const Wall& b) //a가 b에 포함되는가?
{
	int dx = a.x - b.x;
	int dy = a.y - b.y;
	int r = b.r;
	dx = dx * dx;
	dy = dy * dy;
	r = r * r;

	return dx + dy < r;


}


int main()
{
	int T = 0; cin >> T;

	while (T--)
	{
		int N = 0; cin >> N;

		int x = 0, y = 0, r = 0;
		vector<Wall> v;
		for (int i = 0; i < N; ++i)
		{
			cin >> x >> y >> r;
			v.push_back({ x,y,r });
		}
		sort(v.begin(), v.end());

		for (int i = 0; i < N - 1; ++i)
		{
			for (int j = i + 1; j < N; ++j)
			{
				if (true == IsContain(v[i], v[j]))
				{
					v[j].children.push_back(&v[i]);
					break;
				}
			}
		}
		longest = 0;
		int h = height(&v[N - 1]);
		
		cout << max(longest, h) << '\n';



	}

}