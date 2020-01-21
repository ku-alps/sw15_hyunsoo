#include<iostream>
#include<vector>
using namespace std;
// 소인수분해
// 어떠한 값이 가질 수 있는 (자신을 제외한) 가장 큰 약수는 해당 값의 제곱근
// so, 제곱근까지 존재하는 모든 소수로 분해를 시도

// 다만, 그 결과가 1이 아닌 경우는 그 자체로 소수가 된다는 의미
// 해당 예외를 생각하지 못해 몇 차례 실패

#define MAX 3164 // 천만의 제곱근 값의 올림

int cnt[MAX];
bool arr[MAX]; // 방문 여부
vector<int> v; // 소수 벡터

void eratos() {
	for (int k = 2; k < MAX; k++) {
		if (arr[k]) continue; // 이미 방문한 경우

		v.push_back(k);
		for (int m = 2; m * k < MAX; m++) {
			if (arr[m * k]) continue; // 이미 방문한 경우
			arr[m * k] = true;
		}
	}
}

int main() {
	eratos(); // 소수 획득

	int num;
	cin >> num;

	for (int k = 0; k < v.size();) {
		if (num == 1) break; // 남은 값이 1인 경우 종료
		if (!(num % v[k])) { // 현재 벡터값으로 나눌 수 있다면 약수
			cout << v[k] << endl;
			num /= v[k];
			continue;
		}
		// 기존에는 하나의 소수를 찾은 경우, 처음부터 재시도를 했으나 시간초과
		// but, 그럴 필요는 없으며 동일한 소수가 재등장 할 수 있으므로,
		// 해당 소수부터 다시 분해를 시도하면 충분
		k++;
	}
	if (num != 1) cout << num << endl; // 남은 값이 있다면 그 자체로 소수
}