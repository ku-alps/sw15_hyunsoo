#include<iostream>
using namespace std;
// 이항 계수 2
// '파스칼의 삼각형'
// 이항 계수에서 성립하는 성질로 상단의 합을 결과로 가짐
// 수의 범위가 int 형을 넘으므로,
// 관련된 모든 타입을 long long int 형으로 사용

long long int tri[1001][1001];

long long int Pascal(long long int a, long long int b) {
	if (tri[a][b] != 0) return tri[a][b];
	if (b == 0)
		tri[a][b] = 1;
	else if (a < b)
		tri[a][b] = 0;
	else
		tri[a][b] = (Pascal(a - 1, b - 1) + Pascal(a - 1, b)) % 10007;
	return tri[a][b];
}

int main() {
	long long int num, sel;
	cin >> num >> sel;
	long long int ans = Pascal(num, sel);
	cout << ans << endl;
}
