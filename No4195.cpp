#include<cstdio>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
// 친구 네트워크
// Union-Find 그룹핑 + Hash map 을 사용한 문제풀이
// 다만 cin 의 입력딜레이로 인한 시간초과가 계속해서 발생
// so, cstdio 형태로 구현을 변경

unordered_map<string, int> m; // 각 이름의 인덱스 번호를 보유
vector<int> group, rel; // 소속된 그룹 번호, 그룹의 크기 (대표값만 사용)

int Find(int idx) { // 그 그룹의 대표값 탐색
	if (group[idx] == idx) return idx;
	return group[idx] = Find(group[idx]);
}

int Union(int a, int b) { // 두 대상이 속한 그룹을 비교
	int i_a = Find(a), i_b = Find(b);
	if (i_a == i_b) return rel[i_a]; // 이미 관계 내에 존재하는 경우, 종료

	// 인덱스 값이 작은 쪽으로 그룹을 연결
	if (i_a < i_b) {
		rel[i_a] += rel[i_b]; // 그룹 a 에 소속된 관계 수 증가
		group[i_b] = i_a; // 그룹을 연결
	}
	else {
		rel[i_b] += rel[i_a];
		group[i_a] = i_b;
	}
	return max(rel[i_a], rel[i_b]); // 한 값이 증가했으므로, 둘 중 큰 값을 선택
}

int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		int F;
		scanf("%d",&F);

		m.clear();
		group.clear();
		rel.clear(); // 외부 자료구조 초기화

		group.push_back(0);
		rel.push_back(0); // 0번 인덱스는 사용하지 않음
		while (F--) {
			char f[2][21];
			scanf("%s %s", &f[0], &f[1]);

			int idx[2];
			for (int k = 0; k < 2; k++) {
				if (!m[f[k]]) { // 키가 없었으면, 새로 들어온 값
					m[f[k]] = group.size();
					group.push_back(group.size());
					rel.push_back(1);
				}
				idx[k] = m[f[k]]; // 이름을 대표하는 인덱스 값 저장
			}
			printf("%d\n", Union(idx[0], idx[1])); // Union-Find 수행
		}
	}
}