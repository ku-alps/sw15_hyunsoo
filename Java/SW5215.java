import java.util.Scanner;

// 햄버거 다이어트
class SW5215 {
	static int N, L; // 재료수, 칼로리제한
	static int[] S, K; // 재료의 점수, 칼로리

	// 조합 함수
	static int combination(int idx, int score, int kcal) {
		// 현재 탐색 위치, 현재까지의 점수, 조합의 칼로리
		if( kcal > L ) return 0; // 칼로리 제한을 넘기면 못먹음		
		if( idx >= N ) return score; // 더 넣을 수 있는 재료가 없으면 그대로 끝
		
		// 해당 재료를 포함하는 경우 vs 포함하지 않는 경우 중 큰 점수값을 반환
		return Math.max(
				combination(idx+1, score + S[idx], kcal + K[idx]),
				combination(idx+1, score, kcal));		
	}
	
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		// 입력 가능한 재료의 수가 최대 20가지이므로, 완전탐색으로도 충분히 해결 가능
		for(int test_case = 1; test_case <= T; test_case++) {
			// 재료 수, 제한 칼로리 입력
			N = sc.nextInt();
			L = sc.nextInt();
			S = new int[N];
			K = new int[N]; // 각 재료정보를 담을 공간
			for(int k=0; k<N; k++) {
				S[k] = sc.nextInt();
				K[k] = sc.nextInt();
			}
			System.out.println("#"+test_case+" "+combination(0, 0, 0));
		}
	}
}