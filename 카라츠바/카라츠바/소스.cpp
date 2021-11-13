#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void normalize(vector<int>& c) {
	c.push_back(0);
	for (int i = 0; i + 1 < c.size(); i++) {
		if (c[i] < 0) {
			int borrow = (abs(c[i]) + 9) / 10;
			c[i + 1] -= borrow;
			c[i] += borrow * 10;
		}
		else {
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
	}
	while (c.size() > 1 && c.back() == 0) c.pop_back();
}
vector<int> multiply(const vector<int>& a, const vector<int>& b)
{
	vector<int> c(a.size() + b.size(), 0);
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j <b.size(); ++j) {
			c[i + j] += a[j] * b[i];
		}
	}

	normalize(c);
	//while (c.size() > 1 && c.back() == 0) c.pop_back();
	/*for (int i = c.size() - 1; i > 0; --i) 
	{
		c[i - 1] += c[i] / 10;
		c[i] = c[i] % 10;
	}
	*/

	//vector<int>ret(c.rbegin(), c.rend());

	return c;

}


void addTo(vector<int>& a, vector<int>& b,int k)
{
	int an = a.size(), bn = b.size();
	a.resize(max(an, bn + k));
	for (int i = 0; i < bn; i++) {
		a[i + k] += b[i];
	}
	normalize(a);
}

void subFrom(vector<int>& a, const vector<int>& b) {
	int an = a.size(), bn = b.size();
	a.resize(max(an, bn + 1));
	for (int i = 0; i < bn; i++) {
		a[i] -= b[i];
	}
	normalize(a);
}
vector<int> karatsuba(const vector<int>& a, const vector<int>& b)
{
	int an = a.size(); int bn = b.size();

	if (an < bn)return karatsuba(b, a);

	if (an == 0 || bn == 0) return vector<int>();
	
	if (an < 50)return multiply(a, b);

	int half = an / 2;
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half,a.end());

	vector<int> b0(b.begin(),b.begin()+min(bn,half));
	vector<int> b1(b.begin() + min(bn, half),b.end());

	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);
	addTo(a0, a1,0);
	addTo(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);
	
	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);

	return ret;
}

int main()
{
	vector<int> a{ 1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0};
	vector<int> b{ 1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0};
	
	vector<int> ret = karatsuba(a, b);
	
	for (auto d : ret)
		cout << d ;
	cout << endl;
	char s[10024];
	sprintf_s(s, "%d ", 1.524158e+118);
	cout << s << endl;

}