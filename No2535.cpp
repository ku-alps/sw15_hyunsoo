#include<iostream>
using namespace std;
// 처음에는 값 하나를 받으면서 갱신하는 방식을 선택
// but, 중복여부 처리 부분에서 문제가 생겨서 노선 변경

class Student {
public :
	int country; //도시번호
	int number; //참가번호
	int score; // 점수
	Student() {}
};

int over[100]; //중복 수를 체크할 배열
// 기존에는 memset을 활용하려했으나, 정의가 안되어있으므로
// 전역변수를 통한 초기화

int main() {
	int loop; // 참가자 수
	Student **list;
	cin >> loop; //참가자 수 입력

	list = new Student*[loop]; // 배열 생성
	for (int k = 0; k < loop; k++) {
		list[k] = new Student();
		cin >> list[k]->country >> list[k]->number >> list[k]->score; 
		//객체 값을 입력받음

		for (int i = k; i >= 1; i--) {
			if (list[i]->score > list[i - 1]->score) {
				// 새로 입력된 값이 자신의 앞쪽 값보다 크면
				Student* save = list[i - 1];
				list[i - 1] = list[i];
				list[i] = save; // 두 값의 자리를 바꿈
			}
			else // 만일 해당 규칙이 깨지지 않았으면
				break; // 그 앞쪽은 모두 정상 정렬. 종료
		} // 해당 구간은 매 반복문마다 실행되므로, 재귀적으로 성립
	}


	for (int k = 0, flag = 0; flag != 3; k++) { 
			// 배열을 훑을 k, 반복횟수 flag
			// 3개를 출력할 때 까지
		if (over[list[k]->country - 1] != 2) { // 2개가 아니라면
			cout << list[k]->country << " " << list[k]->number << endl;
			over[list[k]->country - 1]++; // 그놈을 선택하고 +1
			flag++;
		}
		// 아닌경우는 그냥 넘김
	}
}