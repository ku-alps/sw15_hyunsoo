#include<iostream>
#include<math.h>
using namespace std;
// 달팽이
// 숫자를 중심으로부터 순차적으로 적어나가는 문제
// 단순한 규칙성을 이용할 예정
// 각 벽을 구성하는 숫자 수 = n + 2(n-1) + (n-2) = 5n-4

int main() {
	int size; //전체 루프
	int pos; //찾을 값
	cin >> size >> pos; //입력
	
	int** room = new int*[size]; //방을 생성
	for (int k = 0; k < size; k++) {
		room[k] = new int[size];
	} // 각 층은 동일한 수의 방으로 구성

	int an_x, an_y; //찾는 숫자의 위치를 잡을 좌표값 2개
	int value = size*size; //입력할 값

	int x = 0, y =0; //움직일 좌표
	for (int k = 0; k < (size + 1) / 2; k++) {
		// 제곱수를 전부 채울 때 까지
		while (y < size - k - 1) { //아래로 이동
			if (value == pos) { //원하는 값이라면
				an_x = x + 1;
				an_y = y + 1; //위치 저장
			}
			room[x][y++] = value--; //값을 넣고 값을 감소시킴
		}
		while (x < size - k -1) { //오른쪽 이동
			if (value == pos) { //원하는 값이라면
				an_x = x + 1;
				an_y = y + 1; //위치 저장
			}
			room[x++][y] = value--; //값을 넣고 값을 감소시킴
		}
		while (y > k) { //위로 이동
			if (value == pos) { //원하는 값이라면
				an_x = x + 1;
				an_y = y + 1; //위치 저장
			}
			room[x][y--] = value--; //값을 넣고 값을 감소시킴
		}
		while (x > k+1) { //왼쪽 이동
			if (value == pos) { //원하는 값이라면
				an_x = x + 1;
				an_y = y + 1; //위치 저장
			}
			room[x--][y] = value--; //값을 넣고 값을 감소시킴
		}
	}
	
	room[x][y] = 1; // 반복문으로 넣지 못한 남은 값

	for (int k = 0; k < size; k++) {
		for (int i = 0; i < size; i++) {
			cout << room[i][k] << " ";
		}
		cout << endl;
	} //출력
	cout << an_y << " " << an_x << endl; //정답 출력

	for (int k = 0; k < size; k++) {
		delete[] room[k];
	}
	delete[] room; //메모리관리
}