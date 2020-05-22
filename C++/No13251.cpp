#include<iostream>
#include<cstdio>
// 조약돌 꺼내기
// 가장 보편적인 확률 계산법 중 하나
// 각 색상 별로 해당 색에서 뽑을 확률을 구한 후, 이를 모두 합함

using namespace std;

int cnt[50];
int total;
double rate;

int main() {
	int color;
	cin >> color;
	for (int k = 0; k < color; k++) {
		cin >> cnt[k];
		total += cnt[k];
	}
	int sel;
	cin >> sel;

	for (int k = 0; k < color; k++) { // 모든 조약돌 색에 따라서
		if (sel > cnt[k]) rate += 0; // 뽑으려는 수보다 작으면 확률 0
		else {
			double val = 1;
			for (int m = 0; m < sel; m++) { // 그 외에는 순차적으로 1개씩 봅아갈 확률을 계산
				val *= ((double)cnt[k] - m) / (total - m);
			}
			rate += val; //최종 결과에 출력
		}
	}
	printf("%.15f", rate);
	// 오차 허용 값이 소수점 9자리 수준이므로,
	// 소수점 출력을 조정하기 위해 printf 를 사용
}