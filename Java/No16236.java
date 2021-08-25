import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;

// 아기 상어
class No16236 {	
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		final int[][] DIR = {{-1,0},{0,-1},{0,1},{1,0}}; // 탐색용 배열
		
		int N = sc.nextInt(); // 바다의 크기

		int[][] SEA = new int[N][N]; // 바다 정보
		int[] babyShark = new int[4]; // 아기상어의 좌표정보 + 크기정보 + 먹은 물고기 수
		for(int x=0; x<N; x++) {
			for(int y=0; y<N; y++) { // 모든 좌표에 대해 정보읽기
				SEA[x][y] = sc.nextInt();
				if( SEA[x][y] == 9 ) { // 아기상어인 경우
					babyShark[0] = x;
					babyShark[1] = y; // 아기상어의 위치값
					babyShark[2] = 2; // 초기 아기상어의 크기
					SEA[x][y] = 0; // 예외처리 편의성을 위해 빈공간으로 둠
				}
			}
		}
		
		int time = 0; // 걸린 총 시간
		PriorityQueue<Integer[]> q; // 조건부 BFS 에 사용할 우선순위 큐
		boolean[][] v; // 좌표 도착 여부
		boolean canEat = true; // 더 먹을 수 있는가?
		outer: while( canEat ) {
			q= new PriorityQueue<>((a, b) -> { // 비교연산자로 커스텀
				if(a[2] != b[2]) return a[2]-b[2]; // 기본은 걸리는 시간 기준
				if(a[0] != b[0]) return a[0]-b[0]; // 다음 기준은 상하기준
				return a[1]-b[1]; // 그 외엔 좌우기준
			});
			v = new boolean[N][N];
			// 아기 상어의 위치부터 BFS 시작
			q.add(new Integer[] {babyShark[0], babyShark[1], 0});
			v[babyShark[0]][babyShark[1]] = true; // 방문표기
			while(!q.isEmpty()) { // 주변을 탐색
				Integer[] info = q.poll();
				int x = info[0], y = info[1], t = info[2];
				if( SEA[x][y] != 0 ) { // 빈칸이 아니면 확인
					if( SEA[x][y] > babyShark[2] ) continue; // 물고기가 상어보다 크면 못먹음
					if( SEA[x][y] < babyShark[2] ) { // 물고기가 더 작으면 먹고 성장
						
						time += t; // 이동하는데 걸린 시간 추가
						SEA[x][y] = 0; // 먹어버림
						babyShark[0] = x;
						babyShark[1] = y; // 상어 이동
												
						babyShark[3]++; // 현재 몸집으로 먹은 물고기 수 증가
						if( babyShark[2] == babyShark[3] ) { // 몸집이 커질 수 있는지 확인
							babyShark[2]++; // 몸집 키우기
							babyShark[3] = 0; // 먹은 수 초기화
						}
						continue outer; // 먹이를 먹었으니 반복작업
					}
				}
				// 크기가 같으면 먹진 못하고 통과만 함 (탐색 재개)
				for(int[] dir: DIR) {
					int nx = x+dir[0], ny = y+dir[1]; // 새로 이동할 좌표
					// 활동범위 확인
					if(nx < 0 || nx >= N || ny < 0 || ny >= N ) continue;
					if(v[nx][ny]) continue; // 방문했던 곳도 무시
					v[nx][ny] = true;
					q.add(new Integer[] {nx, ny, t+1});
				}
			}
			canEat = false; // 큐를 다 돌도록 재시작을 안하면 이건 더 못먹음
		}
		System.out.println(time);
	}
}