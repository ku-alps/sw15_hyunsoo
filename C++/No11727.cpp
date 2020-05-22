#include<iostream>
#include<math.h>
using namespace std;

int main() {
	int size; // 타일 크기
	cin >> size; //입력

	int* count = new int[size + 1]; //0~size 만큼의 배열 선언
	count[0] = 1; // 0짜리 사이즈는 놓지 않는 것 뿐 (1개)
	count[1] = 1; // 1짜리 사이즈는 1개 뿐

	for (int k = 2; k < size + 1; k++) { // 반복문 시도
		count[k] = (2 * count[k - 2] + count[k - 1]) % 10007;
		// 각 타일에서, 2칸이 늘어나는 경우의 수는
		// 2x1 타일 2개를 붙이거나, 2x2 타일 하나를 붙이거나
	}
	cout << count[size] << endl;
	//마지막 위치를 요구하는 나머지 값으로 출력
	delete[] count; // 메모리 관리
}