import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

// 프로세서 연결하기
class SW1767 {
	// 탐색 방향
	static final int[][] DIR = {{0,-1},{1,0},{0,1},{-1,0}};
	
	static int N, conn, lineSum; // 맵 크기, 연결 수, 전선 길이
	static int[][] field; // 전체 맵
	static List<Integer[]> processor; // 프로세서 위치좌표값
	
	// 모든 경우를 다 살펴봄
	static void brute(int idx, int[][] map, int cnt, int len) {
		// 이번에 연결 시도할 프로세서 인덱스, 전체 맵 정보, 현재까지 연결한 프로세서 수, 길이
		if(idx==processor.size()) { // 끝까지 다봤으면
			if( conn < cnt ) { // 새로 연결한 수가 더 많으면
				conn = cnt;
				lineSum = len;
			}
			else if( conn == cnt ) { // 연결 수가 같으면 길이를 짧은 걸로
				lineSum = Math.min(lineSum, len);
			}
			return;
		}

		// 남은 놈들을 다 합쳐도 값이 부족하면, 돌려도
		// so, 제약조건을 걸어서  cut-off 시킴
		if(conn <= (processor.size()-idx)+cnt) {
			// 남은 놈들을 다 합쳐도, 현재까지 발견한 최다 연결보다 적으면 볼 필요 x
			Integer[] pro = processor.get(idx); // 이번에 연결할 프로세서 정보

			search:
			for(int k=0; k<4; k++) { // 4방향 중 하나로 연결
				int[][] clone = new int[N][];
				for(int i=0; i<N; i++) clone[i]=map[i].clone(); // 복사
	
				int line=0; // 전선 길이 계산용
				int nx=pro[0], ny=pro[1]; // 새 좌표
				while(true) {
					nx+=DIR[k][0];
					ny+=DIR[k][1]; // 이동
	
					if(nx<0||nx>=N||ny<0||ny>=N) break; // 범위 밖이랑 연결됨
					if(clone[nx][ny] != 0) continue search; // 무언가가 이미 존재
					clone[nx][ny] = 2; // 전선을 놓았음
					line++; // 길이 증가
				}
				// 연결한 상황에 맞춰서 다음을 만들어봄
				brute(idx+1, clone, cnt+1, len+line);
			} // 4방향 탐색 종료
			
			brute(idx+1, map, cnt, len); // 프로세스 연결 안한 경우
		}
	}
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		// 테스트 케이스
		for(int test_case = 1; test_case <= T; test_case++) {
			N = Integer.parseInt(br.readLine()); // 맵 크기
			field = new int[N][N];
			processor = new ArrayList<Integer[]>();

			conn = 0; // 시작값은 0;
			lineSum = Integer.MAX_VALUE; // 최소값을 구해야 함
			
			for(int x=0; x<N; x++) { // 맵 전체 입력
				StringTokenizer st = new StringTokenizer(br.readLine());
				for(int y=0; y<N; y++) {
					field[x][y] = Integer.parseInt(st.nextToken());
					if( field[x][y] == 1 ) { // 프로세서 위치 저장
						processor.add(new Integer[] {x,y});
					}
				}
			}
			brute(0,field,0,0); // 탐색 시작
			
			System.out.println("#"+test_case+" "+lineSum); // 출력
		}
	}
}