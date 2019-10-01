#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 수강 바구니 

int m[1000]; // 최대치
int bagunee[1000]; //바구니 정보
int list[1000]; // 성공한 대상 정보
int s, c; // 학생 수, 수업 수
vector<int> a[1000]; // 1차 수강 정보
vector<int> b[1000]; // 학생 백터
vector<int> ab[1000]; // 2차 수강 정보

int main() {
	cin >> s >> c; // 학생 s, 수강 c
	for (int k = 0; k < c; k++)
		cin >> m[k];

	for (int k = 0; k < s; k++) { // 1차 바구니에 대한 정보 입력
		while (true) {
			int ch;
			cin >> ch;
			if (ch == -1)
				break;
			ch--;
			bagunee[ch]++; // 증가
			a[ch].push_back(k);
		}
	}
	for (int k = 0; k < c; k++) { // 각 수업들의 초과 여부를 확인하면서
		if (bagunee[k] <= m[k]) { // 넘지 않았으면 (성공이면)
			list[k] += bagunee[k]; // 완전히 등록 성공
			bagunee[k] = 0; // 바구니 초기화
			for (int i = 0; i < a[k].size(); i++) {
				int num = a[k][i];
				b[num].push_back(k); // 각 학생들이 수강성공한 수업을 넣음
			}
		}
	}


	for (int k = 0; k < s; k++) { // 2차 바구니에 대해서 반복
		while (true) {
			int ch;
			cin >> ch;
			if (ch == -1)
				break;
			ch--;
			bagunee[ch]++; // 증가
			ab[ch].push_back(k);
		}
	}
	for (int k = 0; k < c; k++) {
		if (bagunee[k] + list[k] <= m[k]) { //성공하면
			list[k] += bagunee[k];
			for (int i = 0; i < ab[k].size(); i++) {
				int num = ab[k][i];
				b[num].push_back(k);
			}
		}
	}

	for (int k = 0; k < s; k++) { // 각 학생들을 돌리면서
		if (b[k].size() == 0) { // 넣은게 없다면 실패
			cout << "망했어요\n";
			continue;
		}
		sort(b[k].begin(), b[k].end()); // 넣은게 있다면 정렬 후 출력
		for (int i = 0; i < b[k].size(); i++) {
			cout << b[k][i] +1 << " ";
		}
		cout << "\n";
	}
}