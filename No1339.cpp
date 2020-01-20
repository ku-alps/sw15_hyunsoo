#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
// 단어 수학
// 가장 큰 수 조합을 만드는 것이 목표이므로,
// 단순 규칙을 사용하여 풀이

int alpha[26]; // 알파벳 크기만큼의 배열

int main() {
	int line;
	cin >> line; 

	for (int k = 0; k < line; k++) {
		string str; // 문자열 입력
		cin >> str;

		for (int m = 0; m < str.length(); m++) { // 각 문자 종류를 카운팅
			alpha[str.at(m) - 'A'] += (int)pow(10, str.length() - (m + 1));
			// 다만, 각 문자의 위치에 따라 값이 달리지므로, 주의
		}
	}
	sort(&alpha[0], alpha + 26); // 정렬

	int sum = 0, number = 9; // 많이 등장한 수에 내림차순으로 수를 부여
	for (int k = 25; k >= 0; k--) {
		if (alpha[k] == 0) break;
		sum += alpha[k] * number;
		number--;
	}

	cout << sum << endl; // 합 출력
}