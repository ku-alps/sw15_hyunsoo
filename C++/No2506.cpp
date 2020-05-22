#include<iostream>
using namespace std;
// 점수계산 
// 배열을 쓰지 않고
// 단순 반복문으로 즉흥계산을 할 생각

int main() {
	int quiz; // 문제 수
	cin >> quiz;

	int point = 0; //전체 점수
	int result; //정답 여부
	int stack = 0; //쌓이는 점수
	for (int k = 0; k < quiz; k++) {
		cin >> result;
		result == 1 ? stack++ : stack = 0; 
		//결과가 정답이면 누적점수 +1, 아니면 점수없음
		point += stack; //총 점에 더함
	}
	cout << point << endl; 
}