#include<iostream>
#include<string>
using namespace std;
// 잃어버린 괄호
// '최솟값'이 되기 위해선
// 최대한 큰 음수를 만들어야 한다는 규칙을 사용

int main() {
	string str;
	cin >> str; //문자열을 입력받고 처리할 생각

	int sign = 1; // 부호 정보. 첫 수가 양수인 경우 예외처리를 위함
	int total = 0; // 전체 합
	int calc = 0; // 계산용 중간 합
	int num = 0; // 각 숫자 하나하나

	for (char c:str) { // 문자열 안에 있는 각 문자 c에 대해서
		if (c == '-' || c == '+') { // 연산자를 만난 경우
			calc += num; //숫자 한세트를 끝내서 연산
			num = 0; // 숫자 초기화
			if (c == '-') { //음수부호인 경우
				total += calc * sign; 
				calc = 0; // 전체 계산 수행 및 초기화
				sign = -1; // 예외 상황에 대한 세팅
			}
		}
		else  // 숫자인 경우
			num = num * 10 + (c - '0'); //숫자 추출
			// 기존 정보를 10의 자리로 올리고 1의 자리를 더함
	}
	calc += num; // 마지막 숫자는 연산자를 만나지 못해 연산이 안되므로 연산 처리
	total += calc * sign;
	
	cout << total << endl;
}