#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
// �˹�
// �������� �����ϴٴ� ������ �������
// �ּҰ��� ���� ���� ������ ���� 0���� ����� ���
// ���� ������ ����Ž������ ã���� ������ �ð��ʰ��� GCD ����� ������ ���

int N; // ���� ����
int num[100]; // �ִ� 100������ ���� ����

int GCD(int a, int b) { // �ִ����� ���ϱ�
	if (!b) return a; // b�� 0�̶�� (�� ����������) a�� �ִ�����
	return GCD(b, a % b); // ������� �ƴ϶�� ��Ģ���� �ɰ�
}

int main() {
	// �Է�
	cin >> N;

	int minVal = 1000000000; // �ּҰ�0
	int maxVal = 0; // Ž�� �ִ�ġ
	for (int k = 0; k < N; k++) {
		cin >> num[k]; // �Է�
		minVal = min(minVal, num[k]); // �ּҰ� ����
	}
	for (int k = 0; k < N; k++) {
		num[k] -= minVal; // �������� 0�� �ǵ��� ����
		maxVal = max(maxVal, num[k]); // �ִ밪 ����
	}
	
	// ���� ������ ���� �ִ����� ã��
	int gcd = maxVal; // �ϴ� ���� �� ���� ū ������ ����
	for (int k = 0; k < N; k++) { // ��� ���ҵ��� ������� gcd ã��
		// ū ���� ������ �־ �Լ� ȣ��
		gcd = num[k] > gcd ? GCD(num[k], gcd) : GCD(gcd, num[k]);
	}

	// GCD ������� ���� �����
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(gcd); // �ڱ� �ڽ��� �׻� ����
	for (int k = 2; k <= sqrt(gcd); k++) {
		if (!(gcd % k)) { // �� �������� ���̸�
			pq.push(k); // �ĺ� ����
			if (k != sqrt(gcd)) pq.push(gcd / k);
			// ��Ʈ�� �ߺ��Ǵ� ���� �ƴϸ� �� �ݴ뵵 ����
		}
	}

	// ���
	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}
}