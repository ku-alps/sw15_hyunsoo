// 이진수
// 원리 이용

#include<iostream>
using namespace std;

int main() {
	int loop;
	cin >> loop;
	
	while(loop--) {
		int value;
		int pos = 0;
		cin >> value; // 값 입력
		do {
			if (value % 2 == 1) {
				cout << pos << " "; //1이면 출력
			}
			pos++;
			value /= 2; // 2진수로 만드는 과정
		} while (value != 0); //모두 쓸 때 까지
	}
}