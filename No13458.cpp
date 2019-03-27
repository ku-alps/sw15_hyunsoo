#include<iostream>
using namespace std;
// 시험감독 문제
// 각 시험장에는 총감독관 1명 필수, 그외 부감독관은 수 상관x

int main() {
	int room; //방 수
	int main; //총감독관 탐색 수
	int sub; //부감독관 탐색 수

	cin >> room;
	int* student = new int[room]; //각 방에 있는 인원 수를 저장할 공간	

	for (int i = 0; i < room; i++)
		cin >> student[i]; 
	cin >> main >> sub; //값 입력

	int sub_people = 0; // 부감독 수
	for (int i = 0; i < room; i++) {
		//모든 방에 대하여 각각 측정해야하고,
		//총감독 수는 room 수에 의해 결정이 되므로,
		//부감독의 수만 계산할 것

		student[i] -= main; //각 방마다 총감독이 볼 수 있는 사람을 제거
		while (student[i] > 0) { //만일 커버가 안되면
			sub_people++; 
			student[i] -= sub;
			//커버가 될 때 까지 계속 추가
		}
	}

	cout << sub_people + room << endl; //출력값은 부감독관+총감독관 수
}