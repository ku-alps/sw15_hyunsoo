#include<iostream>
#include<string>
using namespace std;
// 30
// 3 �� ����� �� �ڸ����� ���� 3�� ����� �ȴٴ� Ư¡
// 10�� ����� 1�� �ڸ����� 0�̶�� Ư¡
// �� ������ ��� �����ϴ°��� �켱������ �Ǵ� ��,
// ���� ū ���� ����ؾ��ϹǷ� ������ ���� �� ū ������ ���������� ���

int cnt[10]; // 0~9 ���� ������ Ƚ�� (ī���� ��Ʈ)

int main() {
	string num;
	cin >> num; // �� ���� �ϳ��ϳ��� �����ϹǷ� ���ڿ� ���·� ����

	int sum = 0;
	for (int k = 0; k < num.length(); k++) { // �Է¹��� ���ڿ��� ���ҵ鿡 ����
		int val = num[k] - '0'; // ���� ���ڰ����� ��ȯ
		cnt[val] += 1;
		sum += val; // �� ��
	}
	if (cnt[0] && !(sum % 3)) { // ���� �Ǵ�
		for (int k = 9; k >= 0; k--) {
			for (int m = 0; m < cnt[k]; m++) {
				cout << k; // ū ������ ���
			}
		}
	}
	else cout << -1; // ���� �� -1 ���
}