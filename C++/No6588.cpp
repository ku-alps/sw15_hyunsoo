#include<cstdio>
#include<vector>
using namespace std;
// 골드바흐의 추측
// 두 소수의 합으로 표현이 가능한지를 판단
// 즉, 에라토스테네스의 체를 통해 얻어낸 모든 소수에 대해
// 뺄셈을 수행하고 남은 값 또한 소수인지 판단하면 충분

#define MAX 1000001

int cnt[MAX];
bool arr[MAX]; // 방문 여부 배열
vector<int> v; // 소수만 모아둘 벡터

void eratos() {
	for (int k = 2; k <= MAX; k++) {
		if (arr[k]) continue; // 이미 방문한 경우 무시

		v.push_back(k); // 벡터에 넣음
		for (int m = 2; m * k <= MAX; m++) { // 모든 배수를 따라 방문
			if (arr[m * k]) continue; // 이미 방문한 경우 무시
			arr[m * k] = true;
		}
	}
}

int main() {
	eratos(); // 소수 획득

	int num;
	while (true) {
		scanf("%d", &num);
		if (num == 0) break; // 0 이 입력되면 종료
		for (int k = 0; v[k] <= num / 2; k++) {
			// 두 수의 합이므로 입력 크기의 절반까지만 확인하면 충분
			int rev = num - v[k];
			if (arr[rev]) continue; // 소수가 아니라면 무시
			printf("%d = %d + %d\n", num, v[k], rev); // 소수인 경우는 답을 출력 후 종료
			break;
		}
	}
}