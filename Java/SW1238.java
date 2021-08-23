import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

// Contact
class SW1238 {
	static final int N = 100;
	
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		for(int test_case=1; test_case<=10; test_case++) {
			// 입력
			int edgeCnt = sc.nextInt() / 2, start = sc.nextInt(); // 엣지 수, 시작점
			boolean[][] edges = new boolean[N+1][N+1]; // 엣지를 인접 행렬로 만들기
			int[] visit = new int[N+1]; // 방문 여부
			for(int k=0; k<edgeCnt; k++) { // 단방향 엣지 입력
				edges[sc.nextInt()][sc.nextInt()] = true; // 연결되어있음을 표기
			}

			int last = 0; // 정답으로 봅아낼 변수
			
			// BFS 탐색을 진행할 큐
			Queue<Integer> q = new LinkedList<>();
			visit[start] = 1; // 초기세팅 (시작점은 1번째 연락받은 사람)
			q.add(start); // 첫 지점을 삽입
			while(!q.isEmpty()) { // 큐 전부를 돌면서 탐색
				int from = q.poll(); // 다음 대상
				// 연락이 도착한 시점을 먼저 비교하고, 그 외엔 고유번호를 비교
				last = ( visit[last] < visit[from] ? from : (last < from ? from : last));
				
				for(int to=1; to<=N; to++) { // 다른 놈들을 모두 보면서
					// 연결이 안되어있거나, 이미 연락을 받은 놈이면 무시
					if(!edges[from][to] || visit[to] != 0) continue;
					visit[to] = visit[from] + 1; // 다음 타자로 연락을 받았음
					q.add(to); // 삽입
				}
			}
			// 출력
			System.out.println("#"+test_case+" "+last);
		}
	}
}