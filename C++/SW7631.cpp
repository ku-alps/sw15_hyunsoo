#include<iostream>
using namespace std;
// 안녕
// h,e,l,o,w 의 수를 count 하고
// 가장 작은 수를 선택하면 됨

int main() {
	
	int loop;
	cin >> loop; // 테스트 케이스
	cin.get(); // getchar의 오류를 없애기 위한 버퍼제거


	int answer[50] = {}; //각 케이스 별 정답
	for (int k = 0; k < loop; k++) {
		
		int list[4] = {};
			// 값을 할당
			// 순서대로 h, e, l, o
		while (true) {
			char get;
			cin.get(get);
			if (get != '\n') {
			
				switch (get) { // 각 값별로 카운트
				case 'h':
					list[0]++;
					break;
				case 'e':
					list[1]++;
					break;
				case 'l':
					list[2]++;
					break;
				case 'o':
					list[3]++;
					break;
				default:
					break;
				}
			}
			else
				break;
		}


		int least = 10001; //최소값
		for (int i = 0; i < 4; i++) {
			if (i == 2 && list[i] / 2 < least) {
				least = list[i] / 2; // l은 따로 제거
			}
			else if (list[i] < least)
				least = list[i]; // 그 외의 경우
		}
		answer[k] = least; // 정답 저장
	}
	for (int k = 0; k < loop; k++)
		cout << "#" << k + 1 << " " << answer[k] << endl; // 출력
}