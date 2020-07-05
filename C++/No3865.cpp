#include<iostream>
#include<unordered_map>
#include<set>
#include<sstream>
#include<vector>
using namespace std;
// 학회원
// 중복을 없애야하므로, 편의를 위해 set STL 을 활용
// 또한, 문자열 처리를 위해 stringstream 으로 split 을 구현

int N;
set<string> s;
unordered_map<string, vector<string>> m; // 각 그룹별 정보
unordered_map<string, int> visit; // 방문 여부

void DP(string g) { // DP
	if (visit[g]) return; // 방문한 곳이면 무시
	visit[g] = 1;

	for (string t : m[g]) { // 그룹 소속 인원을 전부 파악
		if (!m[t].size()) s.insert(t); // 사람 이름이면 삽입
		else DP(t); // 그룹 명이면 재귀호출
	}
}

int main() {
	while (true) {
		cin >> N;
		if (!N) break; // 0 이면 종료

		s.clear();
		m.clear(); 
		visit.clear(); // 초기화

		string save; // 탐색 그룹 이름
		for (int k = 0; k < N; k++) {
			string str; // 문자열 입력 (한 줄)
			cin >> str;

			string group, people; // 그룹, 사람 정보
			stringstream ss(str);
			getline(ss, group, ':');
			getline(ss, people, ':'); // 문자열 분리

			m[group]; // 집합 생성
			if (!k) save = group;; // 탐색 그룹

			string name;
			stringstream person(people); // 소속 이름 분리
			while (getline(person, name, ',')) { // 콤마를 기준으로 분류
				stringstream end(name);
				getline(end, name, '.'); // 온점 예외처리 (마지막 대상자)
				m[group].push_back(name);
			}
		}
		DP(save); // 탐색 그룹부터 하위로 전부 돌려 하나의 집합을 생성
		cout << s.size() << endl; // 그 크기만큼 출력
	}
}