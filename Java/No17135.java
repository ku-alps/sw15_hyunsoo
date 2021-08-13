import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

// 캐슬 디펜스
class No17135 {
	static final int ARCHER = 3;
	static final int[][] MOVE = {{0,-1},{-1,0},{0,1}}; // 왼쪽, 위쪽, 오른쪽 순
	static int N, M, D; // 행, 열, 거리제약
	static int[][] origin; // 게임판
	
	// 실제 화살쏘기 시물레이션
	public static int simulation(int bit) {
		// 필드 상태가 계속 변하기 떄문에, 복제값을 사용
		int[][] clone = new int[N][];
		for(int x=0; x<N; x++) clone[x] = origin[x].clone();

		int[] archers = new int[ARCHER]; // 각 궁수의 열 위치
		int idx = 0; // 궁수 위치를 표기
		for(int k=0; k<M; k++) if((bit & (1<<k)) != 0) archers[idx++] = k;
		
		int kill = 0; // 죽인 몬스터 수
		for(int k=1; k<=N; k++) { // 모든 몬스터가 밑으로 내려오는 시점까지 진행
			int[][] shoot = {{-1, -1},{-1, -1},{-1, -1}};

			for(int i=0; i<ARCHER; i++) { // 모든 궁수에 대해서
				Queue<Integer[]> q = new LinkedList<>(); // 궁수의 사거리 안을 확인
				q.add(new Integer[] {N-k , archers[i], 1}); // 초기 세팅 (좌표, 닿는 거리)

				// queue 기반의  bfs 로 쏠 상대를 결정
				while(!q.isEmpty()) {
					Integer[] col = q.poll();
					if(col[2] > D) continue; // 길이를 넘었으면 끝
					if(clone[col[0]][col[1]] == 1) { // 몬스터가 있으면 선택
						for(int j=0; j<2; j++) shoot[i][j] = col[j];
						break;
					}
					// 그 외엔 탐색범위를 확장함
					for(int j=0; j<MOVE.length; j++) {
						// 왼쪽->위쪽->오른쪽 순서로 탐색하기 때문에 [ 거리가 짧고, 왼쪽 우선 ] 의 조건을 항상 만족
						int nx = col[0] + MOVE[j][0];
						int ny = col[1] + MOVE[j][1];
						// 범위 확인
						if( nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
						q.add(new Integer[] {nx,ny,col[2]+1});
					}
				}
			}
			for(int i=0; i<ARCHER; i++) { // 실제로 몬스터 제거
				int x = shoot[i][0], y = shoot[i][1];
				if( x == -1 || y== -1 ) continue; // 죽일 애가 없어도 넘김
				if( clone[x][y] != 1 ) continue; // 이미 죽인놈인지 확인
				kill += 1;
				clone[x][y] = 0; // 죽여서 없애버림
			}
		}
		return kill;
	}
	
	// 배치 조합
	public static int combination(int cnt, int idx, int bit) {
		// 선택한 갯수, 시작 인덱스, 선택 조합정보
		int res = 0; // 몬스터를 잡는 가장 적은 수는 0 
		if( cnt == ARCHER ) { // 모든 궁수를 배치했다면
			res = simulation(bit); // 배치정보 기반으로 시뮬레이션 돌리기
		}
		else { // 선택 조합이 남았으면
			for(int k=idx; k<M; k++) { // 열에 궁수를 하나씩 넣어봄
				res = Math.max(res, combination(cnt+1, k+1, bit|(1<<k)));
			}
		}
		return res;
	}
	
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		N= sc.nextInt();
		M=sc.nextInt();
		D=sc.nextInt();
		
		origin = new int[N][M]; // 입력
		for(int x=0; x<N; x++) for(int y=0; y<M; y++) origin[x][y] = sc.nextInt();
		
		System.out.println(combination(0, 0, 0));
	}
}