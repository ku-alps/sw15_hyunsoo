#include<iostream>
using namespace std;
// 간지 문제
// 단순한 규칙
// 다만 계산시작 점이 0이 아닌 4부터

#define BASE_YEAR 56

int main() {
	int year;
	cin >> year; //해를 입력받음

	int n10 = (year + BASE_YEAR) % 10; //십간
	int n12 = (year + BASE_YEAR) % 12; //십이지

	cout << (char)(n12 + 'A') << n10;
}