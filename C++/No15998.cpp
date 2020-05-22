#include<cstdio>
#include<algorithm>
using namespace std;
// 카카오머니
// 최소 충전 단위를 파악하기 위해선
// 각 거래마다 충전되는 값들의 최대공약수를 파악해야 함
// so, 유클리드 호제법을 사용

// 다만, 수의 범위에 있어서 long long int 타입을 사용해야만 했으나,
// 함수에서 데이터를 저장하는 과정에서 변수 c 를 int 타입으로 선언하여 문제가 발생했음
// 채점률 32% 에서 실패를 만들어냈던 원인..

#define MAX 9 * 1000000000000000000 // 최대 한계 조건

long long int N, money, maximum, ans; // 입출금 기록, 현재 잔고, 충전 시 등장한 최대잔고량, 정답

long long int GCD(long long int a, long long int b) { // 유클리드 호제법
	while (b != 0) {
		long long int c = a % b; // 타입 선언 주의
		a = b;
		b = c;
	}
	return a; // 최대공약수 반환
}

int main() {
	scanf("%lld", &N);

	bool flag = true; // 성공 여부 판단
	for (int k = 0; k < N; k++) {
		long long int give, result;
		scanf("%lld %lld", &give, &result); // 거래량, 통장 잔고

		if (give >= 0) { // 0보다 큰 경우,
			if (money + give != result) flag = false; // 에러 존재
		}
		else { // 음수인 경우
			if (money + give >= 0) { // 잔고로 충분한 경우
				if (money + give != result) flag = false; // 결과값과 다르면 에러
			}
			else { // 불가능한 경우, 충전값을 판단해야 함
				long long int charge = result - give - money; // 충전량
				ans = GCD(charge, ans); // 충전 값의 최대공약수를 구함
				maximum = max(maximum, result); // 충전 후 잔고에 대한 역대 최대치 갱신

				if (maximum / ans) flag = false; // 만약 여러번에 나누어 돈을 넣어야한다면 불가능
			}
		}
		money = result;
	}

	if (ans > MAX) flag = false; // 충전단위 허용치를 넘어서도 실패

	if (flag) { // 조건에 맞춰 출력
		if (ans) printf("%lld\n", ans); 
		else printf("1\n");
	}
	else {
		printf("-1\n");
	}
}