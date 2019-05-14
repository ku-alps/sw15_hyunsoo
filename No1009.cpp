// 분산 처리
// math 함수 내의 pow값을 사용할 생각이었으나
// long long 타입으로도 오버플로우가 나버려 포기
// 1의 자리만 사용하는 알고리즘

#include<iostream>
using namespace std;

int main() {
	int loop; //반복 횟수
	cin >> loop;

	int *ans = new int[loop]; //동적할당

	for (int k = 0; k < loop; k++) {
		int sub, pow;
		cin >> sub >> pow; // 값과 지수 입력

		ans[k] = sub; // 첫 값은 sub 값 그대로
		for (int i = 1; i < pow; i++) {
			ans[k] = (ans[k] * sub) % 10 != 0 ? (ans[k] * sub) % 10 : 10;
			//1의 자릿수만 알면 충분
			//10으로 나눠서 딱떨어지면 10번째 컴퓨터가 처리하니 예외처리
		}
	}

	for (int k = 0; k < loop; k++) {
		cout << ans[k] << endl;
	}

	delete[] ans; //할당 해제
}