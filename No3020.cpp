#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// 개똥벌레
// 석순과 종유석의 등장 순서는 의미가 없음 (고정된 높이에 따라 충돌여부 결정)
// so, 입력값을 석순, 종유석으로 분류 및 정렬
// 이후, 각 높이멸 충돌 횟수 중 가장 작은 최소값을 선택, 카운팅

// +) 해당 문제는 값의 연속성이 보장되지 않으므로 파라매트릭 서치를 사용 불가
// so, 프로님은 세그먼트 트리 2개를 만들어 풀이 (석순, 종유석)


vector<int> btm, top; // 석순, 종유석 높이
int sum[500000], sum2[500000]; // 높이에 따른 충돌 갯수

int main() {
	int loop, h;
	cin >> loop >> h; // 가로 길이, 높이

	for (int k = 0; k < loop; k++) {
		int len;
		cin >> len;
		if (k % 2) top.push_back(len); // 짝수면 종유석
		else btm.push_back(len); // 홀수면 석순
	}
	sort(top.begin(), top.end());
	sort(btm.begin(), btm.end()); // 높이에 따른 정렬

	int iter = top.size() - 1; // 종유석에 대해서
	for (int k = h - 1; k >= 0; k--) {
		int cnt = 0; // 갯수
		while (iter >= 0 && top[iter] == k) { // 중복되는 값 여부 체크
			cnt += 1;
			iter -= 1;
		}
		if (k != h - 1)	sum[k] += sum[k + 1]; 
		sum[k] += cnt; // 높이순 정렬이므로 이전 값을 끌어와서 통합
	}

	iter = btm.size() - 1; // 석순에 대해서
	for (int k = 0; k < h; k++) { // 높이
		int cnt = 0;
		while (iter >= 0 && h - btm[iter] == k - 1) {
			cnt += 1;
			iter -= 1;
		}
		if (k != 0)	sum2[k] += sum2[k - 1];
		sum2[k] += cnt;
		sum[k] += sum2[k]; // 기존 종유석 수에 석순 수를 추가하여 갱신
	}

	int cnt = 0, min = 200000;
	for (int k = 0; k < h; k++) { 
		if (min > sum[k]) {
			cnt = 1;
			min = sum[k];
		}
		else if (min == sum[k])
			cnt += 1;
	} // 모든 높이를 탐색하며 최소 충돌 수와 가능한 높이 수를 체크
	cout << min << " " << cnt << endl;
}


