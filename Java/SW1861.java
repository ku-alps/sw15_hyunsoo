import java.util.Scanner;

// 정사각형 방
class SW1861 {
	static int[][] DIR = {{-1, 0}, {1, 0}, {0, -1} ,{0, 1}};
	static int size;
	static int[][] map, visit; // 맵, 방문여부
	
	// 주변 탐색 함수
	static int search(int px, int py) {
		int cnt = 1; // 나를 포함하면 한 칸
		for(int[] dir: DIR) {
			// 살펴볼 곳이 범주를 넘어갔으면 무시
			int nx = px + dir[0], ny = py + dir[1];
			if( nx < 0 || nx >= size || ny < 0 || ny >= size) continue;
		
			// 현재 위치보다 값이 1이 더 큰 경우에만 이동 가능
			if( map[nx][ny] == (map[px][py] + 1) ) {
				cnt = ( visit[nx][ny] != 0 ? visit[nx][ny]  : search(nx, ny)) + 1;
			}
		}
		visit[px][py] = cnt;
		return cnt;
	}
	
	// 메인
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for(int test_case = 1; test_case <= T; test_case++) {
			size = sc.nextInt();
			map = new int[size][size];
			visit = new int[size][size];
			
			// 입력
			for(int x=0; x<size; x++) for(int y=0; y<size; y++) map[x][y] = sc.nextInt();
			
			int ax=0, ay=0; // 출발해야 하는 위치 (정답)
			for(int x=0; x<size; x++) {
				for(int y=0; y<size; y++) {
					search(x,y);
					
					if( visit[ax][ay] < visit[x][y] ) {
						// 새로 방문한 곳이 이전보다 더 많이 움직일 수 있으면
						ax = x;
						ay = y; // 변경
					}
					else if ( visit[ax][ay] == visit[x][y] ) {
						if( map[ax][ay] > map[x][y] ) {
							// 최대치가 같으면 작은 놈을 선택
							ax = x;
							ay = y;
						}
					}
				}
			}
			System.out.println("#" + test_case + " " + map[ax][ay] + " " + visit[ax][ay]);
		}
	}
}