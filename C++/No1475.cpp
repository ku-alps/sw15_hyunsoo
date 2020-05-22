#include<iostream>
using namespace std;
// 방 번호
// 6,9는 서로 바꿔쓸 수 있음
// 필요한 세트 수를 찾는데, count 소팅을 사용할 생각
// 6,9는 서로 섞어 쓸 수 있으므로 한 세트에 2개가 들어있다 가정
int main() {
	int num;
	int count[10] = {}; //카운팅에 사용할 숫자배열

	cin >> num;

	do {
		int one = num % 10;
		num /= 10;
		count[one]++; //각 숫자의 수를 측정
	} while (num != 0);
	// do while 을 쓰는 이유는 0이 입력되는 경우도 처리하기 위함

	count[6] += count[9]; //두 수는 같은 세트를 공유
	++count[6] /= 2; // 한 세트에는 수 2개가 들어감

	int max = 0;
	for (int i = 0; i < 9; i++) {
		max = max > count[i] ? max : count[i];
		// 두 값중 큰 값을 무조껀 선택
	}
	cout << max << endl;
}