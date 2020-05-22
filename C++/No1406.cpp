#include<iostream>
#include<stack>
using namespace std;
// 에디터

stack<char> l_q, r_q; // 커서 왼쪽, 오른쪽

int main() {
	string s;
	cin >> s;
	for (char ch : s) { // 문자열을 구성하는 각 문자
		l_q.push(ch); // 초기 커서는 문자열 맨 뒤이므로 앞쪽 문자부터 stack 에 쌓음
	}

	int loop;
	cin >> loop;
	for (int k = 0; k < loop; k++) {
		char toDo;
		cin >> toDo; // L, D, B, P

		if (toDo == 'L') { // 커서 왼쪽 이동
			if (l_q.empty()) continue; // 커서가 맨 앞인 경우
			r_q.push(l_q.top());
			l_q.pop(); // 왼쪽 스택의 최상단을 뽑아서 오른쪽으로 옮김
		}
		else if (toDo == 'D') { // 커서 오른쪽 이동
			if (r_q.empty()) continue; // 커서가 맨 뒤인 경우
			l_q.push(r_q.top());
			r_q.pop(); // 오른쪽 스택 값을 이동
		}
		else if (toDo == 'B') { // 문자 삭제
			if (l_q.empty()) continue; // 커서가 맨 앞인경우
			l_q.pop(); // 문자 삭제
		}
		else if (toDo == 'P') { // 문자 삽입
			char ch;
			cin >> ch; // 삽입할 문자를 추가로 입력
			l_q.push(ch);
		}
	}

	// 왼쪽 스택의 정보를 모두 오른쪽으로 몰아서 문자열 하나로 통합
	while (!l_q.empty()) {
		r_q.push(l_q.top());
		l_q.pop();
	}
	
	while (!r_q.empty()) { // 담긴 문자열 출력
		cout << r_q.top();
		r_q.pop();
	}
}