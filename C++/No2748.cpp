#include<iostream>
using namespace std;
// 피보나치 수 2
// 입력된 횟수만큼 반복문으로 피보나치 수열을 계산

int main() {
	long long int num;
	cin >> num;

	long long int a = 0, b = 1;
	for (int k = 0; k < num; k++) { // 피보나치 계산 반복문
		long long int c = a + b;
		a = b;
		b = c;
	}

	cout << a << endl; // 출력
}