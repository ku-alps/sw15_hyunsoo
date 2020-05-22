#include<iostream>
#include<vector>
using namespace std;
// 혼란
// 자신보다 작은 크기의 값이 몇 개 남아있는가에 대한 체크가 필요
// 데이터 갱신이 필요하므로 세그먼트 트리 사용하려 했으나,
// 데이터 범주가 너무 크므로 불가능 + 모든 Case 에 대해 매번 시도해 봐야 함

// so, 이를 누적합으로 수식화하여 풀이
// A 개의 숫자로 만드는 혼란 값은
// A-1 개로 만드는 혼란 값에 기반하여, 앞쪽에 어떠한 수가 들어올 수 있는가가 추가되는 방식
// 이 때, 각 수는 단 한 번만 등장하므로, 앞에 등장하는 수와 관계없이 뒤쪽 대소관계는 영향을 받지 않음 

// 다만, 입력되는 혼란 값의 제약 조건이 숫자에 묶여있지 않음
// 즉, 해당 조합으로 만들 수 없는 혼란 값 또한 들어올 수 있으며, 예외처리가 필요

#define NUM 1000
#define CNT 10000 // 혼란 값
#define DIV 1000000007 // 나누어야 하는 값

int C, N;
vector<int> cnt[NUM + 1]; // a개의 값에서 각 단계까지 충족하는 case 의 누적 수

int main() {
	cin >> C >> N;

	cnt[0].push_back(1);
	for (int k = 1, limit = 0; k <= C; limit += k++) { 
		for (int m = 0; m <= (limit < CNT ? limit : CNT); m++) { // 모든 혼란 값에 대해
			int basic = cnt[k].size() == 0 ? 0 : cnt[k].back(); // 첫 값인 경우, 0 을 기준으로 잡음
			int add = m < cnt[k - 1].size() ? cnt[k - 1][m] : cnt[k - 1].back(); // 인덱스 범위를 벗어나면 가장 끝 값 사용
			int minus = m < k ? 0 : cnt[k - 1][m - k]; // 추가되는 값을 넘어서면 사용할 수 없는 경우가 생김

			int ans = basic + add - minus;
			ans < 0 ? ans += DIV : ans %= DIV; // 음수값이라면 양수로 변환, 양수면 나눔
			cnt[k].push_back(ans);
		}
	}

	// 찾고자 하는 N 값이 C 로 만들 수 있는 혼란 값 내에 존재하는가를 판단해줘야 함
	int select = (C - 1) * C < 2 * N ? 0 : cnt[C][N] - (N != 0 ? cnt[C][N - 1] : 0);
	cout << (select < 0 ? select + DIV : select) << endl;
}