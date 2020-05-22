#include<iostream>
using namespace std;
// 쉬운 계단 수
// 각 자리 별 숫자의 차이가 1일 것
// 1,000,000,000 으로 나눈 나머지 값을 출력
// 다이나믹 프로그래밍 사용 (배열, 반복)

int main() {
	int size; //크기 저장 변수
	cin >> size; // 입력

	int* count[10]; //0~9로 끝나는 모든 경우에 대해
	for (int i = 0; i < 10; i++) {
		count[i] = new int[size];
	} //동적 할당 배열 생성 (2차원)

	count[0][0] = 0; // 0으로 시작 및 끝은 없음
	for (int i = 1; i < 10; i++) {
		count[i][0] = 1; 
		// 길이가 1인 경우, 각 숫자로 끝나는 경우의 수는 1개
	}

	for (int k = 1; k < size; k++) {
		for (int i = 0; i < 10; i++) {
			int up = 0; //아래에서 위로 올라오는 경우
			int down = 0; // 위에서 아래로 내려오는 경우
			if (i < 1) // i 값이 1보다 큰 경우, 내려오는 값만 받음
				down = count[i + 1][k - 1]; //K-1 루프에서 i+1 값으로 끝난 경우 수
			else if (i > 8) // 8보다 큰 경우, 올라가는 값만 받음
				up = count[i - 1][k - 1]; //k-1 루프에서 i-1 값으로 끝난 경우 수
			else {
				up = count[i - 1][k - 1]; //k-1 루프에서 i-1 값으로 끝난 경우 수
				down = count[i + 1][k - 1]; //K-1 루프에서 i+1 값으로 끝난 경우 수
			}
			count[i][k] = (up + down) % 1000000000; //계산값을 넣음
		}
	}
	
	int total = 0; //전체 합
	for (int k = 0; k < 10; k++) {
		total += count[k][size - 1]; //값을 더하고
		total %= 1000000000; //나눠버림
	}
	cout << total << endl; //출력
		
	for(int i=0;i<10;i++)
		delete[] count[i]; //삭제
}