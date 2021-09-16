import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 사람 네트워크2
class SW1263 {
	static final int MAX = Integer.MAX_VALUE;
	
	static int N; // 사람 수
	static long[][] conn; // 각 경로의 최단거리
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		// 테스트 케이스
		for(int test_case = 1; test_case <= T; test_case++) {
			// 입력
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			conn = new long[N][N];
			
			// 사람 네트워크 정보
			for(int x=0; x<N; x++) {
				for(int y=0; y<N; y++) {	
					conn[x][y]=Integer.parseInt(st.nextToken());
					// 셀프 사이클이 아닌 곳에서 입력이 0이면, 경로 자체가 없음을 의미
					if(x!=y && conn[x][y] == 0) conn[x][y] = MAX;
				}
			}
		
			// 플로이드 워셜
			for(int k=0; k<N; k++) { // 1~k까지의 사람을 거쳐갈 수 있을 때
				// 모든 경로를 갱신
				for(int x=0; x<N; x++) {
					for(int y=0; y<N; y++) {
						// 기존 경로 vs 중간에 k를 거쳐서 가는 경로
						conn[x][y] = Math.min(conn[x][y], conn[x][k]+conn[k][y]);
					}
				}
			}
			
			// 모든 사람들이 각자의 네트워크 합을 구하고, 최소값을 선택
			int cc = MAX;
			for(long[] dist: conn) {
				int sum = 0;
				for(long d: dist) sum += d;
				cc = Math.min(cc, sum);
			}
			
			System.out.println("#"+test_case+" "+cc);
		}
	}
}