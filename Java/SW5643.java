import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

// 키 순서
class SW5643 {
	
	static boolean[] visit; // 방문 여부
	static int[] light, heavy; // 가벼운놈, 무거운놈
	static List<Integer>[] conn, rConn; // 가벼움->무거움, 무거움->가벼움
	
	// 가벼움->무거움 탐색
	public static void dfs (int node) {
		for(Integer next: conn[node]) { 
			// 현재 노드보다 크다고 확정된 놈들을 하나씩 살펴봄
			if( visit[next] ) continue;
			visit[next]=true;
			
			light[next]++; // 이 노드보다 가벼운놈이 한 놈 더 있다
			dfs(next); // 다음 노드로 재탐색
		}
	}
	
	// 무거움->가벼움 탐색
	public static void rDfs (int node) { // 역방향 DFS
		for(Integer next: rConn[node]) { 
			if( visit[next] ) continue;
			visit[next]=true;

			heavy[next]++; // 이 노드보다 무거운 놈이 더 있다
			rDfs(next); // 다음 노드로 재탐색
		}
	}
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine().trim());

		for(int test_case = 1; test_case <= T; test_case++) {
			int N = Integer.parseInt(br.readLine().trim()); // 항생 수
			int M = Integer.parseInt(br.readLine().trim()); // 비교 횟수
			
			// 리스트 생성
			conn = new List[N+1];
			rConn = new List[N+1];
			for(int k=1; k<=N; k++) conn[k] = new ArrayList<>();
			for(int k=1; k<=N; k++) rConn[k] = new ArrayList<>();

			light = new int[N+1]; // 나보다 가벼운 놈들의 수
			heavy = new int[N+1]; // 나보다 무거운 놈들의 수
			
			for(int k=0; k<M; k++) { // 비교 정보 입력
				String[] AB = br.readLine().split(" ");
				int a = Integer.parseInt(AB[0]);
				int b = Integer.parseInt(AB[1]); // a가 b보다 키가 작다
				conn[a].add(b); // a 뒤에 b가 온다 (연결)
				rConn[b].add(a); // b 앞엔 a가 온다
			}
			
			for(int k=1; k<=N; k++) { // 학생 하나하나 적용
				visit = new boolean[N+1];
				dfs(k); // 나보다 큰 놈들에게 기록
				visit = new boolean[N+1];
				rDfs(k); // 나보다 작은 놈들에게 기록
			}
			
			int ans = 0; // 키를 알 수 있는 학생 수
			for(int k=1; k<=N; k++) {
				// 가벼운놈 + 무거운놈 + 본인 포함해서 인원이 맞는가 확인
				if(light[k]+heavy[k]+1 == N) ans++;
			}
			System.out.println("#"+test_case+" "+ans); // 출력
		}
	}
}