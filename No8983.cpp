#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// 사냥꾼
// 라인 스위핑 방식을 사용하여
// 해당 문제에 대해 필요한 부분만 확인해가는 방법을 채택

class XY {
public:
	int x, y;
	XY() {}
	XY(int i_x, int i_y);
};

int sand, ani, length; // 사대 수, 동물 수, 사정거리
vector<int> s_pos; // 사대의 위치 정보
vector<XY> a_pos; // 동물의 위치정보

int main() {
	cin >> sand >> ani >> length; // 사대 수, 동물 수, 사정거리 입력
	for (int k = 0; k < sand; k++) {
		int a;
		cin >> a;
		s_pos.push_back(a); // 각 사대위치 입력
	}
	s_pos.push_back(2000000000); // 가장 끝으로 조건 상 넘을 수 없는 값을 추가
	// 반복문에서 예외처리를 간편화하기 위함
	
	for (int k = 0; k < ani; k++) {
		int x, y;
		cin >> x >> y;
		a_pos.push_back(XY(x, y)); // 동물의 위치정보를 넣음
	}

	sort(s_pos.begin(), s_pos.end()); // 사대 정렬
	sort(a_pos.begin(), a_pos.end(), [](XY a, XY b)->bool { // 동물 정렬
		if (a.x == b.x)
			return a.y < b.y;
		return a.x < b.x;
	}); // x,y 기준에 따라 

	int ans = 0, check[2] = { 0,1 }; // 잡을 수 있는 동물 수, 사대 번호
	for (int k = 0; k < a_pos.size(); k++) { //모든 동물을 다 보면서
		while (s_pos[check[1]] <= a_pos[k].x) { // 우선 감싸는 놈을 만날 때까지 반복
			// 마지막 값은 조건 상 넘을 수 없으므로 걱정 x
			check[0]++;
			check[1]++; // 모두 한칸 씩 옆으로 이동
		} // 해당 동물을 기준으로 좌 우 사대가 결정됨

		for (int i = 0; i < 2; i++) { // 두 사대에서 동물을 쏠 수 있는지 확인
			if (abs(s_pos[check[i]] - a_pos[k].x) + a_pos[k].y <= length) {
				ans++; // 잡을 수 있으면 값 증가
				break; // 반복문 끝
			}
		}
	}

	cout << ans << endl; // 출력
}

XY::XY(int i_x, int i_y) {
	x = i_x;
	y = i_y;
}