#include<cstdio>
using namespace std;
// ����
// ��� ���踦 ���� ������ �����Ͽ� �Է��� �ܹ��� ������ ��ȯ
// �ܼ� Ž���� ��� ���� ���� ���� �ð��ʰ��� �߻��ϹǷ�,
// ��� ��ο� ���� ������ ���� ó�� ��, ������ ������ ����

#define NUM 400

int map[NUM + 1][NUM + 1]; // a ���� b ���� ��Ұ��谡 �����ϴ°�?

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	for (int k = 0; k < K; k++) {
		int a, b;
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
		// ��� �����̹Ƿ�, ���⼺�� ���� �ִٰ� ������ �� ���� ( ���� ��� -> ���� ��� )
	}
	
	// �÷��̵�-���� ����
	for (int k = 1; k <= N; k++) { // k �� ���� ���� ���
		for (int m = 1; m <= N; m++) {
			for (int i = 1; i <= N; i++) { // �� ��ü ���� ( �� ����� ��ȣ�� 1~N ���� )
				map[m][i] = map[m][i] || (map[m][k] && map[k][i]); 
				// ���� ��Ұ��谡 ��Ȯ�ϰų�, �ش� ����� ��Ұ��谡 ��� ��Ȯ�� ��� OK
			}
		}
	}

	int S;
	scanf("%d", &S);
	while (S--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", map[b][a] - map[a][b]);
		// a �� ���� ����� ���, map[a][b] �� ���� ����� ( -1 ��� )
		// a �� ���� ����� ���, map[b][a] �� ���� ����� ( 1 ��� )
		// �� �ܿ� �����ϴ� ��ΰ� ��Ȯ���� �����Ƿ� ��� 0 ���
	}
}