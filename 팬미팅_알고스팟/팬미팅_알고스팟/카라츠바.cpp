#include "카라츠바.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b.size(); j++)
			c[i + j] += (a[i] * b[j]);
	return c;
}
void addTo(vector<int>& a, const vector<int>& b, int k)
{
	a.resize(max(a.size(), b.size() + k));
	for (int i = 0; i < b.size(); i++)
		a[i + k] += b[i];
}

void subFrom(vector<int>& a, const vector<int>& b)
{
	a.resize(max(a.size(), b.size()) + 1);
	for (int i = 0; i < b.size(); i++)
		a[i] -= b[i];
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b)
{
	int an = a.size(), bn = b.size();

	//짧을경우 순서바꾸기
	if (an < bn)return karatsuba(b, a);

	//a나 b가 비어있는경우
	if (an == 0 || bn == 0)return vector<int>();


	//자리수가 작으면 multiply곱으로 하는게 이득이다.
	if (an <= 50)return multiply(a, b);

	int half = an / 2;
	int bhalf = bn / 2;
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(bn,half));
	vector<int> b1(b.begin() + min<int>(bn, half), b.end());
	
	//z0
	vector<int> z0 = karatsuba(a1, b1);
	//z2;
	vector<int> z2 = karatsuba(a0, b0);
	//z2;
	addTo(a0, a1,0);
	addTo(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	
	vector<int> ret;
	addTo(ret, z0, half + half);
	addTo(ret, z1, half);
	addTo(ret, z2, 0);

	return ret;

	
}
