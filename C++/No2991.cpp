#include<iostream>
using namespace std;
// 사나운 개
// 행동이 반복되므로, mod 연산을 활용하여 시간을 축소

int first[2], second[2]; // 두 개의 시간 정보
int Attack(int time);

int main() {
	int mail, milk, news; // 우체부, 우유배달부, 신문배달부

	cin >> first[0] >> first[1] >> second[0] >> second[1];
	cin >> mail >> milk >> news; // 데이터 입력

	cout << Attack(mail) << endl;
	cout << Attack(milk) << endl;
	cout << Attack(news) << endl; // 각 대상에 대해 짖는 횟수 출력
}

int Attack(int time) {
	int f_cycle = first[0] + first[1];
	int s_cycle = second[0] + second[1]; // 각 개가 행동을 반복하는 사이클 정보

	return ((time-1) % f_cycle < first[0] ? 1 : 0)
		+ ((time-1) % s_cycle < second[0] ? 1 : 0); 
	// 나머지 중, 0에 대한 예외처리가 필요
	// so, 입력된 값을 1 작게 만들어서 예외를 제거
}