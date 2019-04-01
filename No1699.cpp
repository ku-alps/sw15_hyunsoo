#include<iostream>
using namespace std;
// 제곱수의 합
// 다이나믹 프로그래밍 사용
// 이전까지의 최단 합을 비교하여 최단 경로를 측정

int main() {

	int num;
	cin >> num; // 값 입력

	int* record = new int[num + 1]; // 입력받은 값 크기만큼의 기록을 남김
		// 0부터 입력받은 값까지의 배열이므로 num+1
	record[0] = 0; // 숫자 0을 채우는 방법은 아무것도 더하지 않은 값 0   
	for (int i = 1; i < num + 1; i++) { //모든 배열을 채울 때 까지 실행
		
		int select = i - 1; //선택할 index 번호
		int loop = 1; // 루프를 돌릴 놈 
		int save = i - 1;
			// 우선 내 밑에꺼 +1이 일단 정해진 최단거리
		while (save >= 0) { //save 값이 접근가능한 인덱스 범위 안쪽이면 계속해서

			if (record[select] > record[save]) { 
				// 새로 얻어온 값이 내가 선택했던 값보다 더 좋으면
				// 구성되는 수가 적을수록 좋음
				select = save; // 선택
			}
			loop++; // 루프 더함
			save = i - (loop * loop); // save 값 변환
			  // 현재 넣을 값공간에서
			  // 해당 루프의 제곱을 빼면서 접근 
		}
		record[i] = record[select] + 1; // 증가
	}

	cout << record[num] << endl; //출력

	delete[] record;
}