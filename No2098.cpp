#include<iostream>
#include<algorithm>
using namespace std;
// 외판원 순회
// 빠른 알고리즘이 존재하지 않는 완전 탐색 문제 중 하나
// so, 입력의 크기가 상당히 작은 편 ( 노드의 수 16 )
// 다만, '어떤 도시를 경유 했는가' 란 정보가 반드시 필요하므로
// bit mask 를 사용하여 경유도시 정보를 단순화하여 처리
// ( 약 16비트가 필요하므로, int 형으로 충분 )

#define MAX 16
#define INF MAX * 1000000 + 1
#define BIT (1<<MAX) // 비트마스크 최대값

int N, arr[MAX][MAX];
int datas[MAX][BIT];

int DP(int idx, int record) {
	record |= (1 << idx); // 해당 노드를 방문했음을 표기
	if (record == (1 << N) - 1) return arr[idx][0] != 0 ? arr[idx][0] : INF;
	// 모든 곳을 다 방문했다면 원점으로 돌아가는 경로 비용을 반환
	// 다만 돌아가는 경로가 없다면 ('0') 사용할 수 없으므로, 반환 값에 유의해야 함
	if (datas[idx][record]) return datas[idx][record]; // 값이 있다면 사용

	datas[idx][record] = INF;
	for (int k = 0; k < N; k++) {
		if (!(record & (1 << k)) && arr[idx][k] != 0) { // 방문 안한경우
			datas[idx][record] = min(datas[idx][record], DP(k, record) + arr[idx][k]); // 모든 경로와 비교하며 최선의 값을 사용
		}
	}
	return datas[idx][record];
}

int main() {
	cin >> N;
	for (int k = 0; k < N; k++) {
		for (int m = 0; m < N; m++) {
			cin >> arr[k][m];
		}
	} // 모든 경로값을 입력받음
	cout << DP(0, 0) << endl; // '돌아오는 경로' 를 찾는 것이 목표이므로, 탐색 위치는 상관 없음
}