import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

// 토마토
class No7576 {
	// 탐색용 4방향
	static final int[][] DIR = {{0,-1},{0,1},{-1,0},{1,0}};
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] MN = br.readLine().split(" ");
		int M = Integer.parseInt(MN[0]); // 가로
		int N = Integer.parseInt(MN[1]); // 세로

		// 입력
		int[][] farm = new int[N][M]; // 농장 정보	
		boolean[][] visit = new boolean[N][M]; // 방문 정보
		Queue<Integer[]> q = new LinkedList<>(); // BFS 탐색용 큐
		for(int x=0; x<N; x++) { // 맵 정보 읽기
			String[] row = br.readLine().split(" "); // 한 줄 읽기
			for(int y=0; y<M; y++) { // 숫자로 변환
				farm[x][y] = Integer.parseInt(row[y]);
				if(farm[x][y] == 1) { // 토마토가 있는 위치
					q.offer(new Integer[] {x,y,0}); // 좌표+걸린 시간
					farm[x][y] = 0;
					visit[x][y] = true; // 방문 표기
				}
			}
		}
		
		// BFS 탐색
		while(!q.isEmpty()) {
			Integer[] tomato = q.poll(); // 토마토 꺼내오기
			int x=tomato[0], y=tomato[1], time=tomato[2];
			
			// 4방향 탐색
			for(int k=0; k<4; k++) {
				int nx=x+DIR[k][0], ny=y+DIR[k][1]; // 새 위치

				if(nx<0||nx>=N||ny<0||ny>=M) continue;// 범위 밖

				if(visit[nx][ny]) continue; // 이미 봤던 곳도 무시
				if(farm[nx][ny] != 0) continue; // 익지않은 토마토가 아니면 무시

				visit[nx][ny] = true; // 방문 표기
				farm[nx][ny] = time+1; // 시간값을 1 늘려서 익은 시점을 기록
				q.add(new Integer[] {nx,ny,time+1}); // 다음에 탐색할 대상
			}
		}
		
		int last_time = 0; // 등장한 시간의 최대값
		search:
		for(int x=0; x<N; x++) {
			for(int y=0; y<M; y++) {
				if( !visit[x][y] && farm[x][y] == 0 ) { 
					// 방문을 하지 않은 익지 않은 토마토가 있으면 실패
					last_time = -1;
					break search;
				}
				// 더 큰 시간값을 선택
				last_time = Math.max(last_time, farm[x][y]);
			}
		}
		System.out.println(last_time); // 출력
	}
}