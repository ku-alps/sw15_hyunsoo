#include<iostream>
#include<string>
using namespace std;
// 30
// 3 의 배수는 각 자릿수의 합이 3의 배수가 된다는 특징
// 10의 배수는 1의 자릿수가 0이라는 특징
// 두 조건을 모두 성립하는가를 우선적으로 판단 후,
// 가장 큰 값을 출력해야하므로 보유한 원소 중 큰 값부터 순차적으로 출력

int cnt[10]; // 0~9 까지 등장한 횟수 (카운팅 소트)

int main() {
	string num;
	cin >> num; // 각 숫자 하나하나를 봐야하므로 문자열 형태로 받음

	int sum = 0;
	for (int k = 0; k < num.length(); k++) { // 입력받은 문자열의 원소들에 대해
		int val = num[k] - '0'; // 실제 숫자값으로 변환
		cnt[val] += 1;
		sum += val; // 총 합
	}
	if (cnt[0] && !(sum % 3)) { // 조건 판단
		for (int k = 9; k >= 0; k--) {
			for (int m = 0; m < cnt[k]; m++) {
				cout << k; // 큰 수부터 출력
			}
		}
	}
	else cout << -1; // 실패 시 -1 출력
}