#include<iostream>
#include<string>
using namespace std;
// 지뢰 찾기
// 기본적으로 N*N의 배열이 핌요 (저장/계산/출력)
// 계산과 동시에 맵에 정보를 기록,갱신하는 방법

#define INF -1000; 
// 좌표 안에 들어갈 수 있는 최대 계산값은 9*8 = 48

int n; //맵 크기
int mine[1000][1000]; // 맵 정보

int main() {
	cin >> n;
	string info;
	for (int k = 0; k < n; k++) {
		cin >> info; // 문자열을 입력받은 후, 문자열의 각 위치별로 접근
		for (int i = 0; i < n; i++) {
			char ch = info[i]; //문자를 입력
			if (ch != '.') { //빈 공간표식이 아니라면 (지뢰가 있다면)
				mine[k][i] = INF; // 해당 자리를 음수로 만듦 (지뢰가 있음을 표기)
				int mine_num = ch - '0'; // 입력된 문자의 아스키값을 실값으로 변환
				for (int j = 0; j < 8; j++) { // 8방향에 대하여 값을 계산
					int x = k + "10001222"[j] - '1';
					int y = i + "22100012"[j] - '1'; // 아래부터 시계방향으로
					if (!(x < 0 || x >= n) && !(y < 0 || y >= n)) { // 맵을 넘어서지 않으면
						mine[x][y] += mine_num; // 갯수추가
					}
				}
			}
		}
	} // 입력 및 계산과정

	for (int x = 0; x < n; x++) { // 출력
		for (int y = 0; y < n; y++) { //N*N
				
			if (mine[x][y] < 0) // 음수는 지뢰가 있는 좌표
				cout << "*";
			else if (mine[x][y] > 9) // 10부터는 M으로 표기
				cout << "M";
			else
				cout << mine[x][y]; // 0~9는 정상출력
		}
		cout << "\n"; // 한 줄마다 줄바꿈
	} 
}