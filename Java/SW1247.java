import java.util.Scanner;

// 최적 경로
class SW1247 {
	static int N; // 손님 수
	static int[] HOME = new int[2]; // 집좌표
	static int[][] CUSTOMER; // 출발좌표(회사) + 손님좌표

	// 길탐색 함수
	static int findRoad(int idx, int bit) {
		// 현재 방문중인 손님, 방문 기록
		if(bit >= (1<<N+1)-1) { // 모든 집을 다 들렀다면
			int between = 0; // 집까지의 경로계산값을 반환
			for(int k=0; k<2; k++) between += Math.abs(CUSTOMER[idx][k]-HOME[k]);
			return between;
		}

		int dis = Integer.MAX_VALUE; // 경로값
		for(int k=1; k<=N; k++) { // 모든 집을 다시 훑으면서
			if((bit & 1<<k) != 0) continue; // 방문했던 곳이면 무시

			int between = 0; // 두 지점의 거리 계산
			for(int i=0; i<2; i++) between += Math.abs(CUSTOMER[idx][i]-CUSTOMER[k][i]);
			// 가능한 경로 중 최소값을 선택
			dis = Math.min(dis, findRoad(k, bit|(1<<k))+between);
		}
		return dis;
	}
	
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int test_case = 1; test_case <= T; test_case++) {
			// 입력
			N = sc.nextInt(); // 손님 수
			CUSTOMER = new int[N+1][2]; // 회사좌표를 출발지점으로 삼음 
			for(int k=0; k<2; k++) CUSTOMER[0][k] = sc.nextInt(); // 회사
			for(int k=0; k<2; k++) HOME[k] = sc.nextInt(); // 집
			for(int k=1; k<=N; k++) // 손님 모두에 대해
				for(int i=0; i<2; i++) CUSTOMER[k][i] = sc.nextInt(); // 각각의 좌표
			
			// 시작지점은 회사, 해당 지점은 방문을 한채 시작
			System.out.println("#"+test_case+" "+findRoad(0, 1));
		}
	}
}