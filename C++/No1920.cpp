#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
// 수 찾기
// 데이터 크기가 10만, 탐색 횟수가 10만
// so, 단순 탐색을 사용하면 시간 초과 (100억)
// 이분 탐색을 사용

// 다만, 시간초과가 발생했는데 이는 cin, cout 의 시간지연으로 인한 문제
// cstdio 의 scanf, printf 로 변환하여 해결

int num, datas[100000], data_n, find_n;
int Binary_search(int start, int end);

int main() {

	scanf("%d", &data_n);
	for (int k = 0; k < data_n; k++) {
		scanf("%d", &datas[k]); // 입력받기
	}
	sort(&datas[0], &datas[data_n]); // 입력정보 정렬

	scanf("%d", &find_n); // 숫자 갯수 입력

	for (int i = 0; i < find_n; i++) {
		scanf("%d", &num); // 루프돌리면서 입력

		int start = 0, end = data_n - 1; 
		bool succ = false; // 성공 여부
		while (start <= end) { // 이분 탐색 시작
			int middle = (start + end) / 2;
			if (datas[middle] == num) { // 찾은 경우 종료
				succ = true;
				break;
			}
			else if (datas[middle] > num) { // 크면 좌측 탐색
				end = middle - 1;
				continue;
			}
			else { // 작으면 우측 탐색
				start = middle + 1;
				continue;
			}
		}

		if (succ) printf("1\n"); // 찾았으면 1
		else printf("0\n"); // 아니면 0
	}
}