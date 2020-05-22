#include<iostream>
#include<algorithm>
using namespace std;
// LCS
// 기본적으로 최장 공통 부분 수열은 dp 문제이며
// 길이만 얻으면 충분하므로, 갱신시킨 방향은 기록하지 않음

#define NUM 1000

int comp[NUM + 1][NUM + 1]; // a, b 지점까지 얻을 수 있는 LCS 값
string str[2]; // 2개의 문자열

int main() {
	cin >> str[0] >> str[1];
	for (int k = 0; k < str[0].length(); k++) { // 각 문자열을 0~N 까지 사용하는 경우 얻는 LCS 값을 계산
		for (int m = 0; m < str[1].length(); m++) {
			// 세 경우 중 하나를 비교하여 큰 값을 취함
			comp[k + 1][m + 1] = max({ comp[k + 1][m], comp[k][m + 1], comp[k][m] + (str[0][k] == str[1][m]) });
		}
	}
	cout << comp[str[0].length()][str[1].length()] << endl; // 두 문자열로 얻을 수 있는 LCS 값 출력
}
