#include<iostream>
using namespace std;
// 공

int main() {
	int cup[3] = { 1,0,0 };	//처음엔 1번 컵에 공
	int loop;
	cin >> loop; // 이동 횟수
	for (int k = 0; k < loop; k++) {
		int a, b;
		cin >> a >> b; //컵 번호 입력

		int swap = cup[a-1];
		cup[a-1] = cup[b-1];
		cup[b-1] = swap; // 교환
	}
	for (int k = 0; k < 3; k++)
		if (cup[k]) // 0이 아닌 값이라면
			cout << k + 1 << endl; // 출력
}
