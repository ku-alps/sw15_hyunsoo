#include<iostream>
using namespace std;
// 김성렬 교수님 자작 문제
// 스타벅스

int main() {
	int loop;	
	cin >> loop; // 반복 횟수

	char answer[20]; //가능한 테스트 케이스는 최대 20개

	for (int k = 0; k < loop; k++) {
		int people, coffee, card; //인원 수, 커피 종류, 카드한도
		cin >> people >> coffee >> card;
		
		int list[20] = {}; //각 종류별 수를 측정할 목록
		// 커피 종류가 최대 20개이므로, 20개의 고정배열 사용

		for (int i = 0; i < people; i++) {
			int select;
			cin >> select;
			list[select - 1]++; //선호하는 커피 종류를 받고 갯수 증가
		}

		int total = 0;
		for (int i = 0; i < coffee; i++) {
			int price;
			cin >> price; //가격을 입력받고
			total += list[i] * price; //수*가격의 총 합
		}
		answer[k] = total <= card ? 'Y' : 'N'; //답 저장	
	}

	for (int k = 0; k < loop; k++)
		cout << "#" << k + 1 << " " << answer[k] << endl; // 출력

}