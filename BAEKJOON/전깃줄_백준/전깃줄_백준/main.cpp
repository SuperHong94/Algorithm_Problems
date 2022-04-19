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


int lines[501];//���� 1, 200�����̸� lines[1][0]=200; �̷����Ҳ���
int copylines[501];
int cache[501];
int N;
int MIN = 100;

int CutCrossline(int point)
{
	if (cache[point] != 0)
		return cache[point];
	for (int i = 0; i < 501; ++i) { //�ڱ� ���������°� ���ڸ���
		if (copylines[i] == 0) continue;

		if (i > point) {
			if (copylines[i] > copylines[point]) {
				copylines[i] = 0;
				cache[point] += 1;
			}
		}
		else if (i < point) {
			if (copylines[i] > copylines[point]) {
				copylines[i] = 0;
				cache[point] += 1;
			}
		}
	}

	//�ߺ��� ��������
	copylines[point] = 0;

	for (int i = point + 1; i < 501; ++i) { //���ڸ��ſ��� ��͵���
		if (copylines[i] == 0) continue;

		if (copylines[i] == 1)
			cache[point] += CutCrossline(i);
	}
	return cache[point];

}
int main()
{
	cin >> N;
	int a = 0, b = 0;//�� ��
	for (int i = 0; i < N; ++i) {
		cin >> a >> b;
		lines[a] = b;

	}

	for (int i = 0; i < 501; ++i) {
		if (lines[i] == 0) continue;
		memcpy(copylines, lines, sizeof(lines));
		CutCrossline(i);
		//MIN = min(MIN, CutCrossline(i));
	}

	for (int i = 0; i < 501; i++) {
		if (cache[i] == 0)continue;
		MIN = min(MIN, cache[i]);
	}
	cout << MIN << endl;
}