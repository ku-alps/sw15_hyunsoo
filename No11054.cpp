#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 가장 긴 바이토닉 부분 수열
// 다이나믹 프로그래밍을 사용하여 정보를 얻고
// 얻어낸 정보를 통합하여 골라내는 방식을 사용

int loop;
int max_up[1000]; //앞 인덱스 중 자신보다 작은 값
int max_down[1000]; //뒤 인덱스 중 자신보다 작은 값
int total[1000]; //총합
vector<int> list; // 데이터 입력

int Up(int index); //점점 커지는 규칙을 확인
int Down(int index); //점점 작아지는 규칙을 확인
void DP(); //다이나믹 프로그래밍

int main() {
	cin >> loop; // 배열 크기
	
	for (int k = 0; k < loop; k++) {
		int d;
		cin >> d;
		list.push_back(d);
		max_up[k] = -1; // 정보배열 초기화
		max_down[k] = -1;
	}
	
	DP();
}

int Up(int index) { //현재 위치의 인덱스와, 나를 부른놈의 값
	if (max_up[index] != -1) //이미 기록된 값이 있다면
		return max_up[index]; //종료
	max_up[index] = 0; //일단 왔음
	for (int k = 0; k < index; k++) { // 모든 하위 놈들에 대해 호출
		if (list[k] < list[index]) //점점 커지는 규칙이 성립하면
			max_up[index] = max(max_up[index], Up(k) + 1);
			//호출 후, 녀석이 갖고 있는 값을 받아 비교하여 최대값을 추출
	}
	return max_up[index];
}

int Down(int index) { //현재 위치의 인덱스와, 나를 부른놈의 값
	if (max_down[index] != -1) //이미 기록된 값이 있다면
		return max_down[index]; //종료
	max_down[index] = 0; //일단 왔음
	for (int k = index + 1; k < loop; k++) { // 모든 하위 놈들에 대해 호출
		if (list[index] > list[k]) //점점 작아지는 규칙이 성립하면
			max_down[index] = max(max_down[index], Down(k) + 1);
		//호출 후, 녀석이 갖고 있는 값을 받아 비교하여 최대값을 추출
	}
	return max_down[index];
}

void DP() {
	for (int k = 0; k < loop; k++) { //모든 상황에 대하여 계산
		Up(k);
		Down((loop - 1) - k);
	}
	for (int k = 0; k < loop; k++) 
		total[k] = max_up[k] + max_down[k] + 1; 
	// Up,Down 값을 합하여
	// 각 인덱스가 중심이 되었을 경우, 최댓값을 구함

	cout << *max_element(total,total+loop) << endl; //최댓값을 골라 출력
}