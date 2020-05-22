#include<iostream>
using namespace std;
// 보이는 점의 개수
// 원점에서는 특정 (x,y) 좌표의 배수값은 막혀서 볼 수 없음
// 즉, 에라토스테네스의 체 방식을 응용한 문제

#define MAX 1000 // 맵의 최대 크기

int main() {
	int loop;
	cin >> loop; // 반복 횟수
	for (int k = 0; k < loop; k++) {

		bool visit[MAX + 1][MAX + 1] = {}; // 좌표 정보

		int size, cnt = 0;
		cin >> size;
		for (int k = 1; k <= size; k++) {
			for (int m = k + 1; m <= size; m++) { // 대각선을 중심으로 한 측면만 계산
				if (visit[k][m]) continue; // 방문한 경우 무시
				visit[k][m] = true;
				cnt++; // 원점에서 볼 수 있는 좌표 수 증가
				for (int n = 2; n * k <= size && n * m <= size; n++) {
					visit[n * k][n * m] = true; 
					// 해당 좌표와 일직선 상에 놓인 모든 좌표 제거
				}
			}
		}
		cnt *= 2; // 대각선을 기점으로 대칭 ( 2배 )
		cnt += 3; // 수직, 수평, 대각선은 따로 추가
		cout << cnt << endl; // 결과를 출력
	}
}