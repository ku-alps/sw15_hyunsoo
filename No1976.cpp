#include<iostream>
using namespace std;
// 여행 가자
// 도시끼리 연결이 되어야 계획대로 움직일 수 있다는 점에 초점을 둠
// so, 각 도시가 하나의 유니온으로 이루어져 있는지만을 판단

class Link { //도시의 연결 정보
public:
	Link * link;
	Link();
};

int city, schedule;
Link Bridge[200];

int main() {
	cin >> city >> schedule;
	
	for (int k = 0; k < city; k++) {
		for (int i = 0; i < city; i++) {
			// NxN 번 만큼 루프를 돌며 연결여부를 입력받음
			int a;
			cin >> a;
			if (a)  // 연결 여부는  0 또는 1로 입력되므로, 1인 경우 참
				if (k <= i) { // 이때, 연결은 대칭성을 띄게 됨
					// so, 중복입력을 피하기 위해 행렬의 크기 정보를 비교
					Link* find = &Bridge[i];
					while (find->link != NULL) { // 빈 칸을 찾을 떄 까지 계속 돌림
						find = find->link; //해당 칸으로 이동
					}
					find->link = &Bridge[k]; // i부터 거슬러 올라간 노드에서 k로 연결
				}
		}
	} // 그래프 생성

	int to = -1; // 한 번에 두개의 노드만을 비교할 예정
	Link* from = NULL, *find = NULL;
	while (schedule--) {
		from = find; // 이전 정보를 저장
		cin >> to;

		find = &Bridge[to - 1];
		while (find->link != NULL) { // 빈 칸을 찾을 떄 까지 계속 돌림
			find = find->link; //해당 칸으로 이동
		}

		if (from != NULL) { // 첫 입력이 아니라면
			if (from != find) { // 비교하는 두 대상이 연결되어있지 않으면 절대 불가능
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	cout << "YES" << endl; // 반복문을 무사히 나온 경우 성공
	return 0;
}

Link::Link() {
	link = NULL;
}