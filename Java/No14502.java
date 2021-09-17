import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

// 연구소
class No14502 {
	static final int[][] DIR = {{0,-1},{0,1},{-1,0},{1,0}}; // 탐색 방향
	
	static int[][] map; // 전체 맵 정보
	static List<Integer[]> virus = new ArrayList<>(); // 바이러스 좌표
	
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), M = sc.nextInt(); // 세로 가로

		map = new int[N][M]; // 지도 입력
		for(int x=0; x<N; x++) {
			for(int y=0; y<M; y++) {
				map[x][y]=sc.nextInt();
				if(map[x][y] == 2) virus.add(new Integer[] {x,y});
			}			
		}
		
		int safe = 0; // 안전 구역
		// 벽 3개를 설치할 위치 정하고, 시뮬레이션
		for(int x1=0; x1<N; x1++) {
			for(int y1=0; y1<M; y1++) { // 1번 벽의 위치
				if(map[x1][y1] != 0) continue; // 설치 불가능한 위치
				
				for(int x2=x1; x2<N; x2++) {
					for(int y2=0; y2<M; y2++) { // 2번 벽의 위치
						if(map[x2][y2] != 0) continue; // 설치 불가능한 위치
						if(x1==x2 && y1>=y2) continue; // 이미 해봤던 조합
						
						for(int x3=x2; x3<N; x3++) {
							for(int y3=0; y3<M; y3++) { // 3번 벽의 위치
								if(map[x3][y3] != 0) continue; // 설치 불가능한 위치
								if(x2==x3 && y2>=y3) continue; // 이미 해봤던 조합
								
								int[][] clone = new int[N][]; // 맵 복사
								for(int k=0; k<N; k++) clone[k]=map[k].clone();
								
								// 시뮬레이션
								// 벽 세우고, 직접 시뮬레이션 돌려보기
								clone[x1][y1] = clone[x2][y2] = clone[x3][y3] = 1;
								Queue<Integer[]> q = new LinkedList<>(); // BFS 용
								for(Integer[] v: virus) q.add(v); // 시작점은 바이러스좌표
								while(!q.isEmpty()) { // 전부 돌린다
									Integer[] pos = q.poll();
									int vx=pos[0], vy=pos[1]; // 좌표
									if(clone[vx][vy] < 0) continue; // 이미 방문했던 곳
									clone[vx][vy] = -1; // 방문 처리
									
									for(int dir=0; dir<4; dir++) { // 4방향 조사
										int nx=vx+DIR[dir][0], ny=vy+DIR[dir][1];
										if(nx<0||nx>=N||ny<0||ny>=M) continue; //범위 밖
										if(clone[nx][ny] != 0) continue; // 갈수 있는 공간이 아님
										q.add(new Integer[] {nx,ny}); // 좌표 삽입
									}
								}
								
								int leftover = 0; // 남은 안전 영역 계산
								for(int x=0; x<N; x++) {
									for(int y=0;y<M;y++) {
										leftover += (clone[x][y] == 0 ? 1 : 0);
									}
								}
								safe = Math.max(safe, leftover);
							}
						} // 3번 벽
					}
				} // 2번 벽
			}
		} // 1번 벽
		
		System.out.println(safe);
	}
}