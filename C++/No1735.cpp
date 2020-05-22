#include<iostream>
using namespace std;
// 분수 합
// 기약분수를 만들기 위해선 분자 분모의 최대공약수를 찾아야 함
// so, 유클리드 호제법을 사용

int main() {
	int prnt[2], cld[2];
	for (int k = 0; k < 2; k++) {
		cin >> cld[k] >> prnt[k];
	}
	int s_prnt = prnt[0] * prnt[1], s_cld = cld[0] * prnt[1] + cld[1] * prnt[0];
	int a = s_prnt, b = s_cld;
	while (b != 0) {
		int save = a % b;
		a = b;
		b = save;
	} // 유클리드 호제법 사용

	s_prnt /= a;
	s_cld /= a; // 분자 분모를 최대공약수로 나눔
	cout << s_cld << " " << s_prnt << endl;
}