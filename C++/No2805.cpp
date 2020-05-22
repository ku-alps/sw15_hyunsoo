#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// 나무 자르기
// 파라메트릭 서치 (정답 범위의 이분 탐색)

long long int tree, want;
vector<long long int> height; // 각 나무들의 높이 벡터
bool check(int mid);

int main() {
	cin >> tree >> want; // 입력

	int sum = 0, m = 0;
	for (int k = 0; k < tree; k++) {
		int data;
		cin >> data; // 정보를 입력받음
		height.push_back(data); 
		m = max(m, data);// 벡터에 삽입하고, 최대값 판단
	}
	sort(height.rbegin(), height.rend()); // 정렬

	int f = 0, b = m;
	while (f <= b) { // 이분 탐색
		// 조건에 맞는 경우, 그 밑은 모두 조건에 성립
		int mid = (f + b) / 2;
		if (check(mid)) f = mid + 1;
		else b = mid - 1; // 조건 판단하며 위치를 선택
	}

	cout << b << endl; // 선택한 높이를 출력
}

bool check(int mid) {
	long long int sum = 0;
	for (int k = 0; k < tree; k++) { // 선택한 높이에 대해 높이 합을 계산
		long long int val = height[k] - mid; // 잘라서 얻을 수 있는 값
		if (val > 0) sum += val; // 0보다 크면 더하고
		else break; // 작다면, 나무 높이는 정렬되어 있으므로 종료
	}
	if (sum >= want) return true;
	else return false; // 성공 여부 결과 판단
}