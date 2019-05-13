#include<iostream>
using namespace std;
// 동전 0
// 처음에 문제를 잘못 이해했음..
// 주어진 동전이 각각 하나씩 있다고 착각해서
// 풀이 방식이 감이 안온 문제

int val[10];
int main() {
	int num, money; // 동전 종류와 금액
	cin >> num >> money;

	for (int k = 0; k < num; k++) {
		cin >> val[k]; // 가치를 입력받음
	}

	int coin = 0; // 동전 총 수
	for (int k = num - 1; k >= 0; k--) {
		coin += money / val[k]; //코인이 차지하는 양
		money %= val[k]; //필요한 남은 돈
	}
	cout << coin << endl; //출력
}