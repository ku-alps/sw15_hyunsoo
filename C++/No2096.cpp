#include<iostream>
#include<algorithm>
using namespace std;
// 내려 가기
// 재귀 구조를 통한 DP 문제
// 다만, 메모리 제약이 4MB 로 상당히 빡센 편
// so, 재귀 DP 특성을 통해 불필요한 메모리 공간을 없애는 방식이 필요

int H, ladder_max[2][3], ladder_min[2][3]; 
// 기존 DP 방식에서 할당되는 배열의 크기는 [100000][3]
// but, 실제로 매번 접근하는 배열은 자신, 앞 배열 뿐 ( 총 2개 )

int main() {
	cin >> H; // 사다리 높이

	for (int k = 1; k <= H; k++) { // 사다리는 1부터 시작 (인덱스 '0'은 초기값 0)
		int a, b, c;
		cin >> a >> b >> c; // 각 방의 값 입력

		int now = k % 2, before = (k - 1) % 2; // 현재 사용할 방, 이전에 사용한 방

		// 최대 값 계산
		ladder_max[now][0] = max(ladder_max[before][0], ladder_max[before][1]) + a; // 왼쪽, 가운데 중 큰 값을 선택
		ladder_max[now][1] = max(max(ladder_max[before][0], ladder_max[before][1]), ladder_max[before][2]) + b; // 세 방향 중 큰 값
		ladder_max[now][2] = max(ladder_max[before][1], ladder_max[before][2]) + c; // 왼쪽, 가운데 중 큰 값을 선택

		// 최소 값 계산
		ladder_min[now][0] = min(ladder_min[before][0], ladder_min[before][1]) + a; // 왼쪽, 가운데 중 큰 값을 선택
		ladder_min[now][1] = min(min(ladder_min[before][0], ladder_min[before][1]), ladder_min[before][2]) + b; // 세 방향 중 큰 값
		ladder_min[now][2] = min(ladder_min[before][1], ladder_min[before][2]) + c; // 왼쪽, 가운데 중 큰 값을 선택

		// 짝수, 홀수를 번갈아가며 사용
	}
	cout << max(max(ladder_max[H % 2][0], ladder_max[H % 2][1]), ladder_max[H % 2][2]) <<
		" " << min(min(ladder_min[H % 2][0], ladder_min[H % 2][1]), ladder_min[H % 2][2]) << endl; // 출력
}