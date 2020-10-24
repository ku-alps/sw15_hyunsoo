#include<iostream>
#include<stack>
using namespace std;
// 소가 길을 건너간 이유 2
// 밀폐된 공간을 직선으로 뚫는다는 특징이 존재
// 이떄 선이 교차하는 경우는 테두리에 등장한 점의 순서가 서로 엉킬 때
// ( ex. 등고선 or HTML 구조를 생각 )

#define ALP 26
#define NUM 52

int cow[ALP]; // 알파벳 등장 횟수
stack<int> s; // 등장한 알파벳 정보 (테두리순)

int main() {
	int ans = 0;
	for (int k = 0; k < NUM; k++) {
		char ch;
		cin >> ch;
		int alp = ch - 'A';

		if (!cow[alp]) { // 첫 등장
			cow[alp] = 1;
			s.push(alp);
		}
		else { // 재등장
			stack<int> save;
			while (s.top() != alp) { // 두 사이에 낀 알파벳 저장
				save.push(s.top());
				s.pop();
			}
			s.pop(); // 같은 알파벳 제거
			ans += save.size(); // 사이에 낀 알파벳만큼 쌍이 생김

			while (!save.empty()) { // 다시 이동
				s.push(save.top());
				save.pop();
			}
		}
	}
	cout << ans << endl;
}