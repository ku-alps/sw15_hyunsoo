#include<iostream>
#include<unordered_map>
using namespace std;
// 문자열 집합
// 맵을 통한 자료의 유무 확인
// 트라이를 사용하여 구현할 수도 있음

int N, M, ans; // 문자 집합, 입력 문자 수, 정답
unordered_map<string, int> m; // 맵

int main() {
	cin >> N >> M;
	for (int k = 0; k < N; k++) { // 문자 집합 생성
		string str;
		cin >> str;
		m[str] = 1;
	}
	for (int k = 0; k < M; k++) { // 일치하는 문자 존재 확인
		string str;
		cin >> str;
		if (m[str]) ans += 1; // 있다면 정답 수 증가
	}
	cout << ans << endl;
}