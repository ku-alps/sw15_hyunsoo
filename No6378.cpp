// ������ ��Ʈ
// 1�� �ڸ��� 10���� �÷� ���ع�����
// 10�� �ڸ��� 1�� �ڸ��� ������� ���
// ������ �ø��� ��� ���� ���ܵ�
// �ٽ� ���ϴ� ����� �ݺ��ϱ� ������ ����
// �ٸ�, �����÷ο� ������ getchar�� ���ڿ� �Է��� ����

#include<iostream>
using namespace std;

int main(){

	int num;
	do {
		num = 0; // ���� �ʱ�ȭ
		while (true) {
			int get = getchar();
			if (get != '\n')
				num += get - '0'; 
				// �������·� �Է¹����Ƿ� '0'����ŭ ��
			else // ���Ͱ� ������ �ݺ��� ��
				break;
		}
		while (num >= 10) {
			// 10���� ũ�� ��� �ݺ�
			num += (num % 10) * 10;
			num /= 10; // ����
		}
		if(num != 0)
			cout << num << endl;
	} while (num != 0);
		// �Է°��� 0�� �ƴϸ� ��� ����
}