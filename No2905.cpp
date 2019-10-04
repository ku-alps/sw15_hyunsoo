#include<iostream>
#include<algorithm>
using namespace std;
// 홍준이와 울타리
// 라인 스위핑의 응용방법으로 풀려고 시도
// but, 연산처리가 너무 많은지 시간초과

int stick, roller; // 판자 수, 롤러 수
int r_count, brush; // 롤러질 횟수, 칫솔질 해야하는 범위
int success[1000000]; // 칠하는데 성공한 판자 높이
int height[1000000]; // 판자 높이 체크

int main() {
	cin >> stick >> roller; // 값 입력
	for (int k = 0; k < stick; k++)
		cin >> height[k]; // 높이값 입력

	int index = 0; // 현재 인덱스 위치
	int last_h = 0; // 마지막으로 칠한 높이
	bool out = false; // 끝나는 여부

	while (!out) { //모든 스틱을 다 볼 때 까지
		// 여기서 예외처리 필요
		if (index >= stick) // 칠하는 널판지 크기를 벗어났으면 종료
			break;

		if (last_h >= height[index]) { // 현재 최대 높이보다 높은 지점까지 칠했다면
			last_h = height[index]; // 이전에 칠할 방법이 있단 이야기
			int add = 0;
			for (int k = 0; k < roller && height[index] >= last_h; k++) {
				// 같은 높이가 있으면 쭉 칠함
				success[index + add] = last_h;
				if ( height[index] == last_h) //높이가 같은경우에만 다 칠했으니 인덱스 이동
					index += 1; // 옆으로 옮기면서
				else
					add++;

				if (index + add >= stick) {
					out = true;
					break;
				}
			}
		}
		else {
			if (index + roller >= stick)
				out = true; // 이번에 나감
			int* mini;

			if (!out) // 아직 끝에 도달 안했으면
				mini = min_element(&height[index], &(height[index]) + roller);
			//현재 위치~ 롤러가 닿을 수 있는 곳 까지
			else // 이제 마지막이면
				mini = min_element(&height[stick - roller], &(height[stick]));
				// 롤러로 밀 수 있는 최대 크기만큼 밀어버림
			for (int k = 0; k < roller; k++)
				success[index + k] = max(success[index + k], *mini);
			// 이미 칠해진 값과 이번에 칠할 값 중 큰 값으로 선택
			last_h = *mini; // 마지막으로 칠한 값 저장
			index = (mini - height); // 두 주소의 차이값 = 인덱스 번호
				// 또한 해당 위치는 이미 다 칠한상태 -> 다음 위치로 넘어감 (+1)

			while (index != stick && success[index] == height[index])
				index++; //범위를 넘지않고 다 칠한 판자를 가리키고 있으면 다음으로 넘김
		}
		r_count++; 
	}
	for (int k = 0; k < stick; k++)
		brush += height[k] - success[k]; // 칠해야 하는 판자 범위
	cout << brush << endl << r_count << endl; // 출력
}

// 고려할점 : 같은높이의 막대가 있을 때, 길이가 짧아서 못칠하게 된 경우 -> 예외처리 필요