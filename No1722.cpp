#include<iostream>
using namespace std;
// 순열의 순서
// 빠른 속도를 위해 메모아이제이션을 사용

int s;
long long int cnt[21];
bool visit[21];

long long int Cnt(int n) { 
	if (n == 0)	return 1; // 모든 자리를 다 사용
	if (cnt[n] != 0) { // 이미 방문했다면 반환
		return cnt[n];
	}
	cnt[n] = n * Cnt(n - 1); // 해당 위치가 가질 수 있는 조합 수
	return cnt[n];
}

void Q1() {
	long long int sel;
	cin >> sel;
	int ka = 1;
	while (sel != 0) {
		long long int a = Cnt(s - ka); // 현재 자리의 뒷부분이 만들 수 있는 조합 수
		long long int q = (sel - 1) / a + 1; // 몇 번째 블록을 사용하는가?
		int check = 0; // 블록 등장 횟수
		int aaa = 0; // 사용하는 카드 번호
		while (check != q) {
			aaa += 1;
			if (!visit[aaa]) { // 아직 쓰지 않은 카드라면, 블록에 등장 가능
				check += 1;
			}
		}
		visit[aaa] = true; // 선택된 카드를 사용
		cout << aaa << " "; // 출력
		sel %= a; // 남은 위치의 상대적 순서를 구함
		ka++; // 남은 자릿수 감소
	}
	for (int k = s; k > 0; k--) { // 그 외 출력되지 않은 놈들은 순차적으로 출력
		if (!visit[k])
			cout << k << " ";
	}
}

void Q2() {
	long long int sum = 1;
	int arr[21];
	for (int k = 1; k <= s; k++) {
		cin >> arr[k]; // 값 입력
		long long int a = Cnt(s - k); // 뒷자리 조합 경우의 수

		int check = 0;
		visit[arr[k]] = true; // 해당 카드를 사용하였음
		for (int m = 1; m < arr[k]; m++) {
			if (!visit[m]) { // 자신이 해당 위치에서 몇번째로 등장하는지 판단
				check++;
			}
		}
		sum += check * a; // 그 곱만큼 순서 증가
	}
	cout << sum; // 출력
}

int main() {
	cin >> s;
	int ques;
	cin >> ques; // 문제 종류

	switch (ques)
	{
	case 1: // k 번째 순열
		Q1();
		break;
	case 2: // 주어진 순열의 번호
		Q2();
		break;
	default:
		break;
	}
}
