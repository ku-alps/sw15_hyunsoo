import java.util.Scanner;

// 서로소 집합
class SW3289 {
	static int N, M; // 노드 수, 연산 수
	static int[] group; // 소속 그룹

	// 초기 환경세팅
	static void setting() {
		group = new int[N+1]; // 각 요소의 소속 그룹을 저장할 공간
		for(int k=1; k<=N; k++) group[k] = k; // 초기 세팅
	}
	
	// 대표자 찾기
	static int find(int a) { // 대상이 속한 그룹의 대표자 찾기
		if(group[a] == a) return a;
		return group[a] = find(group[a]);
	}
	
	// 그룹 합치기
	static boolean union(int a, int b) {
		// a,b 가 속한 그룹의 대표자 찾기
		int aRoot = find(a), bRoot = find(b);
		
		if( aRoot == bRoot ) return false; // 같은 그룹이면 합치기 실패
		group[aRoot] = bRoot; // 한쪽을 대표자로 설정함
		return true; // 합치기 성공
	}

	// 동일 그룹인지 확인
	static boolean compare(int a, int b) {
		int aRoot = find(a), bRoot = find(b);
		return aRoot == bRoot; // 대표자가 같으면 한 그룹
	}
	
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for(int test_case = 1; test_case <= T; test_case++) {
			// 입력
			N = sc.nextInt();
			M = sc.nextInt();
			setting(); // 초기 환경 세팅
			
			// 출력 담당할 문자열 객체
			StringBuilder sb = new StringBuilder("#"+test_case+" ");
			
			for(int k=0; k<M; k++) {
				// 합치기 or 그룹확인 후 출력
				if(sc.nextInt() == 0) union(sc.nextInt(), sc.nextInt());
				else sb.append(compare(sc.nextInt(), sc.nextInt()) ? 1 : 0);					
			}
			
			System.out.println(sb.toString());
		}
	}
}