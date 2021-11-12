#include <iostream>
using namespace std;


int A = 0;
int B = 0;
int M[2000][2000];


int main()
{
	cin >> A;
	cin >> B;
	int n = 1;
	for (int i = 0; i < A; ++i)
	{
		for (int j = 0; j < B; ++j){
			M[i][j] = n;
			n++;
		}
	}

	printf("M\n");
	for (int i = 0; i < A; ++i)
	{
		for (int j = 0; j < B; ++j)
			printf("%d ", M[i][j] );
		printf("\n");
	}
	printf("R\n");
	for (int i = 0; i < B; ++i) {
		for (int j = A-1; j >=0; --j)
			printf("%d ",M[j][i]);
		printf("\n");
	}
	printf("L\n");
	for (int i = B-1; i >=0; --i) {
		for (int j = 0; j <A; ++j)
			printf("%d ", M[j][i]);
		printf("\n");
	}
	printf("T\n");;
	for (int i = 0; i <B; ++i) {
		for (int j = 0; j < A; ++j)
			printf("%d ", M[j][i]);
		printf("\n");
	}

}