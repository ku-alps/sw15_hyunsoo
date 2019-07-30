#include<iostream>
using namespace std;
// 집합의 표현

class Group {
public:
	Group* root;
	Group();
}; // 포인터 정보를 갖고 있는 그룹

int total, loop;
Group group[1000000]; // 각 원소 정보

bool Equal(int a, int b, Group* pa, Group* pb); // 동일 집합 연산
void Union(int a, int b); // 합집합 연산

int main() {

	cin >> total >> loop;

	while (loop--) {
		bool toDo;
		int a, b;
		cin >> toDo >> a >> b; //수행할 연산 및 비교 대상


		if (toDo) { // 1인 경우, 단순 확인
			if (Equal(a, b, NULL, NULL)) //사용하지 않을 예정이므로 NULL 인자
				cout << "YES\n"; // 동일
			else
				cout << "NO\n"; // 다른 집합
		}
		else { // 0인 경우, 합집합
			Union(a, b);
		}
	}
}

Group::Group() {
	this->root = NULL;
}

bool Equal(int a, int b, Group* here_a, Group* here_b) {
	Group* pa = &group[a];
	Group* pb = &group[b];
	Group* move = NULL;
	Group* save = NULL;
	while (pa->root != NULL) { // NULL이 나올 때 까지 계속 찾음
		move = save;
		save = pa;
		pa = pa->root; // 트리형태를 역으로 쫓아감
		
		if(move != NULL) move->root = pa; // NULL이 아니면, 위로 건너 뛸 수 있도록 함
	}

	save = NULL;
	while (pb->root != NULL) {
		move = save;
		save = pb;
		pb = pb->root; // b에 대해서도 동일한 방법을 사용
					   // 거슬러 올라가는 형태의 트리에서, 결국 하나의 집합은 대표값 하나로 모이게 됨
		if (move != NULL) move->root = pb; // NULL이 아니면, 위로 건너 뛸 수 있도록 함
	}
	if (here_a != NULL) here_a = pa;
	if (here_b != NULL) here_b = pb; // 단순 탐색에서 예외처리

	return pa == pb; //두 위치의 동일 여부를 bool 값으로 return
}

void Union(int a, int b) {
	Group *here_a = &group[a], *here_b = &group[b];
	if (!Equal(a, b, here_a, here_b)) {
		//우선 두 위치가 같은 집합 내에 없어야 합칠 수 있음
		here_b->root = here_a; // 두 노드 중, 먼저 들어온 값으로 붙임
	}
}