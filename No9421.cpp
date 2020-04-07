#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
// 소수상근수
// 소수 중, 조건을 만족하는 값을 탐색해야 함
// 이 때, 중복되는 값이 계속해서 발생하므로 미모아이제이션을 추가로 활용

#define NUM 1000000

int arr[NUM + 1], visit[NUM + 1][2];
vector<int> v; // 소수 집합

void Prime() { // 에라토스테네스의 체
	for (int k = 2; k <= NUM; k++) {
		if (arr[k]) continue;
		v.push_back(k); // 도달할 때 까지 한 번도 쓰이지 않았다면 소수
		for (int m = 1; m * k <= NUM; m++) {
			arr[m * k] = 1;
		}
	}
}

int DFS(int a) { // 상근수 판단
	if (a == 1) return 1; // 값이 1 로 수렴한다면 성공
	if (visit[a][0]) return visit[a][1];
	// 이미 방문했다면 상근수 판단값 반환
	// 기존 값은 false 이므로, 사이클로 인한 재방문인 경우 실패로 판단됨

	visit[a][0] = 1;
	int num = 0, copy = a; // 새로운 값, 복사본
	while (copy) {
		num += pow(copy % 10, 2); // 각 자릿수의 제곱을 모두 더함
		copy /= 10;
	}
	return visit[a][1] = DFS(num); // 자신의 상근수 여부는 최종 결과를 따라감
}

int main() {
	int N;
	cin >> N;

	Prime(); // 소수 생성

	vector<int> ans; // 정답 벡터
	int last = lower_bound(v.begin(), v.end(), N) - v.begin();
	for (int k = 0; k < last; k++) { // 입력값보다 작은 소수에 대해 모두 판단
		int val = v[k];
		if (DFS(val)) ans.push_back(val);
	}

	for (int a : ans) cout << a << endl; // 출력
}