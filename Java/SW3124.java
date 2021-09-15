import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

// 최소 스패닝 트리
class SW3124 {
	static boolean[] visit;
	static List<Edge>[] list;
	static PriorityQueue<Edge> pq;
	
	static class Edge implements Comparable<Edge>{
		int t, w;
		Edge(int t, int w) {
			this.t = t;
			this.w = w;
		}
		@Override
		public int compareTo(Edge o) {
			// TODO Auto-generated method stub
			return this.w-o.w;
		}
	}
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		pq = new PriorityQueue<>();
		
		for(int test_case = 1; test_case <= T; test_case++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int V = Integer.parseInt(st.nextToken());
			int E = Integer.parseInt(st.nextToken());
			
			visit = new boolean[V+1];
			list = new List[V+1];
			for(int k=1; k<=V; k++) list[k] = new ArrayList<Edge>();

			for(int k=0; k<E; k++) { // 엣지 입력
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				int c = Integer.parseInt(st.nextToken());
				list[a].add(new Edge(b,c));
				list[b].add(new Edge(a,c));
			}
			
			long sum = 0;
			pq.add(new Edge(1,0));
			while(!pq.isEmpty()) {
				Edge edge = pq.poll();
				if(visit[edge.t]) continue; // 방문여부 확인
				visit[edge.t] = true;
				sum += edge.w;
								
				for(Edge next: list[edge.t]) {
					if(visit[next.t]) continue;
					pq.offer(next);
				}
			}
			
			System.out.println("#"+test_case+" "+sum); // 출력
		}
	}
}