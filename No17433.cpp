#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
// 신비로운 수
// '나머지 정리' 와 연관된 문제

// 임의의 수 N 은 어떠한 p 에 의해 [ N = a*p + r ] 형태로 표현이 가능
// 이때, p 에 대해 나머지 r 이 같다는 것은
// 두 수 M, N 에 대해 [ N - a*p = M - b*p = r ] 이 성립함을 의미
// 이를 정리하면 [ N - M = (a - b)*p ] 이며, 두 수의 차는 반드시 p 의 배수임을 알 수 있음

// so, 주어진 모든 수에 대하여 차이값을 구한 후, 최대공약수를 구하면 p 를 얻을 수 있음

int GCD(int a, int b) { // 유클리드 호제법
	while (b) {
		int c = a % b;
		a = b;
		b = c;
	}
	return a; // 최대공약수 반환
}

int main() {
	int T;
	cin >> T;
	while (T--) { // 테스트 케이스
		int N;
		cin >> N; // 입력받는 수

		queue<int> q; // 차이 값을 저장할 큐

		int first;
		cin >> first; // 기준이 되는 첫 값
		for (int k = 1; k < N; k++) {
			int next; 
			cin >> next;
			q.push(abs(first - next)); // 값을 하나씩 읽어 그 차이를 큐에 삽입
		}

		int gcd = 0;
		while (!q.empty()) { // 만든 모든 값에 대해 최대공약수를 확인
			gcd = GCD(q.front(), gcd);
			q.pop();
		}

		if (!gcd) cout << "INFINITY" << endl; // 0 인 경우, 공통이 되는 약수가 없음 (무한)
		else cout << gcd << endl; // 그 외엔 가진 값을 출력
	}
}