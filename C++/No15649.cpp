#include<iostream>
using namespace std;
// N과 M (1)
// 걸리는 시간이 C보다 느리긴 하지만 정답은 맞음..
// 출력으로 인해 걸리는 시간인데, 이걸 어디서 줄이라는걸까

void DFS(int tag);

int n, m;
int stack[8]; //스택
bool use[8]; //false 초기화

int main() {
	cin >> n >> m;
	DFS(0);
}

void DFS(int tag) {
	
	if (tag == m) {
				for (int i = 0; i < m; i++) { //현재까지의 순열을 출력
					cout << stack[i]+1 << " ";
				}
				cout << endl; // 한 순열 끝
				return;
	}
	else { //순열의 마지막 부분이 아니라면, 재귀호출
		for (int k = 0; k < n; k++) { //모든 수를 살펴보며
			if (!use[k]) { //아직 사용 안된 수가 있으면
				stack[tag] = k;
				use[k] = true; //이미 사용된 부분은 사용했음을 표기
				DFS(tag + 1); //재귀호출
				use[k] = false; //이미 사용된 부분은 사용했음을 표기
			}
		}
	}
}