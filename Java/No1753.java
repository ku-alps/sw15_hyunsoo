import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

// 최단경로 
class No1753 {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// 입력
		String[] VE = br.readLine().split(" ");
		int V = Integer.parseInt(VE[0]); // 정점
		int E = Integer.parseInt(VE[1]); // 엣지 수
		int K = Integer.parseInt(br.readLine()); // 출발 위치

		List<Integer[]>[] edges = new List[V+1]; // 엣지 정보를 담을 공간을 확보
		for(int k=1; k<=V; k++) edges[k] = new LinkedList<>();

		for(int k=0; k<E; k++) { // 엣지 입력
			String[] eInput = br.readLine().split(" ");
			int A = Integer.parseInt(eInput[0]);
			int B = Integer.parseInt(eInput[1]); // 연결 노드
			int W = Integer.parseInt(eInput[2]); // 가중치
			edges[A].add(new Integer[] {B, W}); // 엣지 정보 삽입
		}
		int[] distance = new int[V+1]; // 시작점부터 최단거리
		boolean[] include = new boolean[V+1]; // 포함 여부
		Arrays.fill(distance, Integer.MAX_VALUE); // 초기화
		
		distance[K] = 0; // 시작점의 거리는 0
		while(true) { // 모든 노드가 포함될 때 까지 수행
			// 최소거리인 노드 선택
			int next = 0;
			for(int i=1; i<=V; i++) {
				if(include[i]) continue; // 이미 포함된 위치면 무시
				if(distance[i] < distance[next]) next = i; // 더 거리가 짧은 놈을 선택
			}
			if(next == 0) break; // 추가로 포함시킬 놈이 없다면 강제종료

			// 정답으로 포함시키고, 주변 노드의 거리값 갱신
			include[next] = true; // 포함
			for(Integer[] connect : edges[next]) {
				// 주변 거리값 갱신 ( 기존 거리값 vs 이번 노드를 거쳐서 가는 길 )
				int to = connect[0], weight = connect[1];
				distance[to] = Math.min(distance[to], distance[next]+weight);
			}
		}
		
		for(int k=1; k<=V; k++) { // 각 정점의 최단거리 출력
			System.out.println(distance[k] != Integer.MAX_VALUE ? distance[k] : "INF");
		}
	}
}