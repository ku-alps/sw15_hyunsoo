#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// 암호 만들기
// 조건이 성립하는 모든 문자열을 출력

int len, num, stack[16];
string mo_c = "aeiou"; // 모음 문자 집합
vector<char> v; // 문자 저장 벡터

void DFS(int select, int cnt); // DFS 탐색

int main() {
	cin >> len >> num;
	for (int k = 0; k < num; k++) {
		char info;
		cin >> info;
		v.push_back(info);
	}  // 문자를 입력받아 벡터에 추가 (문자 리스트를 생성)

	sort(v.begin(), v.end()); // 정렬
	for (int k = 0; k <= num - len; k++)
		DFS(k, 0); // 모든 문자열에 대한 완전 탐색
}

void DFS(int select, int cnt) {
	stack[cnt] = select;
	if (cnt == len - 1) { // 원하는 문자 길이에 도달하면 조건 체크
		string ans = "";
		int ja = 0, mo = 0;
		for (int k = 0; k < len; k++) {
			ans += v[stack[k]]; // 문자를 정답에 추가
			if (mo_c.find(v[stack[k]]) != -1) mo++; // 모음 집합에 있다면 모음 수 추가
			else ja++; // 없으면 자음
		}
		if (mo >= 1 && ja >= 2) // 조건이 성립하면 출력
			cout << ans.c_str() << endl;
		return;
	}

	for (int k = select + 1; k < num; k++) {
		DFS(k, cnt + 1); // 이후 존재하는 문자에 대해 재귀탐색
	}
}