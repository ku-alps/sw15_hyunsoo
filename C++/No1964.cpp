#include<iostream>
using namespace std;
// 오각형
// 규칙을 활용하는 문제
// n번째 값 = n-1번째 값 + 4 + 3*(n-1)
// 이는 새로 생기는 테두리 꼭지점 + 각 변을 구성하는 점의 수

int main() {
	int level;
	cin >> level;
	int total = 5; //전체 점 수
	// 1단계에서는 점의 수를 고정
	for (int k = 1; k < level; k++) { // 1단계 스킵
		total = (total + 4 + 3 * k) % 45678; // 계산
	}
	cout << total << endl; // 출력
}