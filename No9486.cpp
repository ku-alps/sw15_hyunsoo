#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
// 이름 남기기
// 주어진 문자에 대해 어떤 문자를 먼저 처리하는가에 따라 답이 달라짐
// so, 가장 마지막에 처리한 정보와 입력한 문자 정보로 정보를 구분하여 관리
// 입력 문자열의 길이는 최대 18 글자이므로, 비트마스킹을 사용

#define ALP 26
#define STR 18 // 입력 문자 최대 길이
#define BIT ( 1 << STR ) // 비트마스킹
#define INF 1000 // default 값

string str;
int visit[STR][BIT]; // 커서 위치, 작성된 글자 정보

int Calc(int cur, int bit, char alp) { // 현재 커서 위치, 기록된 문자 정보, 현재 알파벳
	if (visit[cur][bit]) return visit[cur][bit]; // 방문한 기록이 있다면 사용
	if (bit == (1 << str.length()) - 1) return 0; // 모든 문자를 다 채웠다면 반환

	visit[cur][bit] = INF;
	for (int k = 0; k < str.length(); k++) {
		if (bit & (1 << k)) continue; // 해당 글자가 이미 있다면 건너감

		int move = 0;
		if (k < cur) { // 현재 위치보다 앞에 등장하는 놈이면
			for (int m = k; m <= cur; m++) {
				if (bit & (1 << m)) move += 1;
				// 사이에 존재하는 문자만큼 건너뛰어야함
			}
		}
		else { // 뒤에 등장하는 놈이면
			for (int m = cur + 1; m < k; m++) { // 현재 커서 다음부터 고려
				if (bit & (1 << m)) move += 1;
			}
		}

		int btw = abs(str[k] - alp);
		int updown = min(btw, ALP - btw); // 위, 아래 중 더 적은 변화를 선택

		// 재귀 함수 + 커서 이동 값 + 문자 변환값 + 입력 (1)
		int calc = Calc(k, bit | (1 << k), str[k]) + move + updown + 1;
		visit[cur][bit] = min(visit[cur][bit], calc); // 가능한 경우 중, 최소를 선택
	}
	return visit[cur][bit];
}

int main() {
	do {
		cin >> str;
		if (str == "0") break; // 종료 문자열이면 종료

		memset(visit, 0, sizeof(visit)); // 미모아이제이션 배열 초기화

		int ans = INF;
		for (int k = 0; k < str.length(); k++) {
			ans = min(ans, Calc(k, 0, 'A'));
		}
		cout << ans << endl; // 정답 출력
	} while (true);
}