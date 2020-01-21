#include<iostream>
#include<string>
using namespace std;
// 큐
// STL 이 존재하지만 실 구현을 목표로 함

int main() {
	int loop;
	cin >> loop;

	int h = 0, t = 0; // 큐의 앞, 뒤 인덱스
	int q[10000] = {}; // 큐 초기화

	string toDo;
	for (int k = 0; k < loop; k++) {
		cin >> toDo;
		if (!toDo.compare("push")) { // push 인 경우
			cin >> q[t++];
		}
		else if (!toDo.compare("pop")) { // pop 인 경우
			int num = h != t ? q[h++] : -1;
			cout << num << endl;
		}
		else if (!toDo.compare("size")) { // size 인 경우
			cout << t - h << endl;
		}
		else if (!toDo.compare("empty")) { // empty 인 경우
			cout << (t == h) << endl;
		}
		else if (!toDo.compare("front")) { // front 인 경우
			int num = h != t ? q[h] : -1;
			cout << num << endl;
		}
		else if (!toDo.compare("back")) { // back 인 경우
			int num = h != t ? q[t - 1] : -1;
			cout << num << endl;
		}
	}
}