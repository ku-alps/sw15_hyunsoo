#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Ceiling Function
// 트리를 구성한 후, DFS 탐색을 통해 모양을 '숫자'로 표준화 시킴
// 각 노드의 좌,우 노드 여부에 대한 정보를 표현해야 하므로,
// 총 2비트의 정보가 필요 (속도개선을 위해 간단한 비트연산 사용)
// 0 : 없음, 1 : 왼쪽 존재, 2 : 오른쪽 존재, 3 : 양쪽 존재

class Node {
public:
	int val; //노드 보유값
	int state; //좌,우 노드 보유상태
	Node *l, *r;
	Node(){}
	Node(int val);
};

int test; // 테스트 횟수
int node; // 노드 수
vector<long long int> ans; // 각 케이스 별 트리값을 저장할 벡터

void DFS(long long int& save, Node* here); // 값을 기록할 함수

int main() {
	cin >> test >> node; // 테스트 횟수, 노드 수 입력
	for (int k = 0; k < test; k++) { // 테스트 반복
		Node* root = NULL; // 트리의 루트
		for (int i = 0; i < node; i++) {
			int data;
			cin >> data;
			if (root == NULL) // 루트가 비어있으면 루트를 채우고 끝
				root = new Node(data);
			else {
				Node* make = new Node(data); // 새로 만든 노드
				Node* move = root; // 이동할 현재 노드
				while (true) {
					if (move->val > data) { //현재위치가 받은값보다 크면
						if (move->l == NULL) {
							move->state += 1; // 왼쪽이 있으면 1을 증가
							move->l = make; //만든 값을 넣음
							break; //할일 끝
						}
						move = move->l; //그 외엔 이동
					}
					else {
						if (move->r == NULL) {
							move->state += 2; // 오른쪽은 2 증가
							move->r = make; //만든 값을 넣음
							break; //할일 끝
						}
						move = move->r; //그 외엔 이동
					}
				} // 만든 노드 연결 끝
			}
		} // 값 입력 끝 (트리 생성)

		long long int result = 0; //결과를 저장할 변수
		DFS(result, root); // 해당 트리의 모양을 값으로 형상화
		ans.push_back(result); // 값을 넣음
	} // 모든 케이스에 대한 처리 끝

	sort(ans.begin(), ans.end()); // 벡터를 오름차 순 정렬
	int count = 1;
	for (int k = 1; k < ans.size(); k++) {
		if (ans[k - 1] < ans[k]) //앞서 나온 값보다 크면 종류 증가
			count++;
		// 해당 규칙이 왜 성립하는가?
		// 우선 오름차 순 정렬이므로, 값이 작은 경우는 존재 x
		// 값이 같은 경우는, 형상화된 트리의 모양이 동일하다는 의미
		// so, 이전값보다 큰 경우에만 새로운 모양이 등장했음을 의미
	}
	cout << count << endl;
}

Node::Node(int val) {
	this->val = val;
	state = 0;
	l = r = NULL;
}

void DFS(long long int& save, Node* here) {
	if (here == NULL)
		return;
	save <<= 2;
	save |= here->state; // 비트연산을 수행
	DFS(save, here->l);
	DFS(save, here->r); // 좌우에 대한 재귀
}