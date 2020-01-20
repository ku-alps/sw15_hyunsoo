#include<iostream>
#include<algorithm>
using namespace std;
// 부분합
// 단순히 길이만 구하면 충분
// so, 총 합이 일치하는 경우의 두 포인터의 index 값 차이를 사용

#define DEFAULT 100001 // 최대값 (기본)

int main() {
	int N, S, arr[100000];
	cin >> N >> S;
	for (int k = 0; k < N; k++)
		cin >> arr[k]; // 입력

	int f, b, sum, len; // 두 포인터 인덱스, 합, 배열 길이
	f = b = sum = 0;
	len = DEFAULT;

	while (f != N) {
		if (sum > S || b == N) {
			sum -= arr[f];
			f += 1;
		}
		else {
			sum += arr[b];
			b += 1;
		} // 투 포인터 사용

		if (sum >= S) len = min(len, b - f);
		// 조건이 성립하는 경우, 현재까지 등장한 길이 중 최소값을 선택
	}
	if (len == DEFAULT)	len = 0; // 만일 초기값에서 변하지 않았으면 0 으로 변환
	cout << len << endl;
}