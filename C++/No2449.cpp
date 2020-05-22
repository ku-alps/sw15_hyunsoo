#include<iostream>
#include<algorithm>
using namespace std;
// 전구
// 사실상, DP 구조를 찾지 못해 해결하지 못한 문제
// 정답 설명을 보고도 한동안 구조 이해를 하지 못해 상당히 헤맴
// 멘탈 바사삭

#define MAX 200

int N, M;
int light[MAX]; // 전구의 색
int arr[MAX][MAX]; // a~b 까지의 최소 변경 횟수

int F(int left, int right) {
	if (left >= right) return 0; // 앞뒤 순서가 바뀌면 수행 종료
	if (arr[left][right] != -1) return arr[left][right]; // 이미 방문한 경우 출력

	arr[left][right] = MAX + 1;
	for (int k = left; k < right; k++) { // 가능한 모든 조합에 대해 비교 선택
		int val = light[left] != light[k + 1] ? 1 : 0; // 가장 왼쪽 전구와 현재 기준이 되는 전구의 색이 다르면 색 변경 추가로 필요
		arr[left][right] = min(arr[left][right], F(left, k) + F(k + 1, right) + val); // 좌, 우, 변경 여부 값의 총 합
	}
	return arr[left][right];
}

int main() {
	for (int k = 0; k < 200; k++) {
		for (int m = 0; m < 200; m++) {
			arr[k][m] = -1;
		}
	}

	cin >> N >> M;
	for (int k = 0; k < N; k++) {
		cin >> light[k];
	}
	int ans = F(0, N - 1); // 답을 찾음
	cout << ans << endl;
}