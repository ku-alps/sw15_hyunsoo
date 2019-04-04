#include<iostream>
using namespace std;
// 개미
// 개미는 대각선으로 움직이며, 벽에 튕겨 부딪히면 반대 방향으로 전진
// 크게 두 방식이 존재하는데,
// 하나는 입력받은 시간만큼 실제로 돌리는 방법
// 나머지는 규칙에서 뽑아낸 계산 식을 이용하는 방법
// "대각선" 방향이므로, 상하와 좌우는 서로 영향x
// 즉, 1초에 한칸씩 증가하므로, 상하 t, 좌우 t 만큼 각각 이동

int main() {
	int width, height, x, y; //폭, 높이, 개미의 좌표	
	int time; //개미가 움직이는 시간
	cin >> width >> height >> x >> y >> time;

	int total_x, total_y; // 계산식에 사용할 변수
	total_x = time + x;
	total_y = time + y; // 벽에 제한이 없을 경우의 결과 좌표
	
	int ans_x, ans_y; // 정답
	ans_x = (total_x / width) % 2 == 0 ? total_x % width : width - (total_x%width);
	ans_y = (total_y / height) % 2 == 0 ? total_y % height : height - (total_y%height);
	// 해당 수식이 나오는 이유는,
	// 토탈 거리를 벽마다 접어내는 식의 개념이면 해결이 가능
	// so, 벽을 짝수로 접고 나머지가 남는경우는 해당 나머지가 좌표값
	// 홀수로 접고 나머지가 남는 경우는 그 반대 (벽 넓이 - 나머지)

	cout << ans_x <<" "<< ans_y << endl; 
}