// 디지털 루트
// 1의 자리를 10으로 올려 더해버리고
// 10의 자리를 1의 자리로 끌어당기는 방식
// 어차피 올림의 경우 수가 생겨도
// 다시 더하는 방식을 반복하기 때문에 가능
// 다만, 오버플로우 때문에 getchar로 문자열 입력을 받음

#include<iostream>
using namespace std;

int main(){

	int num;
	do {
		num = 0; // 정답 초기화
		while (true) {
			int get = getchar();
			if (get != '\n')
				num += get - '0'; 
				// 문자형태로 입력받으므로 '0'값만큼 뺌
			else // 엔터가 들어오면 반복문 끝
				break;
		}
		while (num >= 10) {
			// 10보다 크면 계속 반복
			num += (num % 10) * 10;
			num /= 10; // 갱신
		}
		if(num != 0)
			cout << num << endl;
	} while (num != 0);
		// 입력값이 0이 아니면 계속 진행
}