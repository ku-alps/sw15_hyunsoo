#include<iostream>
#include<map>
using namespace std;
// 트리 순회
// 트리의 preorder, inorder, postorder traversal
// 이진 트리이므로 각 자식의 인덱스는 (N * 2 + 1), (N * 2 + 2)

char tree[50]; // 트리 구조로 사용할 배열
map<char, int> index; // 입력된 정보를 임시로 저장할 map
// 입력 순서에 특정한 조건이 붙지 않기 때문에
// 정보를 저장하고 빠르게 탐색하기 위한 수단이 필요했음

void front(int index);
void middle(int index);
void back(int index); // 수행 함수 (재귀)

int main() {
	int node;
	cin >> node;

	index['A'] = 0; // 루트는 A 이며, 배열 내 위치는 0
	tree[0] = 'A';
	for (int k = 0; k < node; k++) {
		char n, l, r;
		cin >> n >> l >> r; // 노드, 왼쪽, 오른쪽 자식

		int wh = index[n]; // 입력된 노드가 위치한 배열의 인덱스 값

		tree[wh * 2 + 1] = l;
		tree[wh * 2 + 2] = r; // 배열에서 자식 위치에 정보를 삽입

		index[l] = wh * 2 + 1;
		index[r] = wh * 2 + 2; // 맵에 인덱스 정보 저장
	}
	front(0); cout << endl;
	middle(0); cout << endl;
	back(0); cout << endl; // 함수 수행
}

void front(int index) { // 전위 탐색
	if (tree[index] == '.') return; // '.' 이라면 종료
	cout << tree[index];
	front(index * 2 + 1);
	front(index * 2 + 2);
}

void middle(int index) { // 중위 탐색
	if (tree[index] == '.') return; // '.' 이라면 종료
	middle(index * 2 + 1);
	cout << tree[index];
	middle(index * 2 + 2);
}

void back(int index) { // 후위 탐색
	if (tree[index] == '.') return; // '.' 이라면 종료
	back(index * 2 + 1);
	back(index * 2 + 2);
	cout << tree[index];
}