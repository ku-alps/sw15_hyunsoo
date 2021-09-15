import java.util.PriorityQueue;
import java.util.Scanner;

// 말이 되고픈 원숭이
class No1600 {
	static final int[][] DIR = {{-1,0},{1,0},{0,-1},{0,1}}; // 기본 이동
	static final int[][] JUMP = {
			{-2,1},{-1,2},{1,2},{2,1},
			{2,-1},{1,-2},{-1,-2},{-2,-1}
		}; // 말 점프
	
	static int[][] map; // 맵 정보
	static int[][][] visit; // 방문 정보
	
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt(); // 말처럼 뛸 수 있는 횟수
		int W = sc.nextInt(), H = sc.nextInt(); // 가로 세로
		map = new int[H+1][W+1]; 
		visit = new int[H+1][W+1][31]; // 좌표 + 남은 점프횟수
		
		for(int x=1; x<=H; x++) { // 맵 입력
			for(int y=1; y<=W; y++) {
				map[x][y] = sc.nextInt();
			}
		}
		
		// 횟수 기반으로 오름차순 정렬
		PriorityQueue<Integer[]> pq = new PriorityQueue<Integer[]>(
				(Integer[] a, Integer[] b) -> a[2]-b[2]
			);
		pq.add(new Integer[] {1,1,0,K}); // 시작 좌표, 이동횟수, 점프가능 횟수
		
		int cnt = -1; // 끝까지 이동하는데 필요한 이동횟수
		while(!pq.isEmpty()) { // 큐 탐색
			Integer[] pos = pq.poll();
			int x = pos[0], y = pos[1], leftover = pos[3];
			
			if(x==H && y==W) {
				cnt=pos[2]; // 이동횟수 기록
				break; // 종료
			}

			if(visit[x][y][leftover] != 0) continue; // 이미 방문했거나, 장애물이면 포기
			visit[x][y][leftover] = -1; // 방문 표기
			
			// 일반 이동
			for(int k=0; k<4; k++) {
				int nx = x + DIR[k][0];
				int ny = y + DIR[k][1]; // 다음 이동 위치

				if(nx < 1 || nx > H || ny < 1 || ny > W) continue; // 범주확인
				if(map[nx][ny] != 0) continue; // 빈 공간 아니면 장애물임
				
				// 새로운 좌표, 이동횟수+1, 특수점프는 사용안함
				pq.add(new Integer[] {nx,ny,pos[2]+1,leftover});
			}
			// 특수 점프
			if(leftover > 0) { // 기회가 남아있으면 사용
				for(int k=0; k<8; k++) {
					int nx = x + JUMP[k][0];
					int ny = y + JUMP[k][1]; // 다음 이동 위치
	
					if(nx < 1 || nx > H || ny < 1 || ny > W) continue; // 범주확인
					if(map[nx][ny] != 0) continue; // 빈 공간 아니면 장애물임
					
					// 새로운 좌표, 이동횟수+1, 특수점프 1회 사용
					pq.add(new Integer[] {nx,ny,pos[2]+1,leftover-1});
				}
			}
		}
		System.out.println(cnt); // 출력
	}
}