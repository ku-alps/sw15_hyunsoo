#include<iostream>
#include<algorithm>
using namespace std;
// 사전

#define MAX 1000000001

int arr[202][101]; // 배열

int Pascal(int a, int b) { // 주어진 조건으로 만들 수 있는 모든 Case
	// 모든 문자의 수, Z 의 수
	if (arr[a][b]) return arr[a][b]; // 이미 정보가 있다면 반환
	if (b == 0) arr[a][b] = 1; // 문자열 길이에 도달했다면
	else if (a < b) arr[a][b] = 0; // 실패한 경우
	else arr[a][b] = min(MAX, Pascal(a - 1, b - 1) + Pascal(a - 1, b));
	// 그 외에는 두 재귀 중 최소값을 선택
	return arr[a][b];
}

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	if (Pascal(N + M, M) < K) { // 만들 수 있는 종류보다 원하는 번호가 크면 실패
		cout << -1 << endl;
	}
	else {
		int a = M; // 남은 z의 갯수
		long long int flag = K; // 번호
		for (int k = 1; k <= N + M; k++) {
			// 만들 수 있는 갯수롤 기준으로 등장하는 문자를 결정
			if (Pascal(N + M - k, a) >= flag) {
				cout << "a";
			}
			else {
				cout << "z";
				flag -= Pascal(N + M - k, a); 
				// a가 우선으로 나오는 경우 만들 수 있는 수 만큼 뺌 
				a -= 1; // z 를 선택하고 남은 z 수 감소
			}
		}
	}
}