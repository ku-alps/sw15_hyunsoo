#include<iostream>
using namespace std;
// 받아올림

int main() {
	int a, b;
	while (1) {
		cin >> a >> b; //입력
		int up = 0; // 올림 총 카운터
		int isUp = 0; // 올림발생 여부

		if (a != 0 || b != 0) {//둘중 하나라도 값이 있으면
			while (a != 0 || b != 0) { // 다 나눌때 까지 반복
					// 두 값의 자릿수가 서로 다를 수 있으므로\
					// && 대신 || 사용
				isUp = (a % 10 + b % 10 + isUp) / 10; // 기존 올림값을 반영
				up += isUp;
				a /= 10;
				b /= 10;
			}
			cout << up << endl;
		}
		else break; //그 외엔 종료
	} 
}