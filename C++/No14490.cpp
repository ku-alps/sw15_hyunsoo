#include<iostream>
using namespace std;
// 백대열
// 최대공약수를 통한 약분을 하는 문제
// 2부터 값을 증가시키며 계산하면 시간초과
// so, 절반부터 값을 감소시키는 방향을 채택
// = 최대공약수를 빠르게 찾는 방식

int main() {
	int a, b;
	cin >> a;
	getchar(); // : 제거 용도 
	cin >> b;

	if (a % b == 0 || b % a == 0) {
		// 입력받은 두 수가 서로 나눠지는 경우
		int div = a < b ? a : b;
		a /= div;
		b /= div; //둘중 작은 수로 나눠줌
	}
	else { // 그 외의 경우는 최대공약수를 찾아야 함
		while (true) {
			int k = a < b ? a / 2 : b / 2;
			// 나누는 수를 결정할 k
			//둘중 작은 수의 절반까지
			while (k > 1) { // k가 1보다 크면 계속 진행

				if (a%k == 0 && b%k == 0) { // 두 수가 모두 딱떨어지면
					a /= k;
					b /= k; // 나눔
					break; // 이번 k 반복문 종료
				}
				k--; //아니라면 k는 1 증가
			}

			if (k == 1) // 한 루프를 끝까지 돌아도 안나오면
				break; // 나눌 수 있는 수가 없으므로 종료
		}
	}
	cout << a << ':' << b << endl;
}