import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

// DFS와 BFS
class SW1260 {
	static List<Integer>[] EDGES; // 엣저징보
	static boolean[] vDfs, vBfs; // 각각 방문체크에 사용할 배열
	
	// DFS 함수
	static void dfs(int node) {
		if(vDfs[node]) return; // 방문했던 곳이면 무시
		vDfs[node] = true; // 방문 표기
		System.out.print(node+" ");
		
		// 연결된 모든 엣지들 대상으로 탐색
		for(int next: EDGES[node]) dfs(next);
		
	}
	// BFS 함수
	static void bfs(int start) {
		Queue<Integer> q = new LinkedList<Integer>(); // bfs 용 큐
		vBfs[start] = true; // 봤음을 표기
		q.add(start); // 시작지점 삽입
		
		// 순환
		while(!q.isEmpty()) {
			int node = q.poll(); // 이번에 살펴볼 대상
			System.out.print(node + " ");
						
			for(int next: EDGES[node]) { // 연결된 놈들을 하나씩 살펴봄
				if(vBfs[next]) continue; // 방문했으면 무시
				vBfs[next] = true;
				q.add(next); // 뒤쪽으로 삽입
			}
		}
	}
	
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);

		// 노드 수, 엣지 수, 탐색 시작점
		int N = sc.nextInt(), M = sc.nextInt(), V = sc.nextInt();

		EDGES = new List[N+1]; // 노드 수 만큼 엣지정보 리스트 생성 ( 1~N )
		for(int k=1; k<=N; k++) EDGES[k] = new ArrayList<Integer>();
		for(int k=0; k<M; k++) { // 엿지 입력
			int a = sc.nextInt(), b = sc.nextInt(); // 연결할 노드
			EDGES[a].add(b);
			EDGES[b].add(a); // 양방향으로 연결
		}
		for(int k=1; k<=N; k++) Collections.sort(EDGES[k]); // 오름차순 정렬
		
		// DFS 실행
		vDfs = new boolean[N+1];
		dfs(V);

		System.out.println(); // 줄바꿈
		
		// BFS 실행
		vBfs = new boolean[N+1];
		bfs(V);
	}
}