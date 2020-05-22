#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
// 줄세우기
// 위상 정렬 (topological sort) 사용
// 처음엔 우선순위 큐 2개를 사용하여 출력을 판단하려 했으나,
// 최악의 경우 N의 제곱 경우수가 나오므로 시간 초과
// so, 벡터와 카운트 배열을 사용하여 간략화

#define MAX 32000

int s, c;
int front[MAX + 1];
vector<int> back[MAX + 1]; // 자신의 뒤에 있는 노드
vector<int> v;

int main() {
	cin >> s >> c;
	for (int k = 0; k < c; k++) {
		int a, b;
		scanf("%d %d", &a, &b);
		front[b] += 1; // b 의 앞에는 반드시 a가 존재해야 함
		back[a].push_back(b); // 데이터 삽입
	}
	for (int k = 1; k <= s; k++) { // 자신 앞에 필수요소가 없는 경우, 삽입
		if (!front[k]) v.push_back(k);
	}

	for (int k = 0; k < v.size(); k++) {
		int data = v[k]; // 데이터를 추출
		printf("%d ", data); // 출력
		for (int m = 0; m < back[data].size(); m++) {
			front[back[data][m]] -= 1; // indegree 감소
			if (!front[back[data][m]]) { // 0인 경우 벡터에 삽입
				v.push_back(back[data][m]);
			}
		}
	}
}
