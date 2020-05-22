#include<iostream>
#include<string>
using namespace std;
// 소수를 분수로
// 주어진 무한소수를 분수로 표현하기 위해서
// 반복 구간을 제거하는 방식의 규칙을 사용

long long int G(long long int a, long long int b) { // 유클리드 호제법 (GCD)
	while (b != 0) {
		long long int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	int loop;
	cin >> loop;

	for (int k = 0; k < loop; k++) {
		string str;
		cin >> str; // 괄호가 포함되므로 문자열 형태로 입력

		bool flag = false;
		long long int val = 0;
		long long int mul = 1; // 비 반복구문
		long long int a_val = 0;
		long long int a_mul = 1; // 반복구문
		for (int m = 2; m < str.length(); m++) { // 입력된 문자열에 대해
			switch (str[m]) {
			case '(': // 괄호인 경우 무한구문 시작
				flag = true;
				break;
			case')': // 괄호가 닫힌 경우 예외처리
				break;
			default: // 그 외의 모든 경우는 숫자부
				a_val *= 10; 
				a_val += str[m] - '0'; // 실제 값을 연산

				if (flag) { // 반복구문인 경우
					a_mul *= 10;
				}
				else { // 비 반복구문인 경우
					val *= 10;
					val += str[m] - '0';
					mul *= 10;
				}
				break;
			}
		}

		long long int t_mul = mul * a_mul; // 전체 분모 값
		if (!flag) { // 반복구문이 없다면 분자, 분모에서 뺄 값도 없음
			mul = 0;
			val = 0;
		}

		long long int prnt = t_mul - mul;
		long long int cld = a_val - val;
		long long int gcd = G(prnt, cld);
		cout << cld / gcd << "/" << prnt / gcd << endl; // 등호식에 따라 연산 후 출력
	}
}
