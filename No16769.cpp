#include<iostream>
using namespace std;
// Mixing Milk
// 서로다른 세 양동이에 우유가 있고
// 총 100회 양동이의 우유를 가득 차거나 빌 때 까지 이동
// 최종 상태에서 각 양동이 안의 우유의 양을 출력

class Bucket {
public:
	int limit; //최대 양
	int input; //현재 양
	int left; //빈 공간
	Bucket(); //생성자
	void operator+=(Bucket& from); // 연산자 오버로딩
};

int main() {
	Bucket buckets[3]; //3개의 양동이 생성

	for (int k = 0; k < 100; k++) {	
			buckets[(k+1) % 3] += buckets[k % 3]; //앞쪽을 전부 부어버림
	}

	for (int k = 0; k < 3; k++) { //출력
		cout << buckets[k].input << endl;
	}
	
}

Bucket::Bucket() { //생성자
	cin >> limit >> input; //값을 입력받아 넣어버림
	left = limit - input; //남은 공간 계산
}

void Bucket::operator+=(Bucket& from) { // += 연산자에 대해
	
	int can; //이동 가능한 우유량
	if (left - from.input > 0) // 다 넣어도 자리가 남는경우
		can = from.input;
	else //자리가 부족한경우
		can = left;

	from.input -= can; //넣을 수 있는만큼만 넣음
	input += can; //앞쪽을 전부 부어버리고
	
	left = limit - input; //값 갱신
	from.left = from.limit - from.input; // 갱신
}
