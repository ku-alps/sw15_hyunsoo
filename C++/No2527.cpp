#include<iostream>
using namespace std;
// 직사각형
// 단순 구현
// '접한다' 라는 개념은 서로 다른 방향의 선분이 맞닿을 때만 허용됨

int main() {
	for (int k = 0; k < 4; k++) {
		int x1, y1, p1, q1, x2, y2, p2, q2;
		cin >> x1 >> y1 >> p1 >> q1 >> x2 >> y2 >> p2 >> q2;

		int state_x, state_y;
		state_x = ( x1 == p2 || p1 == x2 ) // 접하는 경우
			? 1
			: ((x1 < x2 && p1 < x2) || (x2 < x1 && p2 < x1)) // 겹치지 않는경우
				? 0
				: 2;
		state_y = ( y1 == q2 || q1 == y2 ) // 접하는 경우
			? 1
			: ((y1 < y2 && q1 < y2) || (y2 < y1 && q2 < y1)) // 겹치지 않는경우
				? 0
				: 2;

		switch (state_x * state_y) {
		case 0:
			cout << 'd' << endl;
			break;
		case 1:
			cout << 'c' << endl;
			break;
		case 2:
			cout << 'b' << endl;
			break;
		default:
			cout << 'a' << endl;
			break;
		}
	}
}