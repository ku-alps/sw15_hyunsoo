#include<iostream>
// 떡먹는 호랑이
using namespace std;

// 피보나치 수열의 응용문제. 재귀함수
// 사용할 방식 : 결국 정수배의 덧셈이므로,
// 해당 날짜에서의 a,b 의 수를 계산 (재귀함수)
// 이후 각 값을 정수를 대입해가며 값 예측

int day; //총 날짜

void Check(int* a_count_first, int* b_count_first, int* a_count_second, int* b_count_second, int& index);
//횟수 계산 함수 (재귀)

int main() {
	int first_a = 1;
	int first_b = 0;
	int second_a = 0;
	int second_b = 1;
	int index = 3; //인덱스 값은 3부터 시작

	int rice_cake; //그날 준 떡의 수
	cin >> day >> rice_cake; //값 입력

	Check(&first_a, &first_b, &second_a, &second_b, index);

	int last_a = first_a + second_a;
	int last_b = first_b + second_b; //최종 비율

//	cout << last_a << "\t" << last_b << endl;

	// 수식에 의하면 Ma + Nb = 떡


	for (int i = 0; i < rice_cake / last_a; i++) { // 나눌 수 있는 수 만큼
		int leftover = rice_cake - last_a * i; // 먼저 a의 크기를 예측
		
		if ( leftover % last_b == 0 ) {
			//딱 떨어지는 경우

			cout << i << "\n" << leftover / last_b << endl; //출력
			break;
		}
	}
}

void Check(int* a_count_first, int* b_count_first, int* a_count_second, int* b_count_second, int& index) {
	//a (첫날), b(둘쨋날)이 전체 떡 결정에 얼마나 자주 나왔는가

	if (day > index) { // 현재 계산중이 날짜가 범위 안이라면
		switch (index%2)
		{
		case 0: // 짝수 날 (2,4,6,8..) second를 건드림
			*a_count_second += *a_count_first;
			*b_count_second += *b_count_first;
			break;
		case 1: //홀수 날 (3,5,7,9...) first를 건드림
			*a_count_first += *a_count_second;
			*b_count_first += *b_count_second;
			break;
		default:
			break;
		}
		index++; //인덱스 증가
		Check(a_count_first, b_count_first, a_count_second, b_count_second, index);
		//재귀 호출
	}

}