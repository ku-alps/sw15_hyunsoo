// 완전 제곱수

#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int min, max;
	int first = -1; // 범위 중 최소값
	bool tag = false; // 최소값 획득을 위한 flag 값
	cin >> min >> max; //범위 값을 입력

	int ans = 0; // 일단 정답은 0
	int cal = 0; //계산 값
	for (int k = 1; cal <= max; k++) {
		// 범주를 벗어나면 종료
		if (cal >= min) { // 계산 값이 범주 내로 들어서면
			ans += cal; //해당 값을 더함
			if (!tag) {
				tag = true;
				first = cal; // 지금 나온 값이 첫 값
			}
		}
		cal = (int)pow(k, 2.0f);
	}
	if (ans)
		cout << ans << endl;
	cout << first << endl;
}