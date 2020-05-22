#include<iostream>
using namespace std;
// 곱셈
// 단순한 규칙을 통한 수식성 계산을 사용할 예정

int main() {
	int first; //첫 입력 수
	int second; //두번째 입력 수

	cin >> first >> second;
	// 수 입력
	int save = second; //원본 보호를 위한 임시저장
	while (save != 0)	{
		// second를 계속 나누며 계산, second 값이 0이 되는순간 끝
		cout << first * (save % 10) << endl; //현재 second의 1의 자리와 곱셈
		save /= 10; //1의 자리를 버리고 자릿수를 옮김
	}
	cout << first * second << endl; // 최종 정답 출력
}