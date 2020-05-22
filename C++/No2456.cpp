#include<iostream>
using namespace std;
// 나는 학급회장이다
// 문제를 제대로 안읽어서
// 점수가 아닌 "등수"를 적는 조건으로 착각

int ticket[9];
// 각 후보 1,2,3이 받을 표를 저장할 공간
// 전역변수로 선언하여 초기화 생략 (자동 0)
// 9개의 배열로 선언한 이유는 계산처리를 위함
// 후보 1 = 0~2번 방, 후보 2 = 3~5번 방, 후보 3 = 6~8번 방

int main() {
	int vote; // 투표 인원 수
	cin >> vote;
	for (int k = 0; k < vote; k++) {
		int rank; // 각 후보가 받을 랭크 값
		for (int i = 0; i < 3; i++) {
			cin >> rank;
			rank--; //랭크값 조정 (입력은 1~3이므로)
			ticket[i * 3 + rank]++;
			//계산수식으로 각 공간에 티켓 저장
		}
	}

	int best = 0; 
	for (int i = 0; i < 3; i++)
		best += ticket[i] * (i + 1); // 1번 후보의 총 값
	int win = 0; // 우선 1번 후보가 이겼다고 가정

	for (int k = 1; k < 3; k++) {
		int compare = 0;
		for (int i = 0; i < 3; i++)
			compare += ticket[3 * k + i] * (i + 1);
			// 가장 앞쪽 방부터 1,2,3점의 점수를 가짐

		if (best < compare) { // 비교값이 더 크면 
			best = compare;
			win = k; // 승자 변경
		}
		else if (best == compare) { // 만약 같은 경우면

			for (int i = 0; i < 3; i++) {
				int save;
				if (win == -1) { //공동 우승인 경우
					// -1값으로는 인덱스 접근이 불가하므로
					// 0으로 임의 세팅해줌
					// 어차피 해줘도, 후보 1,2는 동일한 점수
					save = 0;
				}
				else
					save = win;
				if (ticket[save * 3 + i] != ticket[k * 3 + i]) { // 같지 않고
					if (ticket[save * 3 + i] < ticket[k * 3 + i]) {// 새로 본 놈이 많으면 변경
						best = compare;
						win = k; // 승자 변경
					}
					break; //더 이상 볼 필요 없음
				}
				if (i == 2) { // 동메달까지 봤는데 판정이 안났다면
					//두놈은 같음
					win = -1; //일단은 승자가 없음
				}
			}
		}
	}
	cout << win + 1 <<" "<< best << endl; //출력
}