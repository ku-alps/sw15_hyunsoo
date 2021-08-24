import java.util.Scanner;

// 창용 마을 무리의 개수
class SW7465 {
	static int[] group; // 그룹 정보

	// 탐색
	static int find(int a) {
		if(a == group[a]) return a;
		return group[a] = find(group[a]);
	}
	
	// 합치기
	static boolean union(int a, int b) {
		int aRoot = find(a), bRoot = find(b);
		if( aRoot == bRoot ) return false; // 이미 연결됨
		group[aRoot] = bRoot; // 합치기
		return true; // 연결 성공
	}
	
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for(int test_case = 1; test_case <= T; test_case++) {
			int N = sc.nextInt(), M = sc.nextInt(); // 노드 수, 관계 수

			group = new int[N+1]; // 그룹 정보 세팅
			for(int k=1; k<=N; k++) group[k] = k; 
			
			int cnt = N; // 총 그룹 수
			for(int k=0; k<M; k++) { // 모든 관계에 대해서 처리
				// 합칠 수 있으면 그룹 수가 감소
				if(union(sc.nextInt(), sc.nextInt())) cnt--;
			}
			System.out.println("#"+test_case+" "+cnt);
		}
	}
}