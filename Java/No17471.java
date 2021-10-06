import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

// 게리맨더링
class No17471 {
	static final int INF = Integer.MAX_VALUE; // 무한대 거리
	
	static int ans=INF; // 정답값
	static int N, total; // 구역 수, 인구수 총 합
	static int[] city; // 각 도시 별 인구 수
	static boolean[][] conn; // 각 도시 별 연결 정보
	static boolean[] state; // 조합 상태에 따른 방문 여부
	
	static void dfs(int cnt, int bit, int sum) {
		// A선거구에 포함된 구역 갯수, A선거구에 포함된 구역정보, A선거구의 인구수 합
		if(cnt == N) return; // 모든 구역을 차지한 경우는 불가능 (무시)
		if(state[bit]) return; // 이미 해봤던 조합도 무시
		state[bit] = true;
		
		if(cnt<N) { // 각 선거구가 최소 하나 이상의 구역을 갖고있다면
			// 조합을 비교
			int calc = Math.abs(total-sum*2);
			if(calc<ans) { // 이번 조합의 격차값이 기존격차보다 작으면
				// B 선거구 구역에 대해서 연결이 잘 되는가를 확인
				Queue<Integer> q = new LinkedList<>(); // BFS 용 큐
				int visit=bit; // 방문 여부 체크값

				int start=1; // bfs 를 시작할 구역 인덱스
				while((visit&(1<<start)) != 0) start++; // B 구역인 곳을 찾음

				q.add(start); // bfs 시작 지점
				while(!q.isEmpty()) { // bfs 진행
					int next = q.poll(); // 값 꺼내오기
					// 이미 방문했던 곳이나, A 구역이 아니라면 무시
					if((visit&(1<<next)) != 0) continue;
					visit |= (1<<next);
					for(int n=1; n<=N; n++) { // 연결 구간을 찾음
						if((visit&(1<<n)) != 0) continue; // 방문여부, 구역여부 체크
						if(!conn[next][n]) continue; // 연결이 안된곳도 무시
						q.add(n); // bfs 확장
					}
				}
				// 탐색이 끝난 상태에서 모든 지역이 자치구에 소속되었는가 확인
				if(visit+1 == (1<<(N+1))) { // 지역번호는 1~N 까지이므로, N+1을 사용
					// B구역들도 연결이 잘 되어있음을 의미
					ans = calc;					
				}
			}
		}
		
		// A 선거구에 연결할 놈들을 늘려봄
		for(int a=1; a<=N; a++) { // A에 포함된 구역에 대해서 연결지점을 하나씩 늘려봄		
			// A 소속이 아니면 무시
			if((bit&(1<<a)) == 0) continue;

			for(int b=1; b<=N; b++) { // 연결된 엣지 확인
				if(!conn[a][b]) continue; // 연결이 안됨
				if((bit&(1<<b)) != 0) continue; // 이미 A에 포함된 곳도 무시
				
				dfs(cnt+1, bit|(1<<b), sum+city[b]); // dfs 재귀
			}
		}
	}
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine()); // 구역의 갯수
		
		city = new int[N+1]; // 각 구역별 인구 수 (1~N)
		conn = new boolean[N+1][N+1]; // 각 구역별 연결 정보
		state= new boolean[1<<(N+1)]; // 조합에 따른 방문 여부
		
		String[] input = br.readLine().split(" ");
		for(int k=0; k<N; k++) { // 입력받기
			city[k+1]=Integer.parseInt(input[k]);
			total += city[k+1]; // 전체 인구수 총 합
		}
		
		// 연결 정보
		for(int k=1; k<=N; k++) {
			String[] data = br.readLine().split(" ");
			int cnt=Integer.parseInt(data[0]); // 연결된 구역 수
			for(int i=1; i<=cnt; i++) conn[k][Integer.parseInt(data[i])]=true;
		}
		
		// 각 지역을 출발점으로 조합을 하나씩 만들어봄
		for(int k=1; k<=N; k++) dfs(1,1|(1<<k),city[k]);
		System.out.println(ans!=INF ? ans : -1); // 상태값에 따라 출력
	}
}