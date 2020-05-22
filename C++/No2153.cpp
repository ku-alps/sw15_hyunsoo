#include<iostream>
#include<string>
#include<cmath>
using namespace std;
// 소수 단어
// 'A' 의 아스키코드 값이 'a' 보다 큼
// 따라서 예외처리가 필요

int main() {
	string str;
	int sum = 0;

	cin >> str;

	for (int k = 0; k < str.length(); k++) {
		if (str.at(k) >= 'a')
			sum += str.at(k) - 'a' + 1; // 소문자인 경우
		else
			sum += str.at(k) - 'A' + 27; // 대문자인 경우
	}

	for (int k = 2; k <= sqrt(sum); k++) { // 최대 루트까지 살펴봄
		if (sum%k == 0) { // 중간에 딱 나눠지는 수가 있다면 합성수
			cout << "It is not a prime word." << endl;
			return 0;
		}
	}
	cout << "It is a prime word." << endl; // 반복문을 정상적으로 나오면 소수
	return 0;
}