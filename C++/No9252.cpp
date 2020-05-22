#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
// LCS 2
// DFS 기반으로 각 case 에 대한 비교탐색이 빠르게 이루어져야 함
// so, 메모아이제이션 기법을 사용

// 또한 단순히 길이만을 받는 것이 아닌, 이를 통해 얻는 문자열을 출력해야하므로
// 각 정보를 갱신시키는 방향의 저장이 필요

#define MAX 4000 // 문자길이 최대 4000

int datas[MAX][MAX], visit[MAX][MAX]; // 해당 위치에서 연속된 최대 길이
int link[MAX][MAX]; // 0: 대각선, 1: 왼쪽, 2: 위쪽
string str1, str2;
stack<char> s;

void Search(int a, int b) {
	if (a < 0 || b < 0) return; // 탐색 불가능하면 종료
	if (!link[a][b]) { // 대각선이라면 공통 문자를 찾았음을 의미
		s.push(str1[a]); // 스택에 저장
	}
	int a_n = a - ("101"[link[a][b]] - '0'), b_n = b - ("110"[link[a][b]] - '0'); // 다음 위치를 결정
	Search(a_n, b_n);
}

int DP(int a, int b) {
	if (a < 0 || b < 0) return 0; // 비교할 문자 없음
	if (visit[a][b]) return datas[a][b]; // 값이 있으면 반환
	visit[a][b] = 1;

	int val;
	if (DP(a - 1, b) < DP(a, b - 1)) {
		val = DP(a, b - 1);
		link[a][b] = 1;
	}
	else {
		val = DP(a - 1, b);
		link[a][b] = 2;
	}
	if (val < DP(a - 1, b - 1) + (str1[a] == str2[b])) {
		val = DP(a - 1, b - 1) + (str1[a] == str2[b]);
		link[a][b] = 0;
	} // 총 3 가지 경우 중, 가장 큰 값을 획득하고 경로를 기록

	return datas[a][b] = val;
}

int main() {
	cin >> str1 >> str2;

	int ans = 0;
	for (int k = 0; k < str1.length(); k++) {
		for (int m = 0; m < str2.length(); m++) {
			ans = max(ans, DP(k, m));
		}
	} // 모든 경우를 살피며 정답을 탐색
	printf("%d\n", ans);

	Search(str1.length() - 1, str2.length() - 1); // 저장된 경로룰 따라 문자열을 저장
	for (int k = 0; k < ans; k++) { // 출력
		printf("%c", s.top());
		s.pop();
	}
}