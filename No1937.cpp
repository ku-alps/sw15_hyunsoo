#include<iostream>
#include<algorithm>
using namespace std;
// 욕심쟁이 판다
// 다이나믹 프로그래밍을 사용
// 방향에 따른 가짓수가 4가지나, 조건에 따라 이동하기 때문에
// 함수 하나로 축약하여 사용이 가능

int map;
int bamboo[500][500]; //대나무 수
int max_life[500][500]; // 최대로 살 수 있는 날
	// 도달하지 않은 경우 0으로 취급하고,
	// 해당 지역에서는 최소 1일은 생존 가능하므로, 최소값을 1로 취급

int Move(int x, int y); //각 방향으로 이동하는 함수
void DP();

int main() {
	cin >> map; //맵 크기 입력
	for (int k = 0; k < map; k++)
		for (int i = 0; i < map; i++) 
			cin >> bamboo[k][i]; // 대나무 정보를 저장
	DP();
}

int Move(int x, int y) { // 주변에 움직일 수 있는 지역이 있는지 확인하는 함수
	if (max_life[x][y]) // 이미 측정한 적이 있으면 반환
		return max_life[x][y];

	max_life[x][y] = 1; // 일단 한번 온 지역이니 생존가능 최소 1일

	if (y > 0 && bamboo[x][y] < bamboo[x][y - 1]) 
		max_life[x][y] = max(max_life[x][y], Move(x, y - 1) + 1);
	if (y < map - 1 && bamboo[x][y] < bamboo[x][y + 1])
		max_life[x][y] = max(max_life[x][y], Move(x, y + 1) + 1);
	if (x > 0 && bamboo[x][y] < bamboo[x - 1][y])
		max_life[x][y] = max(max_life[x][y], Move(x - 1, y) + 1);
	if (x < map - 1 && bamboo[x][y] < bamboo[x + 1][y])
		max_life[x][y] = max(max_life[x][y], Move(x + 1, y) + 1);
	// 상하좌우 순서로 움직이며
	// 현재 위치보다 대나무 수가 많은 경우에만 이동
	// 기존에 기록되어있던 최대 생존 날과, 진행한 방향에서 생존가능한 최대날 +1 을 비교
	// 대나무의 수 조건으로 인해 자신이 왔던 방향으로 되돌아가는 경우는 없음
	// 또한 x,y의 크기조건을 함께 걸어서
	// 인덱스 범위 (0 ~ y-1) 를 벗어나지 않도록 조절

	return max_life[x][y]; // 측정한 최대 생존 날을 반환
}


void DP() {
	int panda = -1; // 판다의 최대 생존 날 
	for (int k = 0; k < map; k++) 
		for (int i = 0; i < map; i++) 
			panda = max(panda, Move(k, i)); // 모든 지역에서 생존가능한 날의 최댓값을 확인

	cout << panda << endl; // 얻어온 값 출력
}
