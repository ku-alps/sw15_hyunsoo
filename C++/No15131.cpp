#include<iostream>
using namespace std;
// Auxiliary Project
// 수의 디지털 표현에서 켤 수 있는 막대의 수가 주어진 경우,
// 얻을 수 있는 수 조합의 최대 합 (중복 허용)

#define THREE 7
#define FOUR 4
#define TWO 1 // 사실 상 해당 값들로만 구성되며, 나머지 값은 효율이 떨어짐

int main() {
	int N;
	cin >> N;

	int ans = THREE * (N / 3);
	if (N % 3 == 1) ans = ans - THREE + FOUR; // 3개짜리 빼고 4개짜리로 채움
	else if (N % 3 == 2) ans += TWO; // 2개짜리 값 추가
	cout << ans << endl;
}