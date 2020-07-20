#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<int> solution(vector<int> A, vector<int> B) {
	vector<int> answer;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int cnt_a = 0, cnt_b = 0;
	queue<int> a, b;
	for (int k = 0; k < A.size(); k++) {
		if (k == 0) {
			cnt_a += 1;
			a.push(A[k]);
		}
		else {
			if (A[k - 1] != A[k]) {
				cnt_a += 1;
				a.push(A[k]);
			}
		}
	}
	for (int k = 0; k < B.size(); k++) {
		if (k == 0) {
			cnt_b += 1;
			b.push(B[k]);
		}
		else {
			if (B[k - 1] != B[k]) {
				cnt_b += 1;
				b.push(B[k]);
			}
		}
	} // Set 으로 만듦

	answer.push_back(cnt_a);
	answer.push_back(cnt_b);

	int sum = 0, inter = 0; // 합집합, 교집합
	while (!a.empty() && !b.empty()) {
		// 둘 모두 값이 존재해야 비교 가능
		sum += 1;
		if (a.front() < b.front()) a.pop(); // a값이 작은 경우
		else if (a.front() > b.front()) b.pop(); // b값이 작은 경우
		else { // 같은 경우
			inter += 1; // 교집합 증가
			a.pop();
			b.pop();
		}
	}
	while (!a.empty()) { // 남은 a 처리
		sum += 1;
		a.pop();
	}
	while (!b.empty()) {
		sum += 1;
		b.pop();
	}

	answer.push_back(sum);
	answer.push_back(cnt_a - inter);
	answer.push_back(inter);
	return answer;
}