#include<iostream>
#include<cstdio>
#include<queue>
#include<tuple>
using namespace std;
// 네트워크 연결
// 최소 스패닝 트리 문제
// so, 크루스칼 또는 프림 알고리즘을 사용

// 쌍 표현의 편의를 위해 tuple 타입을 선언, 우선순위 큐 사용
// tuple 의 경우, 각 인자 접근을 위해선 get<index>(tuple) 함수를 사용해야 함

struct my_fun { // 우선순위 큐의 우선순위 판단용 연산 객체
	bool operator()(tuple<int, int, int> a, tuple<int, int, int> b) {
		return get<2>(a) > get<2>(b); // a, b의 2번쨰 인덱스의 값을 받아옴
	} // 오름차순 정렬을 할 것이므로, 아래값 a가 더 커야 함
};

int N, M;
int arr[1001];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, my_fun> pq;

int F(int idx) { // Union-Find
	if (arr[idx] == idx) return idx;
	return arr[idx] = F(arr[idx]);
}

int main() {
	cin >> N >> M;
	for (int k = 1; k <= N; k++) {
		arr[k] = k;
	}
	for (int k = 0; k < M; k++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		tuple<int, int, int> edge(a, b, c); // 엣지 정보를 담은 튜플을 생성
		pq.push(edge); // 우선순위 큐에 넣음 ( 크루스칼 알고리즘 )
	}

	int sum = 0;
	while (!pq.empty()) { // 큐가 전부 빌 때 까지
		tuple<int, int, int> link = pq.top();
		pq.pop();
		int a_root = F(get<0>(link)), b_root = F(get<1>(link)); // 둘이 연결되어있는지 확인
		if (a_root != b_root) { // 다른놈인 경우
			sum += get<2>(link); // 해당 엣지를 사용할 것임
			arr[a_root] = b_root; // 연결
		}
	}
	cout << sum << endl;
}