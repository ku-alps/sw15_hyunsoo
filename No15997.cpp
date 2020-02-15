#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
// 승부 예측
// 데이터 크기가 작으므로, 모든 case를 완전 탐색하여 확률을 결정
// 중복이 생기는 경우, 확률을 동일하게 분배해아 하므로,
// 간편한 처리를 위해 hash map 을 사용하여 중복을 체크

#define SCORE_F "310" // first의 점수 획득 순서
#define SCORE_S "013" // second의 점수 획득 순서

int score[4]; // 각 팀의 점수
double cnt[4], percent[6][3]; // 각 팀의 진출 확률, 승패 확률 (3 경우)
pair<int, int> vs[6]; // 두 팀의 경쟁 순서
unordered_map<string, int> keys; // 팀명과 고유번호

void DFS(int idx, double rate) {
	if (idx == 6) { // 끝까지 다 본 경우, 우승자 판단
		vector<int> select;
		unordered_map<int, int> check;
		for (int k = 0; k < 4; k++) {
			select.push_back(k); // 고유번호 삽입
			if (check.find(score[k]) != check.end()) check[score[k]] += 1; // 이미 등장한적이 있는 수면
			else check[score[k]] = 1; // 없었다면 초기화
		}
		sort(select.begin(), select.end(), [](int a, int b)->bool {
			return score[a] > score[b]; // 점수의 오름차 순으로 정렬
			});

		int max_v = check[score[select[0]]]; // 정렬 순으로 가장 큰 수가 중복이 몇번 있는지 확인
		if (max_v > 1) { // 1번 이상 등장했다면, 이후 값은 볼 필요없음
			for (int k = 0; k < max_v; k++) {
				int code = select[k]; // 고유 번호
				cnt[code] += 2 * (rate / max_v); // 이놈이 이길 확률 추가
				// 다만, 값이 동일하면 랜덤확률이며, 자리는 2개이므로 2를 곱함
			}
		}
		else {
			cnt[select[0]] += rate; // 1등은 기본 처리
			int sub_v = check[score[select[1]]]; // 중복 수 확인
			for (int k = 0; k < sub_v; k++) { // 중복 수만큼 나눠서 확률을 저장
				int code = select[k + 1]; // 고유 번호
				cnt[code] += rate / sub_v; // 이길 확률 추가
			}
		}
		return;
	}

	for (int k = 0; k < 3; k++) { // 3 가지 경우
		score[vs[idx].first] += SCORE_F[k] - '0';
		score[vs[idx].second] += SCORE_S[k] - '0'; // 각 경우, 각 팀이 얻을 수 있는 점수값

		DFS(idx + 1, rate * percent[idx][k]); // 선택한 경우와 확률을 넘겨서 재호출
	
		score[vs[idx].first] -= SCORE_F[k] - '0';
		score[vs[idx].second] -= SCORE_S[k] - '0'; // 해당 케이스 원상복구
	}
}

int main() {
	for (int k = 0; k < 4; k++) {
		string team;
		cin >> team;
		keys[team] = k;
	} // 각 팀 명 및 고유번호를 설정

	for (int k = 0; k < 6; k++) {
		string first, second;
		cin >> first >> second;
		vs[k] = pair<int, int>(keys[first], keys[second]); // 매칭되는 팀의 고유 번호를 기록
		for (int m = 0; m < 3; m++) cin >> percent[k][m]; // first 가 second 를 [이길/비길/질] 확률
	}

	DFS(0, 1.0); // 0번 인덱스부터, 기본 확률은 1
	for (int k = 0; k < 4; k++) { // 결과를 전부 출력
		cout << cnt[k] << endl;
	}
}