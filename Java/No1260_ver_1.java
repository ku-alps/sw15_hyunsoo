import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

// DFS와 BFS
public class No1260 {
	int nNum, eNum; // 노드수, 엣지수
	LinkedList<Integer>[] edge; // 각 엣지 연결상태 (양방향)
	Queue<Integer> q; // BFS용 큐
	boolean[] visit; // 각 노드의 방문여부
	
	public No1260(int n, int e) {
		this.nNum = n;
		this.eNum = e;
		// 연결상태표기를 위해 배열 객체 초기화
		edge = new LinkedList[this.nNum + 1];
		for(int k=0; k<edge.length; k++) edge[k] = new LinkedList<Integer>();
	}
	
	// 엣지 초기화
	public void insertEdge(int a, int b) {
		edge[a].add(b);
		edge[b].add(a);
	}
	
	// 엣지 정렬 (방문 기준이 오름차순)
	public void sortEdge() {
		for(int k=0; k<edge.length; k++) Collections.sort(edge[k]);
	}
	
	// DFS 함수
	void runDfs(int start) {	
		visit = new boolean[this.nNum+1];
		dfs(start);
		System.out.println();
	}
	void dfs(int pos) {
		if(visit[pos]) return; // 방문여부 체크
		visit[pos] = true;
		System.out.print(pos + " ");
		
		for(int next: edge[pos]) { // 연결된 엣지 탐색
			this.dfs(next);
		}
	}
	
	// BFS 함수
	void runBfs(int start) {
		visit = new boolean[this.nNum + 1];
		q = new LinkedList<Integer>(); // 큐 초기화
		
		// 탐색
		q.add(start);
		while(!q.isEmpty()) {
			// 방문한 곳이면 무시
			int node = q.poll();
			if(visit[node]) continue;

			visit[node] = true;
			System.out.print(node+" ");
			
			for(int next: edge[node]) q.add(next);
		}
		System.out.println();
	}	
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		No1260 p = new No1260(sc.nextInt(), sc.nextInt());

		int start = sc.nextInt();
		for(int k=0; k< p.eNum; k++) p.insertEdge(sc.nextInt(), sc.nextInt());
		
		p.sortEdge();
		
		p.runDfs(start);
		p.runBfs(start);
	}
}
