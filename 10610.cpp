#include<iostream>
#include<string>
#include<cmath>
using namespace std;
// 30
// 30이라는 값은 3*10 으로 분리하여 볼 수 있음
// 우선 주어진 값으로 30의 배수를 만들기 위해서는 0이 필요
// 또한, 3의 배수가 되어야 하는 조건 상, 각 자리수 값의 합이 3의 배수가 되어야 함
// 해당 조건을 만족하는 경우, 값을 구성할 수 있으며,
// 가장 큰 값을 출력해야 하므로, 큰 원소값부터 앞 자리에 선택

int num[10]; // 입력된 원소들의 수 카운팅

int main() {
	string str;
	cin >> str;

	for (int k = 0; k < str.length(); k++) {
		num[str[k] - '0']++; // 각각 원소들을 분석
	}

	int sum = 0;
	string ans = "";
	int max = 0; // 출력값
	for (int k = 9; k > 0; k--) {
		if (num[k]) { // 0이 아니라면
			sum += k * num[k]; // 등장한 원소들을 전부 더함
			while (num[k]--) {
				ans.push_back(k + '0'); // 최대값 구성
			}
		}
	}
	if (sum && !(sum % 3) && num[0]) // 총 합이 3의 배수이고, 0 값이 등장했으면
		for (int k = 0; k < num[0]; k++)
			ans.push_back('0');
	else
		ans = "-1"; // 그 외 조건이 성립하지 않으면 못만듦

	cout << ans << endl;
}