#include<iostream>
using namespace std;
// 문자열 화폐
// 정확한 길이, 정확한 값, 정렬 순 이라는 세 조건
// so, 해당 길이의 문자열을 기본으로 만든 후,
// 필요에 따라 뒤부터 화폐 값을 변화해가는 방식을 사용

#define ALP 25

int N, X;

int main() {
	cin >> N >> X;
	
	string str;
	for (int k = 0; k < N; k++) { // 기본 문자열 생성
		str += 'A';
		X -= 1;
	}
	for (int k = N-1; k >= 0 && X > 0; k--) {
		// 모든 화폐에 대해 남은 화폐 값만큼 추가로 더함
		if (X >= ALP) { // A 를 Z 로 바꿀만큼 충분히 남았다면
			str[k] += ALP;
			X -= ALP; // 변환
		}
		else { // 부족한 경우
			str[k] += X;
			X -= X; // 남은거 전부 사용함
		}
	}
	str = !X ? str : "!"; // X 값이 0이 아닌 경우, 실패
	cout << str << endl;
}