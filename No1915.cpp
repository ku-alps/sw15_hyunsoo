#include<cstdio>
#include<algorithm>
using namespace std;
// 가장 큰 정사각형
// 정사각형이 만들어지기 위해선, 가로,세로,대각선이 모두 값으로 채워져 있어야 함
// so, 세 조건을 모두 만족해야하며 이는 최솟값 연산으로 판단이 가능

#define MAX 1000

int N, M;
pair<int, int> arr[MAX + 1][MAX + 1]; // 해당 노드의 왼쪽, 위로 연속된 1의 개수

int main() {
	scanf("%d %d", &N, &M);
	int result = 0;
	char d;
	for (int k = 1; k <= N; k++) {
		getchar(); // '\n' 을 버퍼에서 빼내어 예외처리 하는 용도
		// 값을 가진 map 을 하나씩 꺼내 사용해야 하므로, int 형이 아닌 char 형으로 받아야 하며
		// 이전 입력으로 남은 버퍼 내용에 대해 예외처리가 필요함

		for (int m = 1; m <= M; m++) {
			scanf("%c", &d);
			if ( d == '1') { // 입력 문자가 1인 경우
				int top = min(arr[k - 1][m].first, arr[k][m - 1].first); 
				top = min(top, arr[k - 1][m - 1].first); 
				int left = min(arr[k - 1][m].second, arr[k][m - 1].second);
				left = min(left, arr[k - 1][m - 1].second);
				// 자신의 왼쪽, 위, 대각선 방향에서 연속된 가로, 연속된 세로의 최소값을 구해옴 
				// cause, 정사각형의 크기가 확장되기 위해선 총 3 방향의 정보가 모두 존재해야 하기 때문

				arr[k][m] = pair<int, int>(top + 1, left + 1); // 배열에 저장
				result = max(result, min(arr[k][m].first, arr[k][m].second));
				// 가로 세로 값 중, 작은 값이 실제로 해당 구역에서 만들 수 있는 정사각형의 크기
				// 가장 큰 값을 매번 선택
			}
		}
	}
	printf("%d\n", result * result); // 넓이 출력
}