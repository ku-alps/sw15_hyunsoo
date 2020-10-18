#include<iostream>
using namespace std;
// 소가 길을 건너간 이유 1

int N, cow[11];

int main() {
	cin >> N;
	for (int k = 1; k <= 10; k++) {
		cow[k] = -1; // 초기화
	}
	int ans = 0;
	for (int k = 0; k < N; k++) {
		int a, b;
		cin >> a >> b;
		if (cow[a] >= 0 && cow[a] != b) ans++;
		cow[a] = b;
	}
	cout << ans << endl;
}