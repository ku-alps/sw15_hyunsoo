#include<iostream>
using namespace std;
// 이항 계수 1

int main() {
	int num, sel;
	cin >> num >> sel;

	int a = 1, b = 1;
	for (int k = 0; k < sel; k++) { // 순열
		a *= (num - k);
	}
	for (int k = 1; k <= sel; k++) { // 경우 수에서 중복 제거
		b *= k;
	}
	cout << a / b << endl; // 조합
}