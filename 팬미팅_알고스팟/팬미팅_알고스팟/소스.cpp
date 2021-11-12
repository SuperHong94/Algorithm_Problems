#include <iostream>
#include <string.h>
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
void addTo(vector<int>& a, const vector<int>& b, int k) {
	int an = a.size(), bn = b.size();
	a.resize(max(an, bn + k));
	for (int i = 0; i < bn; i++) {
		a[i + k] += b[i];
	}
}

void subFrom(vector<int>& a, const vector<int>& b) {
	int an = a.size(), bn = b.size();
	a.resize(max(an, bn + 1));
	for (int i = 0; i < bn; i++) {
		a[i] -= b[i];
	}
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	int an = a.size(), bn = b.size();
	vector<int> ret(an + bn + 1, 0);
	for (int i = 0; i < an; i++) {
		for (int j = 0; j < bn; j++) {
			ret[i + j] += (a[i] * b[j]);
		}
	}
	normalize(ret);
	return ret;
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b)
{
	int an = a.size(), bn = b.size();

	if (an < bn) return karatsuba(b, a);
	if (an == 0 || bn == 0) return vector<int>();
	if (an <= 50) return multiply(a, b);

	int half = an / 2;
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> b0(b.begin(), b.begin() + min(half, bn));
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b1(b.begin() + min(half, bn), b.end());

	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);

	addTo(a0, a1, 0);
	addTo(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half * 2);

	return ret;
}

char menbers[200000];
char fens[200000];

bool solv(int begin, int end, int mB, int mE)
{
	/*if (begin == end)
	{
		switch (menbers[mB])
		{
		case 'F':
			return true;
			break;
		case 'M':
			return fens[begin] == 'F';

			break;
		default:
			break;
		}
	}
	else {
		int mid = (begin + end) / 2;
		int mmid = (mB + mE) / 2;
		if (solv(begin, mid,mB,mmid) == false)
			return false;

		if (solv(mid + 1, end,mmid+1,mE) == false)
			return false;

		return true;
	}*/

	for (int i = 0; i < strlen(menbers); ++i) //이거는 시간초과란 말이야
	{
		switch (menbers[i])
		{
		case 'F':
			break;
		case 'M':
			if (fens[begin + i] != 'F')
				return false;
			break;
		default:
			break;
		}
	}
	return true;
}

int solv2(int begin, int end)
{
	int memlen = strlen(menbers);
	if (begin + memlen - 1 >= strlen(fens))
		return false;
	if (end - begin == memlen - 1) {
		for (int i = 0; i < memlen; ++i) //이거는 시간초과란 말이야
		{
			switch (menbers[i])
			{
			case 'F':
				break;
			case 'M':
				if (fens[begin + i] != 'F')
					return 0;
				break;
			default:
				break;
			}
		}
		return 1;
	}
	else if (end - begin < memlen - 1)
		return 0;
	else
	{
		int mid = (begin + end) / 2;
		int ret = solv2(begin, mid);
		ret += solv2(mid + 1, end);
		ret += solv2(begin + 1, mid);
		return ret;
	}
}
int moveFens()
{
	int b = 0;
	int e = strlen(menbers) - 1;
	int ret = 0;
	while (e < strlen(fens))
	{
		if (solv(b, e, 0, strlen(menbers) - 1) == true)
			ret++;
		b++;
		e++;
	}
	return ret;
}
int main()
{

	vector<int>a = { 1,2,3,4,5,6 };
	vector<int>b = { 1,2,3,4,5 };
	vector<int> ret = karatsuba(a, b);
	int r = 0;
	for (int i = ret.size() - 1; i >= 0; --i)
		cout << ret[i];

	/*int c = 0; cin >> c;
	for (int i = 0; i < c; ++i)
	{
		cin >> menbers;
		cin >> fens;
		cout << solv2(0, strlen(fens) - 1)<<endl;
	}*/
}