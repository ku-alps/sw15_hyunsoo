#include<iostream>
#include<vector>
using namespace std;
// 최소 스패닝 트리
// Minimum Spanning Tree 중, 엣지의 weight 값을 모두 정럴 후 사용하는
// 크루스칼 알고리즘을 사용
// 다만, 사이클을 확인하는 과정에서 '유니온 파인드'의 개념이 들어감

class Edge {
public:
	int from, to, weight; // 두 정점과 무게
	Edge();
	Edge(int i_from, int i_to, int i_weight);
};

int v, e; // 노드, 엣지
int group[10000];
vector<Edge> sort; // 모든 엣지를 저장하고, 정렬할 벡터

int Minimum_Spanning_Tree();
bool Union(int a, int b);
int Find(int here);

int main() {
	cin >> v >> e;

	for (int k = 0; k < v; k++) { // 모든 노드들의 첫 깊이는 1
		group[k] = -1;
	}

	while (e--) {
		int from, to, weight;
		cin >> from >> to >> weight;

		if (sort.empty()) { // 우선적으로 vector가 비어있으면 작동이 안됨
			//so, 이를 1차적으로 걸러줌
			sort.push_back(Edge(from, to, weight));
			continue;
		}

		vector<Edge>::iterator it; // 이터레이터 (반복자)
		for (it = sort.begin(); it != sort.end(); it++) { // 먼저 0번 노드 정보를 삽입
			if (it->weight >= weight) { // 현재 반복자가 가리키는 놈의 무게가
				   // 삽입하고자 하는 데이터값보다 큰 경우, 멈춤 (크기순 삽입)
				sort.insert(it, Edge(from, to, weight));
				break;
			}
		} // 대소비교로 값을 넣고

		sort.push_back(Edge(from, to, weight));
		// 마지막까지 원소가 들어가지 않았다면, 강제로 끝에 넣음

	} // 엣지 값에 대한 입력 끝

	cout << Minimum_Spanning_Tree() << endl;
}

Edge::Edge(){}
Edge::Edge(int i_from, int i_to, int i_weight){
	from = i_from;
	to = i_to;
	weight = i_weight;
}

int Minimum_Spanning_Tree() {
	int total = 0;

	for (int k = 0; k < sort.size(); k++) {  //모든 엣지를 보면서
		Edge select = sort[k];
		if (Union(select.from - 1, select.to - 1)) // 연결을 시도
			total += select.weight; // 연결에 성공한 경우 무게 증가
	}
	return total; // 성공한 엣지들의 총 무게를 반환
}

bool Union(int a, int b) {
	int a_root = Find(a);
	int b_root = Find(b); // 두 노드의 소속 집합을 찾음

	int result = (a_root == b_root); // 결과값 비교

	if (!result) { // 다른 경우
		if (group[a_root] <= group[b_root]) { // 둘 중 깊이가 깊은걸 선택
				// 두 노드의 깊이가 동일할 수 있으므로, 상황에 따라 깊이가 1 증가하기도 함
			group[a_root] -= "10"[group[a_root] == group[b_root]] - '0';
			group[b_root] = a_root;
		}
		else
			group[a_root] = group[b_root]; // 그 외의 경우는 상관없음
	}

	return !result; // 연결 성공 시 true, 실패시 false 반환
}

int Find(int here) {
	if (group[here] == -1) return here; // 현재 위치 값이 -1이면 루트임을 의미
	return group[here] = Find(group[here]); // 그 외에는 세팅 이후, 세팅 값을 반환
}