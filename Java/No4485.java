import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.Scanner;

// 녹색 옷 입은 애가 젤다지?
class No4485 {
	static final int[][] DIR = {{0,-1},{0,1},{-1,0},{1,0}};
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


		for(int test_case = 1; true; test_case++) {
			int N = Integer.parseInt(br.readLine());
			if( N == 0 ) break; // 종료 조건
			
			int[][] map = new int[N][N];
			boolean[][] visit = new boolean[N][N]; // 방문 여부
			int[][] dp = new int[N][N];

			// 지도 전체 입력
			for(int x=0; x<N; x++) {
				String[] input = br.readLine().split(" ");
				for(int y=0; y<N; y++) {
					map[x][y] = Integer.parseInt(input[y]);
				}
			}
			
			// 누적 값의 오름차순으로 정렬
			PriorityQueue<Integer[]> pq = new PriorityQueue<Integer[]>(
					(a, b) -> a[2]-b[2]
				);
			pq.add(new Integer[] {0,0,0}); // 시작점 + 누적합
			while(!pq.isEmpty()) { // 모든값을 살펴봄
				Integer[] pos = pq.poll(); // 값 꺼내오기
				int x = pos[0], y = pos[1], lost = pos[2];
				
				if(visit[x][y]) continue; // 이미 방문했던 곳은 무시
				visit[x][y] = true; // 방문 표기

				lost += map[x][y]; // 현재 위치에 있는 도둑루피값을 합침
				dp[x][y] = lost; // 도달할 때 까지 만난 최소 도둑루피
				
				for(int k=0; k<4; k++) { // 4방향 탐색
					int nx=x+DIR[k][0], ny=y+DIR[k][1]; // 다음 위치
					if(nx<0||nx>=N||ny<0||ny>=N) continue; // 범위를 벗어남
					if(visit[nx][ny]) continue; // 이미 방문한 경우
					
					pq.add(new Integer[] {nx,ny,lost});
				}
			}
			
			
			System.out.println("Problem "+test_case+": "+dp[N-1][N-1]);
		}
	}
}