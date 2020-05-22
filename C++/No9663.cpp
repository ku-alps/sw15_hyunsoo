#include<iostream>
using namespace std;
// N-Queen
// 퀸의 이동 규칙성과 stack을 사용한 재귀적 풀이

int Put(int num);

int queen;
int stack[14];

int main() {
	cin >> queen; // 체스칸 크기 = 여왕 수

	int total = 0;
	if (queen == 1) // 1X1인 경우 예외처리
		total = 1;
	else {
		for (int k = 0; k < queen; k++) {
			// 그 외의 경우엔 0~queen-1까지 넣어가며 합을 구함
			stack[0] = k;
			total += Put(1);
		}
	}
	cout << total << endl;
}

int Put(int num) {
	bool line[14] = {}; // false이면 놓을 수 있음
	for (int k = 0; k < num; k++) { //내 위에 놓은 수 만큼
		line[stack[k]] = true; // 이미 놓은 라인은 놓을 수 없음

		int left = stack[k] - (num - k);
		int right = stack[k] + (num - k);
		if (left >= 0) // 0이 아니라면 (범주를 벗어나지 않으면)
			line[left] = true;
		if (right < queen) //범주를 벗어나지 않으면
			line[right] = true;
		//각 대각선으로 겹치는 부분 확인
	}

	if (num != queen - 1) { //아직 모든 단계를 가지 않았다면
		int total = 0;
		for (int k = 0; k < queen; k++) {
			if (!line[k]) { //놓을 공간이 있었으면
				stack[num] = k; // k번째 공간에 num번째로 둠
				total += Put(num + 1); // 재귀호출
			}
		}
		return total; //자식으로부터 받은 값을 모두 반환
	}
	else { // 마지막 단계이면
		for (int k = 0; k < queen; k++) {
			if (!line[k]) { //놓을 공간이 있었으면
				return 1; // 반환 (마지막 공간은 1개)
			}
		}
		return 0;  // 그 외엔 0개
	}
}