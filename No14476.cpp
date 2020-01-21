#include<iostream>
#include<vector>
using namespace std;
// 최대공약수 하나 빼기
// 임의의 정수 하나를 뺀 경우 획득 가능한 최대 공약수를 구해야 함
// so, 모든 경우에 대한 연산이 필요하나,
// N 의 크기로 인해 일반적인 브루트 포스로는 수행이 불가능
// so, 좌, 우의 최대공약수를 미리 계산하여 사용 

#define MAX 1000000

int N, num[MAX];
int l_gcd[MAX], r_gcd[MAX];
// 선택된 값을 중심으로 왼쪽, 오른쪽 gcd

int G(int a, int b) { // 유클리드 호제법
	while (b != 0) {
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	cin >> N;
	for (int k = 0; k < N; k++) {
		cin >> num[k];
	}
	
	for (int k = 1; k < N; k++) {
		l_gcd[k] = G(l_gcd[k - 1], num[k - 1]);
		r_gcd[(N - 1) - k] = G(r_gcd[N - k], num[N - k]);
	} // 좌우 최대공약수를 미리 계산

	int gcd = 0, idx = -1;
	for (int k = 0; k < N; k++) {
		int val = G(l_gcd[k], r_gcd[k]);
		if (gcd < val) { // 현재 얻은 최대공약수 값이 더 크다면
			gcd = val;
			idx = k; // 교체
		}
	}
	// 마지막 조건 확인
	if (!(num[idx] % gcd)) cout << -1 << endl;
	else cout << gcd << " " << num[idx] << endl;
}