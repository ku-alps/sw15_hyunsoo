#include<iostream>
using namespace std;
// 사이클 게임
// 사이클이 생기는 순간을 판단하면 충분하므로, Union-Find 를 사용

#define NUM 500001

int arr[NUM], N, M;

int Find(int a) { // 대표값 탐색
	if (arr[a] == a) return a;
	return arr[a] = Find(arr[a]);
}

bool Union(int a, int b) { // Union
	int ra = Find(a), rb = Find(b);
	if (ra != rb) {
		arr[ra] = rb;
		return false;
	}
	return true;
}

int main() {
	int ans = 0; // 실패 값 세팅
	cin >> N >> M;
	for (int k = 0; k < N; k++) arr[k] = k; // 기본 세팅
	for (int k = 1; k <= M; k++) {
		int a, b; // 연결할 두 노드
		cin >> a >> b;
		if (Union(a, b)) { // 이미 동일한 소속이면 종료
			ans = k;
			break;
		}
	}
	cout << ans << endl;
}