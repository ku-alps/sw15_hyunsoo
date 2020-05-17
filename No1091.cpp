#include<iostream>
#include<unordered_map>
using namespace std;
// 카드 섞기
// 이해과정에서 걸린 문제
// 카드를 나눠주면서 섞는 것이 아닌, 모두 섞은 후 한 번에 나눠 줌
// so, 단순히 중복을 체크하는 시뮬레이션 구현으로 해결 가능

#define NUM 48

int N, card[NUM], shuffle[NUM]; // 카드 수, 현재 카드가 놓인 순서, 뒤섞는 규칙
unordered_map<string, bool> m; // 중복 체크용 맵

int main() {
	cin >> N;

	string ans = ""; // 정답 문자열
	for (int k = 0; k < N; k++) { // 수를 입력받아 하나의 정답 문자열을 생성
		int num;
		cin >> num;
		ans += ('0' + num);
	}
	m[ans] = true;

	// 카드 섞는 규칙 + 카드 초기화
	for (int k = 0; k < N; k++) {
		cin >> shuffle[k];
		card[k] = k;
	}

	int cnt = 0; // 실제 출력값
	string str; // 비교용 문자열
	for (int k = 0; k < N; k++) str.push_back(k % 3 + '0'); // 초기 카드 배분 상태
	for (; !m[str]; cnt++) { // 중복이 등장하기 전까지 반복
		m[str] = true; // 해당 배분 상태가 등장함을 표기

		int save[NUM] = {};
		for (int k = 0; k < N; k++) save[k] = card[k]; // 카드 복사
		for (int k = 0; k < N; k++) card[shuffle[k]] = save[k]; // 카드 이동
		for (int k = 0; k < N; k++) str[card[k]] = (k % 3 + '0'); // 새로운 배분 상태
	}
	cout << (ans == str ? cnt : -1) << endl; // 출력
}