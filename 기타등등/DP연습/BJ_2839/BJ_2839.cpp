#include <iostream>
using namespace std;


int N;

int memo[5000];
int five;
int three;
int result(int n)
{

	five = n / 5;

	int r = n % 5;

	if ( r < 5)
	{
		five = 0;
		three = n / 3;
		r = n % 3;
		if (r != 0)
			return -1;
		else
			return three;
	}
	three = r / 3;
	if (( r % 3 )!= 0)
		return -1;
	else
		return five + three;


}
int main()
{
	cin >> N;

	cout << result(N) << '\n';

}