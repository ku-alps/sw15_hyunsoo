#include<iostream>
#include<queue>
using namespace std;
// 1학년
// 각 연산으로 생성할 수 있는 수의 횟수를 모두 저장
// 이후 마지막 수를 인덱스로 값을 획득

#define SIZE 100 

int loop, num[SIZE];
long long int res[21]; // 결과값 저장 배열
// 제약조건에서 음수가 아니며 20을 넘는 값은 알 수 없으므로
// 크기 21로 충분

int main() {
	cin >> loop;
	for (int k = 0; k < loop; k++) {
		cin >> num[k];
	} // 입력

	res[num[0]] += 1;
	for (int k = 1; k < loop - 1; k++) {
		long long int calc[21] = {}; // 연산용 배열 (int 를 넘음)
		for (int m = 0; m < 21; m++) {
			if (res[m] == 0) // 0~20까지의 모든 수에 대해 
				continue;
			if (m + num[k] <= 20) // 현재 값을 덧셈으로 쓰는 경우
				calc[m + num[k]] += res[m];
			if (m - num[k] >= 0) // 뺄셈으로 쓰는 경우
				calc[m - num[k]] += res[m];
		}
		for (int k = 0; k < 21; k++) { // 만들 수 있는 case 를 갱신
			res[k] = calc[k];
		}
	}
	cout << res[num[loop - 1]] << endl; // 마지막 값은 등호
}