#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 선 긋기
// Line Sweeping 을 사용한 풀이법

class Line {
public:
	int s, e; //시작과 끝
	Line();
	Line(int i_s, int i_e);
};

int main() {
	int loop;
	vector<Line> line; // 가지고 있는 선 정보

	cin >> loop; //반복 횟수
	while (loop--) {
		int s, e;
		cin >> s >> e;
		line.push_back(Line(s, e));
	}

	sort(line.begin(), line.end(), [](Line a, Line b) -> bool {
		// false 값이 들어오는 경우에만 순서를 바꿈
		if (a.s == b.s) { // 시작점이 같은 경우
			return a.e < b.e; // 끝 지점이 큰 놈의 경우 바꿈
		}
		else return a.s < b.s;
	}); // sort 함수의 정렬 기준을 함수로 정의해줌

	for (int k = 0; k < line.size() - 1;) { // 정렬된 선을 합치는 과정
		if (line[k].e >= line[k + 1].s) { // 현재 직선과 그 다음직선이 겹치는 경우
			if (line[k].e < line[k + 1].e)  // 뒤쪽 직선이 더 있는경우
				line[k].e = line[k + 1].e; // 연결
			// 반대의 경우는 무시해도 됨
			line.erase(line.begin() + k + 1); //뒤쪽 위치 삭제
		}
		else
			k++; //그 외의 경우, 다음 직선으로 넘어감
	}

	int ans = 0;
	for (int k = 0; k < line.size(); k++) {
		ans += line[k].e - line[k].s; // 길이만큼 추가
	}
	cout << ans << endl;
}

Line::Line(){}
Line::Line(int i_s, int i_e){
	s = i_s;
	e = i_e; // 값 입력
}
