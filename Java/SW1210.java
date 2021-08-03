import java.util.Scanner;

// Ladder1
class SW1210 {
	static final int SIZE = 100; // 지도 크기는 100X100
	static final int[][] dir = {{0, -1}, {0, 1}, {-1, 0}}; 
	// 이동 방향 (위쪽 / 왼쪽 / 오른쪽)

	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		
		for(int t=0; t<10; t++) { // 읽을게 있으면 진행 (테스트케이스)
			int test_case = sc.nextInt();
			int[][] map = new int[SIZE][SIZE];
			int px = SIZE-1, py=0; // 현재 위치
			
			for(int x=0; x<SIZE; x++) {
				for(int y=0; y<SIZE; y++) {
					map[x][y] = sc.nextInt();
				}
			}
			for(int y=0; y<SIZE; y++) {
				if(map[SIZE-1][y] == 2) { // 도착지를 찾는다
					py = y;
					break;
				}
			}

			// 탐색 후 출력
			int ans = search(map, px, py);
			System.out.println("#"+ test_case + " " + ans);
		}
	}
	
	// 길 찾기 (탐색)
	static int search(int[][] map, int px, int py) {
		
		// 꼭대기에 도착할 때 까지 반복
		while(px > 0) {
			for(int k=0; k<dir.length; k++) {
				int[] d= dir[k];
				int nx = px + d[0], ny = py + d[1];
				// 범위 확인
				if( ny < 0 || ny >= SIZE ) continue;

				if( map[nx][ny] == 1 ) { // 길이 있으면 이동
					if( k != (dir.length - 1) ) { // 좌, 우 사다리면 끝까지 이동					
						while( map[nx+d[0]][ny+d[1]] == 1) {
							nx += d[0];
							ny += d[1];
							if( ny <= 0 || ny >= SIZE-1 ) break;
						}
						nx -= 1; // 좌우 막대기 끝까지 도달했으면 위로 한칸
					}
					px = nx;
					py = ny;
					break;
				}
			}
		}
		return py;
	}
}