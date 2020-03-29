#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
// 선 긋기
// 주어지는 선에 대해 중복되는 부분을 없애고 합칠 필요가 존재함
// so, 세그먼트 트리 형식을 생각했으나 입력값의 범주가 너무 커서 불가능

// 따라서 각 선분을 앞, 뒤를 기준으로 정렬하며
// 중복 여부를 통해 선울 합치는 과정을 반복

stack<pair<int, int>> s; // 실제로 그어질 선 집합
vector<pair<int, int>> v; // 선을 정렬할 벡터

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); // 입출력 시간으로 인한 시간초과 방지

	int N;
	cin >> N;
	while (N--) { // 선분을 입력받음
		int a, b;
		cin >> a >> b;
		v.emplace_back(a, b);
	}
	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b)->bool { // 정렬
		return a.first != b.first ? a.first < b.first : a.second < b.second;
		});

	for (pair<int,int> line : v) { // 모든 선을 확인
		if (s.empty()) s.push(line); // 스택이 빈 경우, 그냥 사용
		else {
			int s_a, s_b, v_a, v_b;
			tie(s_a, s_b) = s.top(); // 현재까지 그어진 직선 중, 가장 최근을 선택
			tie(v_a, v_b) = line; // 다음에 그을 선을 불러옴

			if (s_b >= v_a) { // 두 선이 겹치는 경우
				s.pop();
				s.emplace(min(s_a, v_a), max(s_b, v_b)); // 두 선을 합침
			}
			else s.emplace(line); // 겹치지 않으면 그 자체로 사용
		}
	}

	int ans = 0;
	while (!s.empty()) { // 실제로 그어진 선을 확인하고 길이를 체크
		int a, b;
		tie(a, b) = s.top();
		s.pop();

		ans += b - a;
	}
	cout << ans << endl;
}