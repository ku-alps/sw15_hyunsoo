#include<iostream>
using namespace std;
// 다리 놓기
// 다리가 겹치지 않도록 하는 것이 목표
// so, 재귀 호출 시, 자신의 앞에 존재하는 다리에만 연결

int arr[31][31];

int Pascal(int a, int b) {
	if (arr[a][b])
		return arr[a][b]; // 이미 왔었으면 종료
	if (b == 0) // 마지막 다리에 연결된 경우
		arr[a][b] = 1;
	else if (a < b) // 연결할 수 있는 다리가 부족하면
		arr[a][b] = 0;
	else // 그 외의 경우는 재귀호출로 값을 누적
		arr[a][b] = Pascal(a - 1, b - 1) + Pascal(a - 1, b);
	// 다리를 선택한 경우 + 선택 안한 경우
	return arr[a][b];
}

int main() {
	int loop;
	cin >> loop;
	for (int k = 0; k < loop; k++) {
		int N, M;
		cin >> N >> M;
		cout << Pascal(M, N) << endl; // 테스트 케이스에 대해 결과 출력
	}
}