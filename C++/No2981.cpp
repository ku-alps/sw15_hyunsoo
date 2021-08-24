#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
// 검문
// 나머지가 동일하다는 조건을 기반으로
// 최소값을 전부 빼서 나머지 값을 0으로 만들고 계산
// 남은 연산은 완전탐색으로 찾으려 했으나 시간초과로 GCD 기반의 로직을 사용

int N; // 숫자 갯수
int num[100]; // 최대 100개까지 수용 가능

int GCD(int a, int b) { // 최대공약수 구하기
	if (!b) return a; // b가 0이라면 (딱 나눠졌으면) a가 최대공약수
	return GCD(b, a % b); // 공약수가 아니라면 규칙으로 쪼갬
}

int main() {
	// 입력
	cin >> N;

	int minVal = 1000000000; // 최소값0
	int maxVal = 0; // 탐색 최대치
	for (int k = 0; k < N; k++) {
		cin >> num[k]; // 입력
		minVal = min(minVal, num[k]); // 최소값 선택
	}
	for (int k = 0; k < N; k++) {
		num[k] -= minVal; // 나머지가 0이 되도록 갱신
		maxVal = max(maxVal, num[k]); // 최대값 선택
	}
	
	// 남은 값들의 공통 최대공약수 찾기
	int gcd = maxVal; // 일단 원소 중 가장 큰 값으로 갖고감
	for (int k = 0; k < N; k++) { // 모든 원소들을 대상으로 gcd 찾기
		// 큰 값을 앞으로 넣어서 함수 호출
		gcd = num[k] > gcd ? GCD(num[k], gcd) : GCD(gcd, num[k]);
	}

	// GCD 기반으로 정답 만들기
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(gcd); // 자기 자신은 항상 포함
	for (int k = 2; k <= sqrt(gcd); k++) {
		if (!(gcd % k)) { // 딱 나눠지는 값이면
			pq.push(k); // 후보 성립
			if (k != sqrt(gcd)) pq.push(gcd / k);
			// 루트로 중복되는 값이 아니면 그 반대도 삽입
		}
	}

	// 출력
	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}
}