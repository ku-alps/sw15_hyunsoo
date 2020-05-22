#include<iostream>
#include<vector>
using namespace std;


int book, people; //책, 사람 수
int range[1000][2]; // 각 사람별 책의 범위값
int have[1000]; // 책을 가진 사람들에 대한 역참조
bool visit[1000]; //방문 여부값
int ans[1000];

int Binary_Match(); // 이중 매칭 함수
int DFS(int want); // 이중 매칭에서 사용할 재귀함수

int main() {
	int loop;
	cin >> loop; // 테스트 케이스
	
	for (int k = 0; k < loop; k++) {
		cin >> book >> people; // 책 수, 사람 수
		for (int k = 0; k < book; k++) {
			have[k] = -1;
		}
		ans[k] = Binary_Match();
	}
	for (int k = 0; k < loop; k++)
		cout << ans[k] << endl;
	
}

int Binary_Match() {
	for (int k = 0; k < people; k++) 
		cin >> range[k][0] >> range[k][1]; // 범위를 입력받음

	int count = 0;

	for (int k = 0; k < people; k++) { // 모든 사람들에게 책을 가질 기회 제공
		for (int i = 0; i < people; i++) // 각 사람들이 책을 바꿀 기회를 초기화
			visit[i] = false; 
		count += DFS(k);
	}
	return count;
}

int DFS(int want) {
	if (visit[want]) return 0; // 방문한 적이 있는 경우 재방문 x
	visit[want] = true; //방문 했음
	for (int k = range[want][0] - 1; k < range[want][1]; k++) { //모든 선호 책에 대해서
		if (have[k] == -1 || DFS(have[k])) {
			// 빈 방이거나, 해당 주인이 다른 방으로 옮겨갈 수 있으면
			have[k] = want; // 방을 차지
			return 1;
		}
	}

	return 0; // 반복문 동안 return 값이 없으면 실패
}