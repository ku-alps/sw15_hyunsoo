import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.Scanner;

// 보급로
class SW1249 {
	// 이동 방향
	static final int[][] DIR = {{0,-1},{0,1},{-1,0},{1,0}};
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine()); // 테스트 케이스

		for(int test_case = 1; test_case <= T; test_case++) {
			int N = Integer.parseInt(br.readLine()); // 맵 크기
			int[][] rail = new int[N][N]; // 복구할 지도정보
			
			for(int x=0; x<N; x++) { // 지도값 입력
				String[] row = br.readLine().split("");
				for(int y=0; y<N; y++) rail[x][y]=Integer.parseInt(row[y]);
			}
			
			// 현재까지 덮은 흙의 크기를 기준으로 정렬해서 탐색
			PriorityQueue<Integer[]> pq=new PriorityQueue<>( (a, b)->a[2]-b[2] );
			pq.add(new Integer[] {0,0,0}); // 출발지점+걸린시간 삽입
			while(!pq.isEmpty()) { // 우선순위 탐색
				Integer[] pos = pq.poll();
				int x=pos[0], y=pos[1], time=pos[2]; // 좌표+걸린 시간
				if(rail[x][y] < 0) continue; // 이미 방문한 위치는 무시
				time += rail[x][y]; // 해당 위치까지 전부 덮고 도착하는데 걸린 시간
				rail[x][y] = -1; // 방문 표기로 수정
				
				if(x == N-1 && y == N-1) { // 도착 지점이라면
					System.out.println("#"+test_case+" "+time); // 결과 출력
					break; // 종료
				}
				
				for(int k=0; k<4; k++) { // 4방향에 대해서 다시 탐색
					int nx=x+DIR[k][0], ny=y+DIR[k][1]; // 이동할 좌표
					if(nx<0||nx>=N||ny<0||ny>=N) continue; // 범주 확인
					if(rail[nx][ny] < 0) continue; // 이미 갔던 곳도 무시
					pq.add(new Integer[] {nx,ny,time});
				}
			}			
		}
	}
}