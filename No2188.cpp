#include<iostream>
#include<vector> //동적할당 (벡터) 사용
using namespace std;
// 축사배정

const int MAX_NUM = 200; // 최대 숫자

int cow, cage; // 소와 철창 수
int isThere[MAX_NUM]; // 각 철창의 소 번호
bool visit[MAX_NUM]; // 각 철창의 방문 여부
vector<vector<int>> prefer; //각 소의 선호 장소 저장 벡터

void Binary_Match();
int Search(int who);

int main() {
	cin >> cow >> cage;
	prefer.resize(cow); // 벡터의 크기 조정
						// 만일 -1이 아닌 0으로 방을 세팅하면, 소의 index 번호는 0을 피해야한다
						// = 1부터 시작해야 함
						// cause, 빈 방을 판단하는 과정에서 0번 소는 방이 비어있는 것과 동등하게 판단되기 때문

	for (int k = 0; k < cage; k++)
		isThere[k] = -1; // 역참조 주소 초기화

	for (int k = 0; k < cow; k++) {
		int count;
		cin >> count; // 선호하는 방의 수

		for (int i = 0; i < count; i++) {
			int like;
			cin >> like;
			prefer[k].push_back(like); // k번째 벡터에 정보 추가
		}
	} // 소의 선호 철창 정보 갱신

	Binary_Match(); //호출
}

void Binary_Match() {
	int ans = 0; // 정답

	for (int k = 0; k < cow; k++) { // 모든 소들에 대해서 방을 잡아줄 예정
		for (int i = 0; i < cow; i++)
			visit[i] = false;
		ans += Search(k);
		// 각 소 별로, 1번씩 방을 잡으려 시도
		// 성공할 경우 방을 잡은 소의 수가 +1
		// 아닌 경우는 무시
	}
	cout << ans << endl; // 답을 출력
}

int Search(int who) { //해당 소에 대해 방문 시도
	if (visit[who]) return 0; // 해당 소에 대해 다시 시도하려는 경우 종료
	visit[who] = true; // 방문했다고 표기

	for (int k = 0; k < prefer[who].size(); k++) { // 소가 선호한다고 말한 철창 모두에 대해
		int room = prefer[who][k] - 1; // 이미 방을 차지하고 있던 소의 정보

		if (isThere[room] == -1 || Search(isThere[room])) {
			// 방이 비어있거나, 혹은 해당 방을 가진 소를 다른 방으로 옮길 수 있으면
			isThere[room] = who; //해당 방은 이놈이 차지
			return 1; // 매칭된 소 +1
		}
	}
	return 0; //모든 철창에 대해 매칭 실패할 경우 끝
}
