#include<iostream>
#include<cmath>
using namespace std;
// 시험 감독
// 타입 선언 관련한 문제
// 100만 교실에 100만 인원이 가득 찬 상태로, 감독은 1명만을 담당하는 경우

#define NUM 1000000

int room, exam[NUM], B, C;

int main() {
	cin >> room;
	for (int k = 0; k < room; k++) cin >> exam[k];
	cin >> B >> C;

	long long int cnt = 0; // 오버 플로우 방지용
	for (int k = 0; k < room; k++) {
		cnt += 1;
		exam[k] -= B;
		if (exam[k] > 0) cnt += ceil((double)exam[k] / C); // double 역시 마찬가지
	}
	cout << cnt << endl;
}