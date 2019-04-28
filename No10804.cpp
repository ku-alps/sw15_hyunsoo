#include<iostream>
using namespace std;
// 카드 역배치
int main() {
	int card[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	// 사용할 카드 리스트
	// 시작은 정배열

	int start, end;
	for (int i = 0; i < 10; i++) { // 총 10번을 입력받음
		cin >> start >> end; // 입력
		start--;
		end--; // 실제로 배열에서 쓸 값은 하나 작은 값
		for (int k = 0; k < (end - start + 1) / 2; k++) {
			// 그 차이값의 절반만큼 서로 바꿀 생각
			int swap = card[start + k];
			card[start + k] = card[end - k];
			card[end - k] = swap; // 배열 범위를 역순으로 변경
		}
	}

	for (int i = 0; i < 20; i++) {
		cout << card[i] << ' '; // 출력
	}
	cout << endl;
}
