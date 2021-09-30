import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

// 탈주범 검거
class SW1953 {
	// 이동 방향
	static final int[][] DIR= {{-1,0},{0,-1},{1,0},{0,1}}; // 상좌하우
	static final boolean[][] TUNNEL = {
			// 각 터널마다 해당 방향으로 연결되어있는가?
			// 상,좌,하,우 순서
			{false, false, false, false}, // 0인 경우, 빈 값 (전부 막힘) 
			{true, true, true, true}, // 십자
			{true, false, true, false}, // 세로 일자
			{false, true, false, true}, // 가로 일자
			{true, false, false, true}, // 상->우
			{false, false, true, true}, // 하->우
			{false, true, true, false}, // 하->좌
			{true, true, false, false}, // 상->좌
		};
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		for(int test_case = 1; test_case <= T; test_case++) {
			String[] NMRCL = br.readLine().split(" "); // 초기 세팅정보
			int N=Integer.parseInt(NMRCL[0]);
			int M=Integer.parseInt(NMRCL[1]); // 가로세로
			int R=Integer.parseInt(NMRCL[2]);
			int C=Integer.parseInt(NMRCL[3]); // 맨홀 좌표
			int L=Integer.parseInt(NMRCL[4]); // 경과 시간

			int[][] underground = new int[N][M]; // 지하 파이프 정보
			for(int x=0; x<N; x++) { // 지하 정보 입력
				String[] row = br.readLine().split(" ");
				for(int y=0; y<M; y++) underground[x][y]=Integer.parseInt(row[y]);
			}
			
			Queue<Integer[]> q = new LinkedList<>(); // BFS 용 큐
			q.add(new Integer[] {R,C,0}); // 맨홀위치 + 초기시간값
			boolean[][] visit = new boolean[N][M]; // 탐색용 방문 정보
			
			int cnt = 0; // 정답값
			while(!q.isEmpty()) { // BFS 탐색
				Integer[] pipe = q.poll(); // 이번에 볼 파이프 정보
				int x=pipe[0], y=pipe[1], time=pipe[2]+1;
				if(time > L) break; // 시간이 초과한 경우, 더이상 이동 불가능
				if(visit[x][y]) continue; // 이미 방문한 공간도 추가방문 안함
				visit[x][y] = true;
				cnt++; // 도달할 수 있는 공간 수 +1
				
				int type=underground[x][y]; // 현재 위치의 파이프 종류
				for(int k=0; k<4; k++) { // 4가지 방향으로 이동
					// 현재 파이프에서, 해당 방향으로 구멍이 없으면 무시
					if(!TUNNEL[type][k]) continue;
					
					int nx=x+DIR[k][0], ny=y+DIR[k][1]; // 이동을 원하는 좌표
					if(nx<0||nx>=N||ny<0||ny>=M) continue; // 범주 확인
					if(visit[nx][ny]) continue; // 이미 방문했던 곳 무시
					
					int nType=underground[nx][ny]; // 마찬가지로 새 위치의 파이프 종류
					// 이동을 원하는 위치에선 반대방향으로 구멍이 있어야 이동 가능
					if(!TUNNEL[nType][(k+2)%4]) continue;
					
					q.add(new Integer[] {nx, ny, time}); // BFS 탐색 계속
				}
			}
			// 출력
			System.out.println("#"+test_case+" "+cnt);
		}
	}
}