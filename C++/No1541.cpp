#include<iostream>
#include<string>
using namespace std;
// �Ҿ���� ��ȣ
// '�ּڰ�'�� �Ǳ� ���ؼ�
// �ִ��� ū ������ ������ �Ѵٴ� ��Ģ�� ���

int main() {
	string str;
	cin >> str; //���ڿ��� �Է¹ް� ó���� ����

	int sign = 1; // ��ȣ ����. ù ���� ����� ��� ����ó���� ����
	int total = 0; // ��ü ��
	int calc = 0; // ���� �߰� ��
	int num = 0; // �� ���� �ϳ��ϳ�

	for (char c:str) { // ���ڿ� �ȿ� �ִ� �� ���� c�� ���ؼ�
		if (c == '-' || c == '+') { // �����ڸ� ���� ���
			calc += num; //���� �Ѽ�Ʈ�� ������ ����
			num = 0; // ���� �ʱ�ȭ
			if (c == '-') { //������ȣ�� ���
				total += calc * sign; 
				calc = 0; // ��ü ��� ���� �� �ʱ�ȭ
				sign = -1; // ���� ��Ȳ�� ���� ����
			}
		}
		else  // ������ ���
			num = num * 10 + (c - '0'); //���� ����
			// ���� ������ 10�� �ڸ��� �ø��� 1�� �ڸ��� ����
	}
	calc += num; // ������ ���ڴ� �����ڸ� ������ ���� ������ �ȵǹǷ� ���� ó��
	total += calc * sign;
	
	cout << total << endl;
}