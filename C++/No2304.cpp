#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 창고 다각형
// 앞, 뒤로 높이를 검사하는 방식을 사용

int height[1001]; // 각 지점별 천막 높이
vector<pair<int, int>> line; // 기둥 정보

int main() {
	int cnt;
	cin >> cnt;
	for (int k = 0; k < cnt; k++) { // 입력
		int pos, height;
		cin >> pos >> height;
		line.emplace_back(pos, height);
	}

	// 순서별 정렬
	sort(line.begin(), line.end(), [](pair<int, int> a, pair<int, int> b)->bool {
		return a.first < b.first;
	});

	// 앞에서 천막을 치는 방식
	int front = 1, maxHeight = 0;
	for (auto l : line) {
		for (; front != l.first; front++) { // 기둥이 없는 지점 덮기
			height[front] = maxHeight;
		}
		maxHeight = max(maxHeight, l.second); // 더 높은 높이로 천막을 침
		height[front++] = maxHeight;
	}

	// 뒤에서 천막을 치는 방식
	int back = 1000, minHeight = 0;
	for (int k = line.size() - 1; k >= 0; k--) {
		auto l = line[k];
		for (; back != l.first; back--) { // 기둥이 없는 지점 덮기
			height[back] = minHeight;
		}
		if (height[back] == l.second) break; // 가장 높은 지점은 천막 높이가 동일
		minHeight = max(minHeight, l.second);
		height[back--] = minHeight;
	}

	// 각 지점별 천막 너비를 합산
	int sum = 0;
	for (int k = 0; k <= 1000; k++) {
		sum += height[k];
	}
	cout << sum << endl;
}