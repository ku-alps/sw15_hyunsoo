#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
// 공통 부분 문자열
// 같은 값을 가진 '연속된' 문자열을 가져야 함
// so, 일치하는 경우에만 대각선 값에서 증가시킴

#define MAX 4000 // 문자길이 최대 4000

int datas[MAX][MAX], visit[MAX][MAX]; // 해당 위치에서 연속된 최대 길이
string str1, str2;

int DP(int a, int b) {
	if (a < 0 || b < 0) return 0; // 비교할 문자 없음
	if (visit[a][b]) return datas[a][b]; // 값이 있으면 반환
	visit[a][b] = 1;
	if (str1[a] == str2[b]) // 같은 경우엔 대각선 라인의 값 +1
		return datas[a][b] = DP(a - 1, b - 1) + 1;
	return 0; // 연속된 값이 끊기면 0 반환
}

int main() {
	cin >> str1 >> str2;
	 
	int ans = 0;
	for (int k = 0; k < str1.length(); k++) {
		for (int m = 0; m < str2.length(); m++) { // 모든 길이 조합을 탐색
			ans = max(ans, DP(k, m));
		}
	}
	printf("%d\n", ans);
}