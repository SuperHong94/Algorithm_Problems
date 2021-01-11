//#include <iostream>
//#include <memory.h>
//using namespace std;
//
//int N = 0;
//int* lopes = nullptr;
//int result = 0;
//int myindex = 0;
//
//int sol(int num);
//int main()
//{
//
//	cin >> N;
//
//	lopes = new int[N];
//	memset(lopes, -1, sizeof(N));
//
//	for (int i = 0; i < N; i++) {
//		cin >> lopes[i];
//	}
//	cout << sol(N);
//
//	if (lopes)
//		delete[] lopes;
//}
//
//int sol(int num)
//{
//	int minValue = 99999;
//	for (int i = 0; i < N; i++)
//	{
//		if (lopes[i] <= minValue && lopes[i] != -1) {
//			minValue = lopes[i];
//			myindex = i;
//		}
//	}
//	lopes[myindex] = -1;
//	if (result > minValue * num)
//		//return result;
//		result = minValue * num;
//	sol(num - 1);
//	if (num == 1)
//		return result;
//
//}

//#include <iostream>
//#include <memory.h>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	int N = 0;
//	int max = 0;
//	int temp = 0;
//	cin >> N;
//
//	int* lopes = new int[N];
//	for (int i = 0; i < N; i++)
//		cin >> lopes[i];
//	
//	sort(lopes, &lopes[N], [](int a, int b) {return a > b; });
//
//	for (int j = 0; j < N; j++)
//	{
//		temp = lopes[j] * (j + 1);
//		if (max < temp)
//			max = temp;
//	}
//	cout << max;
//
// 
//}