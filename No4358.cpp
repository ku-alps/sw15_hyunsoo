#include<iostream>
#include<cstdio>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
// 생태학
// 관련 알고리즘은 Trie 이지만, hash map 을 통한 수의 체크로도 충분
// 다만, 입력 데이터에서 빈 줄에 대한 예외처리가 추가로 필요했음
// 약간 하자가 있는 문제

float cnt;
vector<string> v;
unordered_map<string, int> m;

int main() {
	string str;
	while (!cin.eof()) { // 파일 끝이 아닌 경우 무한 반복
		getline(cin, str); // 문자열을 줄단위로 입력
		if (str.length() != 0) { // 빈 문장이 아니라면 (데이터 값에서 예외처리가 필요함)
			cnt++;
			if (m.find(str) != m.end()) { // 이미 들어있는 나무라면
				m[str] += 1; // 1회 증가
			}
			else {
				m[str] = 1; // 1로 고정 후 벡터에 추가
				v.push_back(str);
			}
		}
	}
	sort(v.begin(), v.end(), [](string& a, string& b)->bool {
		return a.compare(b) < 0; // 사전 순 정렬
		});
	for (int k = 0; k < v.size(); k++) {
		printf("%s %.4f\n", v[k].c_str(), (m[v[k]] * 100) / cnt);
		// string 을 char* 형으로 반환 및 비율을 소수 4자리까지 출력
	}
}