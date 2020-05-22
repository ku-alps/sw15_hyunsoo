#include<iostream>
#include<math.h>
using namespace std;
// 상금헌터 (카카오 대회)
// 각 등수별 인원 수에 규칙이 존재
// 1차 시험의 경우 n+1
// 2차 시험의 경우 2의 배수
// 단, 상금은 정보가 없으므로 스위치 케이스 문으로 입력

int main() {
	int imagine; //상상 횟수
	cin >> imagine;

	int* first = new int[imagine];
	int* second = new int[imagine];

	for (int k = 0; k < imagine; k++) {
		cin >> first[k] >> second[k]; // 입력
	}

	for (int k = 0; k < imagine; k++) {
		int total = 0;

		if (first[k] != 0) {
			for (int i = 1; i < 7; i++) {
				first[k] -= i;
				if (first[k] <= 0) {
					switch (i) { // 루프의 횟수에 따라 등수가 결정됨 
					case 1:
						total += 500;
						break;
					case 2:
						total += 300;
						break;
					case 3:
						total += 200;
						break;
					case 4:
						total += 50;
						break;
					case 5:
						total += 30;
						break;
					case 6:
						total += 10;
						break;
					default:
						break;
					} //내가 얻은 상금을 더함
					break; //얻었으면 해당 반복문 끝
				}
			}
		}
		if (second[k] != 0) {
			for (int i = 1; i < 6; i++) { // 두번째 대회에 대해서도 시도
				second[k] -= (int)pow(2, i) / 2;
				if (second[k] <= 0) {
					switch (i) { // 루프의 횟수에 따라 등수가 결정됨 
					case 1:
						total += 512;
						break;
					case 2:
						total += 256;
						break;
					case 3:
						total += 128;
						break;
					case 4:
						total += 64;
						break;
					case 5:
						total += 32;
						break;
					default:
						break;
					} //내가 얻은 상금을 더함
					break; //얻었으면 해당 반복문 끝
				}
			}
		}

		cout << total * 10000 << endl; //만원단위이므로 4개 붙임
	}

	delete[] first;
	delete[] second;
}