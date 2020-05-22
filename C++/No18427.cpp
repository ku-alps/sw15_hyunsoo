#include<iostream>
#include<vector>
using namespace std;
// 함께 블록 쌓기
// 모든 경우의 조합을 만드는 경우, 최악으로 50 * 11! 을 소모
// ( 최대 50명의 학생, 가진 블록 수 10개 + 선택하지 않는 경우 )
// so, 단순 완전탐색으로 푸는 경우 가짓수를 쳐내더라도 시간초과가 발생할 수 있음

// 조합으로 만들 수 있는 최대값은 1000 이므로,
// 이를 활용하여 미모아이제이션 방식을 사용

#define NUM 50
#define MAX 1000
#define DIV 10007

int N, M, H, ans;
int visit[NUM][MAX + 1], cnt[NUM][MAX + 1];
vector<int> block[NUM]; // 각 블록 정보

int DP(int idx, int val) {
	if (val < 0) return 0; // 음수 밑으로 내려가면 볼 필요 없음
	if (idx == N) return val == 0; // 모든 값을 다 없앤 경우, 1을 반환
	if (visit[idx][val]) return cnt[idx][val]; // 이미 방문한 기록이 있다면 반환
	visit[idx][val] = 1;

	cnt[idx][val] += DP(idx + 1, val); // 해당 케이스를 선택하지 않고 만드는 경우
	for (int w : block[idx]) { // 각 케이스를 선택하여 만드는 경우
		cnt[idx][val] += DP(idx + 1, val - w);
	}
	return cnt[idx][val] %= DIV; // 값을 요구사항에 맞춰 나눈 후 저장
}

int main() {
	cin >> N >> M >> H;

	for (int k = 0; k < N; k++) {
		// 주어지는 값은 학생이 가질 수 있는 블록의 최대값
		// so, 각 학생이 갖는 블록의 수는 이보다 적을 수 있음
		do {
			int w;
			cin >> w;
			block[k].push_back(w); // 블록 크기를 받아서 벡터에 삽입
		} while (getchar() != '\n'); // 뒤에 나온 글자가 공백이면 넘어감
	}

	cout << DP(0, H) << endl;
}