#include<iostream>
using namespace std;
// 뒤집힌 덧셈

int reverse(int val); // 숫자를 뒤집는 함수
int r_add(int a, int b); // 문제가 요구한 함수

int main() {
	int a, b;
	cin >> a >> b; // 입력
	cout << r_add(a, b) << endl;
}

int reverse(int val) {
	int make = 0;
	while (val != 0) { // 입력값이 0이 아니면 반복
		make *= 10;
		make += val % 10;
		val /= 10;
	}
	return make; // 뒤집힌 수를 반환
}

int r_add(int a, int b) {
	return reverse(reverse(a) + reverse(b));
}