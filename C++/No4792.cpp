#include<iostream>
#include<vector>
using namespace std;
// 레드 블루 스패닝 트리
// 모든 엣지가 1인 경우, 스패닝 트리의 경우 수를 따지는 문제
// 기존 재귀를 기반으로 한 Union Find 사용 시, 메모리 초과가 뜸
// so, 경로 압축 방식을 포기, 반복문으로 거슬러 올라가는 방식만 채택

int node, edge, b_edge; // 노드, 엣지, 파란 엣지 수
int group[1000]; // 1000개의 노드를 의미
vector<int> red, blue; // 각 노드의 연결 정보를 입력시킬 공간

int Red_First();
int Blue_First();
int Find(int here);
bool Union(int a, int b);
void reset();

int main() {
	while (true) {
		red.clear();
		blue.clear(); // 사이클 제한이 없으므로, 벡터 초기화 과정 필요

		cin >> node >> edge >> b_edge; // 입력
		if (node + edge + b_edge == 0) // 모든 입력값이 0인 경우 종료
			break; // 다만, 노드 조건이 2 이상이므로, node 값만을 비교해도 OK

		for (int k = 0; k < edge; k++) { // 엣지 수 만큼 입력
			char select; // 엣지 색 결정
			int node[2]; // 2개의 값
			cin >> select >> node[0] >> node[1];
			node[0]--;
			node[1]--; // 입력 노드 값과 사용 인덱스의 범주를 일치시킴

			if (select == 'R')  // 빨간 엣지인 경우
				red.push_back(node[0] * 1000 + node[1]); // 엣지정보를 암호화
			else
				blue.push_back(node[0] * 1000 + node[1]);
			// 모든 엣지(간선)의 weight 값은 동일하므로, 무조껀 뒤에 push
		} // 모든 엣지 입력 완료
	
		if (Red_First() <= b_edge && b_edge <= Blue_First())
			cout << 1 << endl;
		else
			cout << 0 << endl;
		// 어떤 색을 우선으로 사용했냐에 따른 blue 엣지 사용 값을 사용함
		// 반드시 필요한 갯수와, 최대로 활용 가능한 범주 내에 있는 경우
		// 해당 엣지 수를 가지는 스패닝 트리는 반드시 존재한다는 원리를 사용
	}
}

int Red_First(){ // 빨간 엣지를 우선 사용하는 경우
				 // 해당 case의 경우, '반드시 필요한' 파란 엣지의 수를 의미
	int red_first = 0;
	reset();
	for (int k = 0; k < red.size(); k++) { // 우선 빨간 엣지 우선
		Union(red[k] / 1000, red[k] % 1000); // 압축시킨 엣지 정보를 풀어서 건네줌
											 // 이 때, 빨간 엣지의 갯수는 중요하지 않으므로 무시
	}
	for (int k = 0; k < blue.size(); k++) { // 이후 파란 엣지 사용
		if (Union(blue[k] / 1000, blue[k] % 1000)) // 해당 엣지가 사용되는 경우, true를 반환하므로
			red_first++; // 엣지 사용 수를 증가시킴
	} 
	return red_first; // 반환
}

int Blue_First(){ //파란 엣지를 우선 사용하는 경우
				  // 빨간 엣지의 사용 여부는 중요하지 않으므로 생략
				  // 해당 case의 경우, '최대로 사용 가능한' 파란 엣지의 수를 의미
	int blue_first = 0;
	reset();
	for (int k = 0; k < blue.size(); k++) { // 파란 엣지를 먼저 사용하는 경우
		if (Union(blue[k] / 1000, blue[k] % 1000))
			blue_first++; // 파란 엣지 사용 수를 증가시킴
	} 
	return blue_first; //반환
}

int Find(int here){
	while (group[here] != here) { // 루트로 도달할 때까지
		here = group[here]; // 계속해서 거슬러 올라감
	}
	return here; //도달한 루트값을 반환
} // 기존 코드와 다르게 경로를 압축하는 과정이 존재하지 않음

bool Union(int a, int b) {
	int root_a = Find(a), root_b = Find(b);
	if (root_a != root_b) { // 루트가 다른 경우
		group[root_a] = root_b; // 하나로 합침
		return true; // 해당 엣지 사용함
	}
	return false; // 그외의 경우엔 무시
}

void reset() {
	for (int k = 0; k < node; k++)
		group[k] = k; // 각 노드의 대표값 초기화
}