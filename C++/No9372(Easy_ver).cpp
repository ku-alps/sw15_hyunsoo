#include<iostream>
#include<vector>
using namespace std;
// 상근이의 여행
// 사실 공식을 알면 너무 의미없는 문제
// cause, 사이클이 없고, 모든 노드를 연결하는 그래프의 조건 중,
// 엣지의 조건은 항상 갯수가 n-1이라는 점을 사용하면 답이 입력과 함께 해결되어버림

int country, plane; //도시 수, 비행기 종류

int main() {
	int loop;
	cin >> loop; // 반복 횟수

	while (loop--) {
		cin >> country >> plane;

		while (plane--) {
			int from, to;
			cin >> from >> to;
		}
		cout << country - 1 << endl;
	}
}