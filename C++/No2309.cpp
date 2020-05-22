#include<iostream>
#include<algorithm>
using namespace std;
// 일곱 난쟁이

bool check[9]; // 정답체크용

int main() {
	int dwarf[9]; // 9명의 키 정보
	int total = -100; //맞춰야 할 키 정보

	for (int k = 0; k < 9; k++) {
		cin >> dwarf[k];
		total += dwarf[k]; // 모든 키의 합
	}

	sort(dwarf, dwarf + 9); //정렬

	bool find = false;	// 다양한 정답이 나올 수 있기 때문에
						// 정답 하나를 찾으면 멈춤
	for (int k = 0; k < 8; k++) {
		for (int i = k + 1; i < 9; i++) {
			if (dwarf[k] + dwarf[i] == total) {
				check[k] = check[i] = true; // 이 둘을 뺀 나머지의 키가 조건에 성립
				find = true;
			}
		}
		if (find)
			break;
	}
	
	for (int k = 0; k < 9; k++) {
		if (!check[k]) { // 일곱 난쟁이가 맞다면 출력
			cout << dwarf[k] << endl;
		}
	}
}