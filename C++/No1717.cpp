#include <iostream>
#include<cstdio>
using namespace std;
// 집합의 표현 
// Union-Find 사용

int arr[1000001]; // 각 노드의 루트
int N, M;

int F(int idx) { // 유니온 파인드 탐색용 재귀 함수
	if (arr[idx] == idx) return idx; // 해당 집합의 대표값에 도달한 경우 반환
	int next = arr[idx];
	return arr[idx] = F(next); // 자신의 상위 정보를 반환받아 자신이 가진 대표값 갱신
}

int main() {
	cin >> N >> M;
	for (int k = 1; k <= N; k++) { // 초기 세팅
		arr[k] = k;
	}

	for (int k = 0; k < M; k++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		int b_root = F(b);
		int c_root = F(c); // 입력 노드의 대표값을 탐색
		switch (a) { // 수행 명령
		case 0: // 합치는 경우
			if (b_root <= c_root) // 두 대표값 중, 작은 쪽으로 연결함
				arr[c_root] = b_root;
			else
				arr[b_root] = c_root;
			break;
		case 1: // 동일 그룹 판단
			if (b_root == c_root) printf("YES\n"); // 동일하다면 한 그룹
			else printf("NO\n"); // 다르면 다른 그룹
			break;
		default:
			break;
		}
	}
}