#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
// 별자리 만들기
// N개의 '좌표'가 주어지고, 엣지는 주어지지 않았으므로
// 노드 사이를 연결하는 모든 엣지 NxN개를 모두 고려

class Pos { // 좌표르 보관할 타입
public:
	float x, y;
	Pos();
	Pos(float i_x, float i_y);
};

int num; // 별의 수
float total; // 스패닝 트리의 최종 답
int group[100]; // 유니온파인드 전용
Pos star[100]; // 별 위치 정보
float length[100][100]; // 각 별 사이의 거리를 계산하여 저장할 배열
vector<int> sort; // 엣지를 정렬시킬 벡터

int Find(int here);
void Union(int a, int b); // 그래프 연산에 의해 Union-find 연산이 필수적

int main() {
	cin >> num; // 별의 갯수
	for (int k = 0; k < num; k++) { // 별 갯수만큼 입력, 처리연산
		float x, y;
		cin >> x >> y;
		star[k] = Pos(x, y); //별의 좌표를 입력받아 저장

		group[k] = k; // 초기세팅

		for (int i = 0; i < k; i++) {
			float ans = sqrtf(powf(star[i].x - x, 2.0f) + powf(star[i].y - y, 2.0f));
			// 두 별의 대각선 거리를 측정
			length[i][k] = ans; // 엣지는 쌍방향으로 2개가 생기나
								// 중복은 불필요하므로 배열 한칸에만 저장

			for (int j = 0; j <= sort.size(); j++) { //벡터에 값을 비교하며 정렬삽입 할 예정
				if (sort.size() == j) {
					sort.push_back(i * 100 + k); // 마지막까지 도달하면 끝에 삽입
					break; //종료
				}
				if (length[sort[j] / 100][sort[j] % 100] > ans) {
					// 내가 넣고자 하는 값보다 큰 놈을 만나면, 현재 위치에 정착
					sort.insert(sort.begin() + j, i * 100 + k);
					break; //빠져나옴
				}
			}
		} // 입력된 별들과 계산 끝
	} //입력 완료

	for (int k = 0; k < sort.size(); k++) {
		// 입력한 모든 엣지을 기반으로 계산 시작
		Union(sort[k] / 100, sort[k] % 100); // 엣지 수만큼 반복
	}
	cout << fixed; // 소수점 자릿수만 고정
	cout.precision(2); // 소수점 밑 2자리까지 표기
	cout << total << endl; //정답 출력
}

Pos::Pos(){}
Pos::Pos(float i_x, float i_y) { // 생성자
	x = i_x;
	y = i_y;
}

int Find(int here){ // 주어진 값의 소속 그룹 대표값을 찾는 함수
	if (group[here] == here) return here;
	return group[here] = Find(group[here]);
}

void Union(int a, int b){ // 합집합 함수
	int root_a = Find(a);
	int root_b = Find(b); // 각각의 루트값을 찾음
	if (root_a != root_b) { // 다른 곳에 소속 된 경우, 합쳐야 함
		group[root_a] = root_b; // 루트르 서로 연결
		total += length[a][b]; // 주어진 엣지를 사용, 총 합을 더함
	}
}