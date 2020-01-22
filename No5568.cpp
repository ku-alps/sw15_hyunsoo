#include<iostream>
#include<unordered_map>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
// 카드 놓기
// 단순한 순열 조합 문제이나,
// 2자리 수 카드로 인해 생성하는 수의 중복 판단이 굉장히 힘듦
// so, hash map 을 통해 값의 중복을 판단

int cnt;
int N, K;
int visit[100], s[10]; // 벡터의 인덱스 저장
vector<int> v;
unordered_map<int, bool> m; // 값 중복을 판단할 hash map

int S(int level) {
	if (level == K) { // 원하는 카드만큼 뽑은 경우
		int key = 0;
		for (int k = 0; k < K; k++) {
			key *= v[s[k]] < 10 ? 10 : 100;
			key += v[s[k]];
			// 기존 수열을 해치지 않도록 키를 생성
			// 1~9 = 10 을 곱, 10~99 = 100
		}
		if (m.end() != m.find(key)) return 0; // 이미 존재하는 값이라면 종료
		m[key] = true; // 키를 맵에 추가
		return 1; // 경우 수 + 1
	}

	int sum = 0;
	for (int k = 0; k < v.size(); k++) {
		if (visit[v[k]] == 0) continue; // 뽑을 수 있는 카드가 없다면 넘김
		s[level] = k; // 벡터에 현재 인덱스 저장
		visit[v[k]] -= 1; // 카드 하나 뽑음
		sum += S(level + 1); // 재귀 호출
		visit[v[k]] += 1; // 카드 반환
	}
	return sum; // 총합 반환
}

int main() {
	cin >> N >> K;
	for (int k = 0; k < N; k++) {
		int num;
		cin >> num;
		v.push_back(num);
		visit[num] += 1; // 카드 수 체크
	}

	int sum = 0;
	for (int k = 0; k < v.size(); k++) { // 벡터의 모든 경우를 보면서
		s[0] = k; // 현재 인덱스 저장
		visit[v[k]] -= 1;
		sum += S(1); // 호출
		visit[v[k]] += 1;
	}
	cout << sum << endl;
}