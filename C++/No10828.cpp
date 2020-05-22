#include<iostream>
#include<string>
using namespace std;
// 스택
// 라이브러리가 존재하지만, 실 구현을 하기로 함

int top;
int s[10000]; // 스택에 사용할 배열

int main() {
	int loop;
	cin >> loop; // 명령 수행 횟수

	string toDo; // 명령
	for (int k = 0; k < loop; k++) {
		cin >> toDo;
		if (!toDo.compare("push")) { // push 인 경우
			cin >> s[top++];
		}
		else if (!toDo.compare("pop")) { // pop 인 경우
			int num = top != 0 ? s[--top] : -1;
			cout << num << endl;
		}
		else if (!toDo.compare("size")) { // size 인 경우
			cout << top << endl;
		}
		else if (!toDo.compare("empty")) { // empty 인 경우
			cout << (top == 0) << endl;
		}
		else if (!toDo.compare("top")) { // top 인 경우
			int num = top != 0 ? s[top - 1] : -1;
			cout << num << endl;
		}
	}
}