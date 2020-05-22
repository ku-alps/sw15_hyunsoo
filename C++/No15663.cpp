#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
// N과 M (9)
// 완전 탐색을 사용하되, 중복 예외 처리를 위하여
// 중복되는 수를 파악하여 가장 마지막 한 번의 연산만 수행

int N, M;
vector<int> v; // 가지고 있는 모든 수
vector<int> s; // 이후 정답 출력용으로 사용할 값 저장 스택
int visit[10001], cnt[10001];

void D(int idx) {
	if (idx == s.size()) { // 원하는 길이까지 도달
		for (int k = 0; k < idx; k++) {
			printf("%d ", s[k]); // 출력
		}
		printf("\n");
		return;
	}

	for (int k = 0; k < N; k++) {
		if (k < v.size() - 1 && v[k] == v[k + 1]) continue; // 중복되는 수가 있으면 스킵
		if (visit[v[k]] == cnt[v[k]]) continue; // 해당 수를 모두 쓴 경우 스킵
		visit[v[k]] += 1; // 수를 사용함
		s[idx] = v[k]; // 스택에 해당 수를 기록
		D(idx + 1); // 재귀
		visit[v[k]] -= 1; // 사용한 수 반환
	}
}

int main() {
	scanf("%d %d", &N, &M);

	s.resize(M); // 길이 M의 수열 생성 예정
	for (int k = 0; k < N; k++) {
		int data;
		scanf("%d", &data);
		v.push_back(data);
		cnt[data] += 1; // 가지고 있는 수를 추가
	}
	sort(v.begin(), v.end()); // 사전 순 탐색이므로, 정렬
	for (int k = 0; k < v.size(); k++) { // 0부터 모든 카드를 시작점으로 하여 탐색
		if (k < v.size() - 1 && v[k] == v[k + 1]) continue;
		visit[v[k]] += 1;
		s[0] = v[k];
		D(1);
		visit[v[k]] -= 1;
	}
}