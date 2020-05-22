#include<iostream>
#include<queue>
#include<functional>
using namespace std;
// 소수의 곱
// 가능한 모든 조합에 대해 우선순위 큐를 사용
// but, push 조건에 제약을 두지 않아서 메모리가 터지는 문제가 발생

int arr[100]; // 입력 값을 저장할 배열
priority_queue<int,vector<int>,greater<int>> pq; // 오름차순 우선순위 큐

int main() {
	int loop, idx;
	cin >> loop >> idx;

	for (int k = 0; k < loop; k++) {
		cin >> arr[k];
		pq.push(arr[k]); // 큐에 삽입
	}

	long long int num = 0;
	long long int before = 0;
	while (idx) { // 번호에 일치할 때까지
		num= pq.top(); // 데이터를 하나 꺼내오고
		pq.pop();
		if (num == before) continue; // 이전에 봤던것과 동일하면 건너뜀 (중복 확인)
		for (int k = 0; k < loop; k++) {
			long long int n = arr[k] * num; // 뽑은 값에 대해 가능한 모든 값을 생성
			if (n < 2147483648) // 크기제한을 두는 이유는 큐가 너무 커져서 터지기 떄문
				// so, 불필요한 데이터는 push 하지 않아서 속도를 개선
				pq.push((int)n); // 입력된 소수들을 곱해 큐에 추가
		}
		before = num; //갱신
		idx--; // 번호표 감소
	}
	cout << num << endl;
}