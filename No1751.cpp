#include<iostream>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;
// 디버깅
// input 사이즈 최대 300 * 300, 시간제한 5초
// so, 조건에 성립하는 결과들을 추려 정보를 확장시켜나가는 방식을 사용
// 스퀘어 킬러의 크기가 짝,홀인 경우를 각각 나누어 처리해야 하는 번거로움이 존재했음

#define NUM 300

int R, C;
char datas[NUM][NUM];
queue<tuple<int, int, int, int>> q; // x,y, 크기, 홀/짝

// 홀수 크기 데이터 : 중심점 좌표 (x,y), 중심점을 기준으로 떨어진 거리 s, 홀수 flag 1
// 짝수 크기 데이터 : 비교 시작점 좌표 (x,y), 비교지점까지의 거리 s (실 거리의 절반), 짝수 flag 0

bool Check(int x, int y, int s, int select) {
	if (select) { // 크기 값이 홀수인 경우
		// 홀수 데이터의 좌표는 중심점 정보
		if (x - s < 0 || x + s >= R || y - s < 0 || y + s >= C) return false; // 끝에 도달해서 확장 불가능

		// 가로 원소들에 대한 비교
		int top_x = x - s, top_y = y - s, btm_x = x + s, btm_y = y + s; 
		for (int k = 0; k < 2 * s + 1; k++) {
			if (datas[top_x][top_y + k] != datas[btm_x][btm_y - k]) return false; // 다른 경우 실패
		}

		// 세로 원소들에 대한 비교
		int left_x = x - s, left_y = y - s, right_x = x + s, right_y = y + s;
		for (int k = 0; k < 2 * s + 1; k++) {
			if (datas[left_x + k][left_y] != datas[right_x - k][right_y]) return false; // 다른 경우 실패
		}
	}
	else { // 크기 값이 짝수인 경우
		// 짝수 데이터의 좌표는 비교 구간의 좌측 최상단
		if (x < 0 || x + (2 * s - 1) >= R || y < 0 || y + (2 * s - 1) >= C) return false; // 끝에 도달해서 확장 불가능

		// 가로 원소들에 대한 비교
		int btm_x = x + (2 * s - 1), btm_y = y + (2 * s - 1);
		for (int k = 0; k < 2 * s; k++) {
			if (datas[x][y + k] != datas[btm_x][btm_y - k]) return false; // 다른 경우 실패
		}

		// 세로 원소들에 대한 비교
		int right_x = x + (2 * s - 1), right_y = y + (2 * s - 1);
		for (int k = 0; k < 2 * s; k++) {
			if (datas[x + k][y] != datas[right_x - k][right_y]) return false; // 다른 경우 실패
		}
	}

	return true; // 그 외엔 성공
}

int main() {
	cin >> R >> C;
	for (int k = 0; k < R; k++) {
		for (int m = 0; m < C; m++) {
			cin >> datas[k][m];
			q.push(tuple<int, int, int, int>(k, m, 1, 1)); // 모든 값들이 기본적인 스퀘어 킬러 (홀수)
		}
	}

	for (int k = 0; k < R - 1; k++) { // 짝수 크기를 갖는 스퀘어 킬러
		for (int m = 0; m < C - 1; m++) {
			q.push(tuple<int, int, int, int>(k, m, 1, 0));
		}
	}

	int ans = 1;
	while (!q.empty()) { // 큐에서 값을 꺼내가며 판단
		tuple<int, int, int, int> data = q.front();
		q.pop();

		int x = get<0>(data), y = get<1>(data), s = get<2>(data), select = get<3>(data); // 정보를 각각 얻어내고
		if (Check(x, y, s, select)) { // 조건이 성립하는지 확인
			ans = max(ans, 2 * s + (select)); // 성립하는 스퀘어 킬러 중, 가장 큰 값을 선택
			q.push(tuple<int, int, int, int>(x + (select - 1), y + (select - 1), s + 1, select)); // 확장된 버전을 큐에 다시 삽입
		}
	}
	cout << ans << endl; // 정답 출력
}