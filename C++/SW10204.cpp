#include<cstdio>
#include<queue>
#include<tuple>
using namespace std;
// 초밥 식사
// 그릇을 선택하는 기준은 크게 2가지
// (1) 자신이 얻는 점수가 큰 경우 ( 나에게 이득 )
// (2) 상대방이 얻는 점수가 큰 경우 ( 상대에게 이득 )
// so, 두 기준을 상황에 따라 판단해야 하며, 이를 하나의 '합' 으로 표현할 수 있음
// 그 합이 큰 순서대로 뽑는 것이 가장 이상적

// iostream 의 입력지연으로 시간초과 발생
// so, cstdio 로 수정

// 오버플로우가 발생하므로 long long int 로 선언
typedef pair<long long int, long long int> pr;

struct func {
	bool operator()(pr a, pr b) { // 합 크기 순으로 출력
		return a.first + a.second < b.first + b.second;
	}
};

long long int T, num; // 루프 수, 초밥그릇 수
priority_queue<pr, vector<pr>, func> pq; // 우선순위 큐

int main() {
	scanf("%lld", &T);
	for (int k = 1; k <= T; k++) {
		scanf("%lld", &num);
		for (int m = 0; m < num; m++) {
			long long int a, b;
			scanf("%lld %lld", &a, &b);
			pq.emplace(a, b);
		} // 값 입력

		// 정연이부터 하나씩 뽑음
		bool flag = false;
		long long int ans[2] = {};
		while (!pq.empty()) {
			pr data = pq.top(); // 최상위 값
			pq.pop();
			ans[flag] += !flag ? data.first : data.second; // 각각 얻은 행복지수
			flag = !flag; // 상태 바꾸기
		}
		printf("#%d %lld\n", k, ans[0] - ans[1]); // 출력
	}
}