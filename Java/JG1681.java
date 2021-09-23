import java.util.Scanner;

// 해밀턴 순환회로
class JG1681 {
	// 무한대로 사용할 최대값
	// 입력 비용의 최대값은 99 이므로, 연산 시 오버플로우를 고려
	static final int INF = Integer.MAX_VALUE-100;
	
	static int N;
	static int[][] distance;
	static int[][] dp;
	
	// 순열
	static int permutation(int idx, int bit) {
		// 현재 노드, 방문정보 비트, 현재까지 거리 총합
		if(dp[idx][bit] != 0) return dp[idx][bit]; // 이전 경험이 있으면 이를 사용
		if((bit+1)==(1<<N)) { // 모든 곳을 방문했으면 되돌아가는 거리를 연산 후 반환
			return dp[idx][bit] = distance[idx][0];
		}
		
		int res = INF; // 초기값은 최대거리
			for(int k=1; k<N; k++) { // 시작점을 제외하고 시도
				if((bit&(1<<k)) != 0) continue; // 방문했던 곳은 무시
				// 최단거리 구하기
				res = Math.min(res, permutation(k, bit|(1<<k))+distance[idx][k]);
			}
		return dp[idx][bit] = res;
	}
	
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		// 입력
		N = sc.nextInt(); // 장소 수
		distance = new int[N][N]; // 이동 가능하는데 필요한 거리값
		dp = new int[N][(1<<N)];
		
		for(int f=0; f<N; f++) { // 연결 거리
			for(int t=0; t<N; t++) {
				distance[f][t] = sc.nextInt();
				if( f!=t && distance[f][t] == 0 ) { // 연결이 안되어 있으면
					distance[f][t] = INF; // 무한대로 설정
				}
			}
		}
		
		// 플로이드 워셜로 각 지점별 최단거리 찾기
		// N 최대값이 12이므로, N^3 으로 접근 가능
		for(int m=0; m<N; m++) { // 이번에 고려할 노드번호
			for(int f=0; f<N; f++) { // 출발점
				for(int t=0; t<N; t++) { // 도착점
					// 기존 길과, m을 거쳐서 가는 최단거리 중 작은 값을 선택
					distance[f][t] = Math.min(distance[f][t], distance[f][m]+distance[m][t]);
				}
			}
		} // 플로이드 워셜
		
		// 순열로 배달하는 순서를 결정
		System.out.println(permutation(0, 1)); // 0번은 방문을 한 채로 시작
	}
}