import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// 감시
class No15683 {
	static int R, C, EMPTY; // 행, 열, 빈 공간의 수
	static int[][] FIELD; // 전체 상태
	static List<Integer[]> CCTV = new ArrayList<>(); // CCTV 좌표
	
	static final int[][] DIR = {{-1,0},{0,1},{1,0},{0,-1}}; // 방향 (위쪽부터 시계)
	static final int[][][] MODE = { // CCTV 상태에 따라서 (종류, 회전횟수, 바라볼 방향)
			{}, // 0번은 빈 칸
			{{0},{1},{2},{3}}, // 1번 CCTV
			{{0,2},{1,3}}, // 2번 CCTV
			{{0,1},{1,2},{2,3},{0,3}}, // 3번 CCTV
			{{0,1,2},{1,2,3},{0,2,3},{0,1,3}}, // 4번 CCTV
			{{0,1,2,3}} // 5번 CCTV
	};
	
	// CCTV 로 감시
	static int monitor(int[][] map, int idx) {
		int cnt = 0; // 해당  CCTV 가 맵 전체에서 새로 감시하는 타일의 최대치

		if( idx < CCTV.size() ) { // 봐야 할 CCTV가 남아있으면
			Integer[] pos = CCTV.get(idx); // 해당 CCTV의 좌표 확인
			int type = map[pos[0]][pos[1]]; // CCTV 의 종류
			
			for(int k=0; k<MODE[type].length; k++) { // 회전 상태에 따라서
				int sum = 0; // 이번 방식에서 확인 가능한 타일의 총 합
				
				// 맵을 복제하여 상태 변경시키며 계산
				int[][] clone = new int[R][];
				for(int x=0; x<R; x++) clone[x] = map[x].clone();
				
				// 해당 모드의 CCTV 가 바라보는 방향을 전부 계산
				for(int i=0; i<MODE[type][k].length; i++) {
					int dir = MODE[type][k][i];
					int nx = pos[0], ny = pos[1];
					
					do {
						nx += DIR[dir][0];
						ny += DIR[dir][1]; // 이번에 확인할 좌표
						// 범위 확인
						if( nx < 0 || nx >= R || ny < 0 || ny >= C ) break;
						// 나아갈 수 있는지 확인 ( 벽 외에, CCTV 는 넘어서까지 확인 가능 )
						if(clone[nx][ny] == 6) break;
						if(clone[nx][ny] == 0) { // 공간이었으면
							sum += 1; // 볼 수 있는 지역 확장
							clone[nx][ny] = -1; // 해당 타일을 확인했음을 표기
						}
					} while(true);
				}
				
				// 이번 회전모드를 기반으로 남은 CCTV 들이 지울 수 있는 타일을 모두 확인
				sum += monitor(clone, idx+1);
				cnt = Math.max(cnt, sum); // 최대값 갱신
			}
		}
		return cnt;
	}
	
	// 메인함수
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		// 입력
		R = sc.nextInt();
		C = sc.nextInt();
		FIELD = new int[R][C];
		for(int x=0; x<R; x++) {
			for(int y=0; y<C; y++) {
				FIELD[x][y]=sc.nextInt();
				if(FIELD[x][y] == 0) EMPTY++; // 빈 칸 수 증가
				else if(FIELD[x][y] != 6) CCTV.add(new Integer[] {x,y}); // 벽이 아니면 CCTV
			}
		}
		
		// 모든 CCTV 가 볼 수 있는 타일 수를 계산하여 빈 공간이랑 계산 후 출력
		System.out.println(EMPTY-monitor(FIELD, 0));
	}
}