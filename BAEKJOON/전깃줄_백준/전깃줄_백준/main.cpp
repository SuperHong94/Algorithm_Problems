#include <iostream>
#include <memory.h>
using namespace std;



//��� Ǯ��? ���⸸�ϸ�ȴ�.
//������ �̾���� ���� �Ѱ� �������� ���־��ϴ� �ּ� ������ 0
//�̾���� ���� 2���̰� ���������� ���־��ϴ� ���� 1��
//�̾���� ���� 3���̰� ���������� ��������� 2��  �ƴϸ� 1��
//�� ����(����)�ִٴ� ���� ��� ����?
//���⼱�� ��ȣ�� ����Ǿ��ִ�. ex) 1, 3 
/*
1 , 3
2, 1
�̷��� ����
1, 3
2, 4
�̷��� ������

1, 5
2, 3
3, 2
�̷��� ����

���� �� ������ȣ�� �տ� �ι�����ȣ�麸�� �����ΰ��� ���̴� ���� !
������ ���� �տ� �ι�����ȣ�� �ڿ� �ι��� ��ȣ���� ũ�� ����


�׷��� ���� �ڷᱸ���� ����ұ�?
2�����迭�� �ϴ°� ���ҵ� �׷����ϸ� �������⵵ ���ϰ� �̾��� ���°� 0, 1�� ǥ���� �� �־ ���ҵ�

�����Ǵ� �͵� �˾Ұ� �ڷᱸ���� �˾����� ���� �ּ������� ��� ������?

��� 1.
1������ n������ ������ ���鼭 �ش��ٰ� �����ϸ� ���´�. �ð����⵵? n(������)*(n���� �Ȳ��ε鼱���� �ױ������� ���� ���⼭ ������ȹ���� �� �ְڱ�)

*/


int lines[502];//���� 1, 200�����̸� lines[1][0]=200; �̷����Ҳ���
int copylines[502];
int cache[502];
int N;
int MIN = 100;

int CutCrossline(int point)
{

	int ret = 0;

	cache[point] = 1;  //�湮
	for (int i = 1; i <= 500; ++i) {  //��ģ�� ���� ����
		if (cache[i] != 0)continue;//�̹� �ڸ�����
		if (copylines[i] != 0) {
			if (point < i) {
				if (copylines[point] > copylines[i]) {
					ret += 1;
					cache[i] = 1;// ������ ġ��

				}
			}
			else if (point > i) {
				if (copylines[point] < copylines[i]) {
					ret += 1;
					cache[i] = 1;
				}
			}

		}
	}

	//copylines[point] = 0;
	int minRet = 0;
	for (int i = 1; i <=500; ++i) {
		if (copylines[i] == 0) continue;
		if (cache[i] == 0){
			cache[i] = 1;
			minRet = min(minRet, CutCrossline(i));
			cache[i] = 0;
		}
	}

	return ret;
}
int main()
{
	cin >> N;
	int a = 0, b = 0;//�� ��
	for (int i = 0; i < N; ++i) {
		cin >> a >> b;
		lines[a] = b;

	}

	for (int i = 1; i <= 500; ++i) {
		if (lines[i] == 0) continue;
		memcpy(copylines, lines, sizeof(lines));
		memset(cache, 0, sizeof(cache));
		//CutCrossline(i);
		MIN = min(MIN, CutCrossline(i));
	}

	//for (int i = 0; i < 501; i++) {
	//	if (cache[i] == 0)continue;
	//	MIN = min(MIN, cache[i]);
	//}
	cout << MIN << endl;
}