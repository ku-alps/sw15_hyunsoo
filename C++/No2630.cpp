#include<iostream>
using namespace std;
// 색종이 만들기
// 재귀함수를 사용한 방식
// 다만, 분할 여부를 판단하는 방식에서 합의 수식을 사용

void Cut(int size,int x,int y);

int** map;
int white, blue; //색 블록 수

int main(){
	int size;
	cin >> size; //크기 입력

	map = new int*[size]; 
	for (int k = 0; k < size; k++) {
		map[k] = new int[size];

		for (int i = 0; i < size; i++) // 입력
			cin >> map[k][i];
	} // 동적할당

	Cut(size, 0, 0); //재귀함수 호출
	cout << white << "\n" << blue << endl; 
	
	for (int k = 0; k < size; k++) {
		delete[] map[k];
	}
	delete[] map; //메모리 정리
	return 0;
}

void Cut(int size, int x, int y) { // 재귀함수

	int sum = 0;
	for(int k=0;k<size;k++){
		for (int i = 0; i < size; i++) {
			sum += map[x + k][y + i];
		}
	}
	// 각 값은 0 또는 1로 구성
	// so, 총합이 칸 수와 일치하면 성공

	if (sum == size * size) { // 성공
		blue++;
	}
	else if (sum == 0) { //전부 0인 경우
		//자를 필요 없음
		white++;
	}
	else { // 실패
		   //다시 자르기
		Cut(size / 2, x, y);
		Cut(size / 2, x + size / 2, y);
		Cut(size / 2, x, y + size / 2);
		Cut(size / 2, x + size / 2, y + size / 2);
		return;
	}
}