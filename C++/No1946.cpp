//���� ���
// �� ���� ������ �ǹǷ�
// ���� ������ �켱 ���� ��, ��

#include<iostream>
using namespace std;

class Employee {
	// ���
public:
	int document; // ��������
	int interview; // ��������
	bool is_ok;
	Employee() {}
	Employee(int i_doc, int i_int);
};

int main() {
	int loop;
	cin >> loop; // �ݺ� Ƚ��

	for (int k = 0; k < loop; k++) {
		int person;
		cin >> person; //��� ��
		Employee** e = new Employee*[person];

		int how_many = 0; //���� �� �ִ� �ο� ��
		for (int i = 0; i < person; i++) {
			int doc, inter;
			cin >> doc >> inter;
			e[i] = new Employee(doc, inter); //���� ������ ��

			for (int j = 0; j < i; j++) {
				if (e[i]->document > e[j]->document && e[i]->interview > e[j]->interview) {
					// ���� ��������, ���ͺ信�� ��� �и��� ���
					// Ż��
					e[i]->is_ok = false;
					break; //�ش� �ݺ����� ���̻� �� �ʿ䰡 ����
				}
				else if (e[i]->document < e[j]->document && e[i]->interview < e[j]->interview) {
					// �ݴ�� ���� �����ڰ� �и��� ���
					// ���� �����ڴ� Ż���ؾ���
					if (e[j]->is_ok) {
						e[j]->is_ok = false;; //�ش� �ο� Ż�� (����)
						how_many--;
					}
				}
			}
			if (e[i]->is_ok) //��ο� ������ �� �и��� ������
				how_many++; //���� Ȯ�� ����
		} // �迭 �Է� �Ϸ�
		cout << how_many << endl;
	}
}

Employee::Employee(int i_doc, int i_int) {
	document = i_doc;
	interview = i_int; // �� �Է� ������
	is_ok = true; //�ϴ��� �հ� ����
}